#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100000 + 10;
int n, m, f, s;
long long id[MaxN << 1];
void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &s, &f);
    id[i] = (s + 1) * n - f;
    id[i + m] = id[i] + (long long)n * 2LL;
  }
}
void solve() {
  sort(id + 1, id + m * 2 + 1);
  long long ans =
      ((long long)m * (long long)(m - 1) * (long long)(m - 2)) / 6LL;
  int p = 1, q, sm, v;
  for (int i = 1; i <= m; ++i) {
    q = id[i] + n;
    while (p < m * 2 && id[p + 1] < q) ++p;
    sm = p - i;
    ans -= (long long)sm * (long long)(sm - 1) / 2LL;
  }
  if (!ans) {
    p = 1;
    q = 0;
    int p2 = 1;
    for (int i = 1; i <= m; ++i) {
      while (p < m * 2 && id[p + 1] < id[i] + n) ++p;
      while (p2 < p && (p2 < i || id[p2 + 1] != id[p])) ++p2;
      if (p - i < 2) continue;
      v = id[p] - id[i];
      if (v > q) q = v, ans = 0;
      if (v == q) {
        v = p - i;
        ans += ((long long)v * (long long)(v - 1)) / 2LL;
        v = p2 - i;
        ans -= ((long long)v * (long long)(v - 1)) / 2LL;
      }
    }
  }
  cout << ans << endl;
}
int main() {
  init();
  solve();
  return 0;
}
