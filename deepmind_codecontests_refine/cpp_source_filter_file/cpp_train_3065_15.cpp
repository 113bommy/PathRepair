#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int f[305], a[N], b[N], n, m, s, e, C, ans;
vector<int> p[N];
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &e), C = s / e;
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  for (int i = 0; i < m; ++i) scanf("%d", b + i), p[b[i]].push_back(i);
  for (int j = 0; j < C + 1; ++j) f[j] = m;
  f[0] = -1;
  for (int i = 0; i < n + 1; ++i)
    for (int j = C; j >= 0; --j)
      if (f[j] < m) {
        if (i + f[j] + 2 + j * e <= s) ans = max(ans, j);
        vector<int>::iterator it =
            upper_bound(p[a[i]].begin(), p[a[i]].end(), f[j]);
        if (it != p[a[i]].end()) f[j + 1] = min(f[j + 1], *it);
      }
  printf("%d\n", ans);
  return 0;
}
