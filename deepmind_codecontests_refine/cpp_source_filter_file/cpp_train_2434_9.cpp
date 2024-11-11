#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30) - 1;
const long double EPS = 1e-9;
const long double PI = fabs(atan2(0.0, -1.0));
int n, q;
int a[200010];
int cnt[200010];
void load() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0, l, r; i < q; i++) {
    scanf("%d%d", &l, &r);
    --l;
    cnt[l]++;
    cnt[r]--;
  }
}
bool cmp(int a, int b) { return cnt[a] > cnt[b]; }
void solve() {
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cur += cnt[i];
    cnt[i] = cur;
  }
  vector<int> order(n);
  for (int i = 0; i < n; i++) order.push_back(i);
  sort(order.begin(), order.end(), cmp);
  sort(a + 0, a + n);
  reverse(a + 0, a + n);
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += a[i] * 1LL * cnt[order[i]];
  cout << sum << "\n";
}
int main() {
  load();
  solve();
  return 0;
}
