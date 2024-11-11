#include <bits/stdc++.h>
const int N = 1e7 + 10;
const unsigned long long base = 163;
const int INF = 0x3f3f3f3f;
using namespace std;
int a[N];
pair<int, int> b[N];
int c[N];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    c[a[i]]++;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i].first), b[i].second = i;
  }
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  int tot = 0;
  int o = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= tot) {
      o++;
    } else
      return cout << -1, 0;
    if (o == k) o = 0, tot++;
  }
  int ans = 0;
  vector<int> q;
  int r = 1;
  for (int i = 0; i <= (int)1e7; i++) {
    if (c[i] < k && c[i]) {
      while (b[r].first < i) r++;
      while (r <= m && c[i] < k && b[r].first >= i) {
        q.push_back(b[r].second);
        r++;
        c[i]++;
        ans++;
      }
    }
  }
  cout << ans << endl;
  for (auto i : q) cout << i << " ";
  return 0;
}
