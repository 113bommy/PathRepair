#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, p, x, y, f[2][210][501][2], a[2][210], le[2];
int Ans, l, r, q[210];
int L, fa[210], v[210], ch[210][20], Num;
bool b;
inline void Add(int& x, int y) { x = (x + y) % 1000000007; }
inline void Get_fail() {
  l = r = 0;
  for (int i = 0; i < m; i++)
    if (ch[0][i]) q[++r] = ch[0][i];
  while (++l <= r) {
    x = q[l];
    for (int i = 0; i < m; i++)
      if (!ch[x][i])
        ch[x][i] = ch[fa[x]][i];
      else
        fa[ch[x][i]] = ch[fa[x]][i], v[ch[x][i]] += v[ch[fa[x]][i]],
        q[++r] = ch[x][i];
  }
}
inline int Solve(int d) {
  b = 0;
  memset(f[1], 0, sizeof(f[1]));
  for (int i = 1; i <= le[d]; i++, b ^= 1) {
    memset(f[b], 0, sizeof(f[b]));
    for (int q = 1; q < m && (i > 1 || q <= a[d][1]); q++)
      Add(f[b][ch[0][q]][v[ch[0][q]]][(i == 1 && q == a[d][1])], 1);
    for (int j = 0; j <= Num; j++)
      for (int l = 0; l <= k; l++)
        for (int p = 0; p < 2; p++)
          if (f[b ^ 1][j][l][p])
            for (int q = 0; q < m && (!p || q <= a[d][i]); q++) {
              int j1 = ch[j][q];
              int l1 = v[j1] + l;
              if (l1 > k) continue;
              Add(f[b][j1][l1][(p && q == a[d][i])], f[b ^ 1][j][l][p]);
            }
  }
  b ^= 1;
  int Ans = 0;
  for (int i = 0; i <= Num; i++)
    for (int j = 0; j <= k; j++)
      for (int p = 0; p < 2; p++) Add(Ans, f[b][i][j][p]);
  return Ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i >= 0; i--) {
    scanf("%d", &le[i]);
    for (j = 1; j <= le[i]; j++) scanf("%d", &a[i][j]);
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &L);
    p = 0;
    while (L--) {
      scanf("%d", &x);
      if (!ch[p][x]) ch[p][x] = ++Num;
      p = ch[p][x];
    }
    scanf("%d", &x);
    v[p] += x;
  }
  Get_fail();
  Ans = Solve(0);
  if (le[1] > 1 || a[1][1] > 1) {
    a[1][le[1]]--;
    for (i = le[1]; a[1][i] < 0; i--) a[1][i] += m, a[1][i - 1]--;
    for (i = 1; !a[1][i]; i++)
      ;
    if (i > 1)
      for (j = 1; j <= le[1] - i + 1; j++) a[1][j] = a[1][j + i - 1];
    le[1] -= i - 1;
    Add(Ans, -Solve(1));
  }
  cout << (Ans + 1000000007) % 1000000007 << endl;
  return 0;
}
