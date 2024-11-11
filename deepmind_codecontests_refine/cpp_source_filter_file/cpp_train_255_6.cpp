#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int N = 20;
const int E = 1 << 20;
int n, m, a[N][N], c[N][N], maxst;
int t[E], an, lb[N], f[E];
vector<int> to[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      char c;
      c = getchar();
      while (c < 'a' || c > 'z') c = getchar();
      a[i][j] = c - 'a';
    }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) scanf("%d", &c[i][j]);
  maxst = 1 << n;
  for (int i = 0; i < maxst; ++i) t[i] = inf;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 26; ++j) {
      int sum = 0, mx = 0, st = 0;
      for (int k = 0; k < n; ++k)
        if (a[k][i] == j) {
          sum += c[k][i];
          mx = max(mx, c[k][i]);
          st |= 1 << k;
        }
      sum -= mx;
      t[st] = min(t[st], sum);
    }
  }
  for (int i = 0; i < n; ++i) {
    int st = 1 << i;
    for (int j = 0; j < m; ++j) t[st] = min(t[st], c[i][j]);
  }
  an = 0;
  for (int i = 0; i < maxst; ++i)
    if (t[i] != inf)
      for (int j = 0; j < n; ++j)
        if ((i >> j) & 1) to[j].push_back(i);
  for (int i = 0; i < maxst; ++i)
    for (int j = 0; j < n; ++j)
      if (((i >> j) & 1) == 0) {
        lb[i] = j;
        break;
      }
  for (int i = 1; i < maxst; ++i) f[i] = inf;
  f[0] = 0;
  for (int i = 0, ub = maxst - 1; i < ub; ++i)
    for (int j = 0, ub1 = to[lb[i]].size(); j < ub1; ++j) {
      int st = to[lb[i]][j];
      f[i | st] = min(f[i | st], f[i] + t[st]);
    }
  printf("%d\n", f[maxst - 1]);
  return 0;
}
