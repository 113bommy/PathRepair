#include <bits/stdc++.h>
using namespace std;
const long double pi = acosl(-1.0);
const int MAXN = 1001;
void solve() {
  int n, m, u, v;
  scanf("%d%d", &n, &m);
  vector<int> a(n);
  vector<pair<int, int>> p(m);
  vector<int> ac(n, 0);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < m; ++i)
    scanf("%d%d", &u, &v), p[i] = make_pair(u - 1, v - 1);
  vector<int> pref(n);
  pref[0] == a[0];
  for (int i = 1; i < n; ++i) pref[i] = pref[i - 1] + a[i];
  for (auto c : p) {
    int kkk = 0;
    if (c.first != 0) {
      if (c.first == c.second)
        kkk = a[c.first];
      else
        kkk = pref[c.second] - pref[c.first - 1];
    } else
      kkk = pref[c.second];
    if (kkk > 0)
      for (int i = c.first; i <= c.second; ++i) {
        ++ac[i];
      }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i] * ac[i];
  }
  printf("%d\n", ans);
}
int main() {
  solve();
  return 0;
}
