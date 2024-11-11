#include <bits/stdc++.h>
using namespace std;
struct ww {
  int x, y, z;
  inline ww operator-(const ww &A) { return (ww){x - A.x, y - A.y}; }
} v[310 * 310 * 2], O;
int i, j, k, n, m, t, qi, l;
int a[310][310], b[310][310], c[310 * 310 * 2], f[310 * 310 * 2],
    g[310 * 310 * 2];
vector<ww> d[310 * 310 * 2], dui;
long long an;
inline bool cc1(const ww &a, const ww &b) { return a.z < b.z; }
int get(int x) { return f[x] == x ? x : f[x] = get(f[x]); }
inline int gets(ww A) {
  swap(A.x, A.y);
  A.y *= -1;
  int l = max(abs(A.x), abs(A.y));
  if (!l) return 1;
  int w = (l - 1) * 2 + 1, an = w * w;
  if (A.y == l && A.x > -l) return an + A.x - (-l);
  an += l - 1;
  if (A.x == l && A.y < l) return an + l - A.y;
  an += l - 1;
  if (A.y == -l && A.x < l) return an + l - A.x;
  an += l - 1;
  return an + A.y - (-l);
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      c[++t] = a[i][j];
    }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      scanf("%d", &b[i][j]);
      c[++t] = b[i][j];
    }
  sort(c + 1, c + t + 1);
  {
    scanf("%d%d", &O.x, &O.y);
    dui.push_back(O);
  }
  for (i = 1; i <= t; i++) f[i] = i;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      a[i][j] = lower_bound(c + 1, c + t + 1, a[i][j]) - c;
      b[i][j] = lower_bound(c + 1, c + t + 1, b[i][j]) - c;
      if (c[b[i][j]] >= 0 && c[a[i][j]] > 0 && (i != O.x || j != O.y))
        d[a[i][j]].push_back((ww){i, j});
      g[a[i][j]]++;
    }
  for (l = 0; l < dui.size(); l++) {
    ww A = dui[l];
    int co = a[A.x][A.y], col = b[A.x][A.y], w = get(co);
    if (c[w] == 0 || w == col) continue;
    an += g[w];
    int nn = d[w].size();
    for (j = 0; j < nn; j++) {
      v[j] = d[w][j];
      v[j].z = gets(v[j] - A);
    }
    sort(v, v + nn, cc1);
    for (j = 0; j < nn; j++) dui.push_back(v[j]);
    d[w].clear();
    g[col] += g[w];
    g[w] = 0;
    if (get(w) != get(col)) f[get(w)] = col;
    f[get(col)] = col;
    f[col] = col;
  }
  printf("%I64d\n", an);
  return 0;
}
