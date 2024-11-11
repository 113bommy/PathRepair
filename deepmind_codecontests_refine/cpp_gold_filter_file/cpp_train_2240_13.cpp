#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
long long fen[2][maxn];
pair<int, int> a[maxn];
void add(int type, int idx, int val) {
  for (; idx < maxn; idx += idx & -idx) fen[type][idx] += val;
}
long long get(int type, int idx) {
  long long ret = 0;
  for (; idx > 0; idx -= idx & -idx) ret += fen[type][idx];
  return ret;
}
bool cmp(pair<int, int> b, pair<int, int> c) {
  if (b.second < c.second) return true;
  return false;
}
int main() {
  long long ans = 0;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  a[1].first = 1;
  add(1, 1, 1);
  for (int i = 2; i <= n; i++) {
    if (a[i].first == a[i - 1].first)
      a[i].first = a[i - 1].first;
    else
      a[i].first = a[i - 1].first + 1;
    add(1, a[i].first, 1);
  }
  sort(a + 1, a + n + 1, cmp);
  add(1, a[1].first, -1);
  add(0, a[1].first, 1);
  for (int i = 2; i < n; i++) {
    ans += get(1, a[i].first - 1) * (get(0, maxn - 1) - get(0, a[i].first));
    add(1, a[i].first, -1);
    add(0, a[i].first, 1);
  }
  cout << ans << endl;
  return 0;
}
