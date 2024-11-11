#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void R(T &xx) {
  xx = 0;
  char ch = getchar();
  bool F = 0;
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') F = 1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    xx = xx + xx + (xx << 3) + ch - 48, ch = getchar();
  if (F) xx = -xx;
}
template <class T>
inline void add(int &x, T y) {
  for (x += y; x >= 51123987; x -= 51123987)
    ;
}
vector<int> ans[4011], g[4011];
pair<int, int> a[4011];
int n, m, hs[4011], f[4011], bel[4011], p[4011], id[4011];
inline bool cmp(int A, int B) { return a[A] < a[B]; }
int main() {
  R(n);
  int x, y;
  for (int i = 1; i <= n; i++)
    R(x), R(y), a[i] = make_pair(x + y, x - y), hs[i] = x + y,
                hs[i + n] = x - y;
  sort(hs + 1, hs + n + n + 1);
  int ht = unique(hs + 1, hs + n + n + 1) - (hs + 1);
  for (int i = 1; i <= n; i++)
    a[i].first = lower_bound(hs + 1, hs + ht + 1, a[i].first) - hs,
    a[i].second = -(lower_bound(hs + 1, hs + ht + 1, a[i].second) - hs);
  n++;
  a[n] = make_pair(n - 1 << 1, 0);
  for (int i = 1; i <= n; i++) id[i] = i;
  sort(id + 1, id + n + 1);
  for (int _ = 1; _ <= n; _++) {
    int i = id[_];
    memset(f, -1, sizeof(f));
    swap(a[i].first, a[i].second);
    a[i].first *= -1;
    f[a[i].first] = bel[a[i].first] = 0;
    for (int j = a[i].first + 1; j <= a[i].second; j++) {
      f[j] = f[j - 1];
      bel[j] = bel[j - 1];
      for (int k = 0; k < (int)((int)g[j].size()); k++) {
        int x = g[j][k];
        if (a[x].first < a[i].first) continue;
        if (f[a[x].first] + p[x] > f[j])
          f[j] = f[a[x].first] + p[x], bel[j] = x;
      }
    }
    p[i] = f[a[i].second] + 1;
    for (int k = a[i].second, x = bel[k]; x; x = bel[k]) {
      for (int j = 0; j < (int)((int)ans[x].size()); j++)
        ans[i].push_back(ans[x][j]);
      k = a[x].first;
    }
    ans[i].push_back(i);
    g[a[i].second].push_back(i);
  }
  sort(ans[n].begin(), ans[n].end());
  printf("%d\n", p[n] - 1);
  for (int i = 0; i < (int)((int)ans[n].size()) - 1; i++)
    printf("%d ", ans[n][i]);
  return 0;
}
