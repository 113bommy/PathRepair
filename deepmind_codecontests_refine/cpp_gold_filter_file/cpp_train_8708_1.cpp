#include <bits/stdc++.h>
using namespace std;
int n, m, L, R, t[1010], c[1010], q[1010];
vector<int> a[1010], w[1010];
long long d[1010];
int he[1010], ad[1010 * 1010], ne[1010 * 1010], di[1010 * 1010], _;
bool v[1010];
int main() {
  scanf("%d%d%d%d", &n, &m, &L, &R);
  for (int i = 1, x, y, z; i <= m; i++)
    scanf("%d%d%d", &x, &y, &z), a[x].push_back(y), w[x].push_back(z),
        a[y].push_back(x), w[y].push_back(z);
  for (int i = 1, x, y, z; i <= n; i++) scanf("%d%d", t + i, c + i);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) d[j] = 1000000000000000000LL, v[j] = 0;
    int l = 0, r = 0, C = 1;
    q[0] = i, v[i] = 1;
    d[i] = 0;
    while (C) {
      int x = q[l];
      C--;
      v[x] = 0;
      for (int i = 0; i < (int)a[x].size(); i++) {
        if (d[x] + w[x][i] < d[a[x][i]]) {
          d[a[x][i]] = d[x] + w[x][i];
          if (!v[a[x][i]]) {
            r++;
            C++;
            if (r == 1010) r = 0;
            v[q[r] = a[x][i]] = 1;
          }
        }
      }
      l++;
      if (l == 1010) l = 0;
    }
    for (int j = 1; j <= n; j++)
      if (i != j && d[j] <= t[i])
        _++, ne[_] = he[i], he[i] = _, ad[_] = j, di[_] = c[i];
  }
  for (int i = 1; i <= n; i++) d[i] = 1000000000000000000LL, v[i] = 0;
  int l = 0, r = 0, C = 1;
  q[0] = L;
  v[L] = 1;
  d[L] = 0;
  while (C) {
    int x = q[l];
    C--;
    v[x] = 0;
    for (int p = he[x]; p; p = ne[p])
      if (d[x] + di[p] < d[ad[p]]) {
        d[ad[p]] = d[x] + di[p];
        if (!v[ad[p]]) {
          C++;
          r++;
          if (r == 1010) r = 0;
          v[q[r] = ad[p]] = 1;
        }
      }
    l++;
    if (l == 1010) l = 0;
  }
  if (d[R] == 1000000000000000000LL)
    puts("-1");
  else
    printf("%I64d\n", d[R]);
  return 0;
}
