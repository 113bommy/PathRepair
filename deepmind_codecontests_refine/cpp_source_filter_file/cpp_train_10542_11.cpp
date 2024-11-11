#include <bits/stdc++.h>
using namespace std;
const int maxn = 555;
int n, m;
pair<int, int> a[maxn], b[maxn];
int f[maxn][maxn];
void operator-=(pair<int, int> &a, pair<int, int> o) {
  a.first -= o.first;
  a.second -= o.second;
}
bool ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  b -= a;
  c -= a;
  return 1ll * b.first * c.second > 1ll * b.second * c.first;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1), _b = (n); i <= _b; ++i)
    scanf("%d%d", &a[i].first, &a[i].second);
  for (int i = (1), _b = (m); i <= _b; ++i)
    scanf("%d%d", &b[i].first, &b[i].second);
  for (int i = (1), _b = (n); i <= _b; ++i)
    for (int j = (1), _b = (n); j <= _b; ++j)
      if (a[i].first < a[j].first) {
        for (int k = (1), _b = (m); k <= _b; ++k)
          f[i][j] += b[k].first >= a[i].first && b[k].first <= a[j].first &&
                     ccw(a[i], a[j], b[k]);
        f[j][i] = -f[i][j];
      }
  int ans = 0;
  for (int i = (1), _b = (n); i <= _b; ++i)
    for (int j = (i + 1), _b = (n); j <= _b; ++j)
      for (int k = (j + 1), _b = (n); k <= _b; ++k)
        ans += f[i][j] + f[j][k] + f[k][i] == 0;
  printf("%d", ans);
  return 0;
}
