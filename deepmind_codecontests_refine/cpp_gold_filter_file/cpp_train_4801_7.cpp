#include <bits/stdc++.h>
using namespace std;
int ff[2000000], fcol[2000000], ls[2000000];
long long gg[2000000], ans;
int len, N, M, l, r, ll, x, y, s, k, tt, pt, col;
int f[800][800], a[800][800], b[800][800];
int fx[4] = {-1, 0, 1, 0};
int fy[4] = {0, 1, 0, -1};
int ne[2000000], st[2000000], go[2000000][2];
int q[2000000][2];
class rec {
 public:
  int x, y;
} t[2000000];
int findset(int x) {
  if (ff[x] == x) return x;
  ff[x] = findset(ff[x]);
  return ff[x];
}
int find(int x) {
  int l = 0;
  int r = len;
  for (; l < r;) {
    int mid = (l + r + 1) / 2;
    if (ls[mid] > x)
      r = mid - 1;
    else
      l = mid;
  }
  return l;
}
bool cmp(rec a, rec b) {
  return f[ll + a.x - x][ll + a.y - y] < f[ll + b.x - x][ll + b.y - y];
}
int main() {
  scanf("%d%d", &N, &M);
  l = max(N, M) * 2 - 1;
  ll = max(N, M);
  x = ll;
  y = ll;
  f[x][y] = s++;
  k = 1;
  tt = 0;
  for (int i = 1; i < l * l; i++) {
    x = x + fx[tt];
    y = y + fy[tt];
    if ((!x) || (!y) || (x > l) || (y > l) ||
        max(abs(x - ll), abs(y - ll)) > k) {
      x = x - fx[tt];
      y = y - fy[tt];
      if (tt == 3) k++;
      tt = (tt + 1) % 4;
      x = x + fx[tt];
      y = y + fy[tt];
    }
    f[x][y] = s++;
  }
  ls[len++] = 0;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      scanf("%d", &x);
      a[i][j] = x;
      ls[len++] = x;
    }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      scanf("%d", &x);
      b[i][j] = x;
      if (x >= 0) ls[len++] = x;
    }
  sort(ls, ls + len);
  len--;
  x = 0;
  for (int i = 1; i <= len; i++)
    if (ls[i] != ls[x]) ls[++x] = ls[i];
  len = x;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      a[i][j] = find(a[i][j]);
      gg[a[i][j]]++;
    }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      if (b[i][j] >= 0) {
        b[i][j] = find(b[i][j]);
        x = a[i][j];
        ne[++pt] = st[x];
        st[x] = pt;
        go[pt][0] = i;
        go[pt][1] = j;
      }
  scanf("%d%d", &x, &y);
  l = r = 0;
  ans = 0;
  q[l][0] = x;
  q[l][1] = y;
  for (int i = 1; i <= len; i++) ff[i] = i, fcol[i] = i;
  for (; l <= r; l++) {
    x = q[l][0];
    y = q[l][1];
    col = fcol[findset(a[x][y])];
    if (col == 0) continue;
    if (col == b[x][y]) continue;
    ans += gg[findset(a[x][y])];
    len = 0;
    if (st[col])
      for (int i = st[col]; i; i = ne[i]) {
        t[++len].x = go[i][0];
        t[len].y = go[i][1];
      }
    st[col] = 0;
    sort(t + 1, t + len + 1, cmp);
    for (int i = 1; i <= len; i++)
      if (t[i].x != x || t[i].y != y) q[++r][0] = t[i].x, q[r][1] = t[i].y;
    col = findset(a[x][y]);
    if (findset(b[x][y]) != findset(a[x][y])) {
      ff[col] = b[x][y];
      gg[ff[col]] += gg[col];
      gg[col] = 0;
    } else {
      fcol[col] = b[x][y];
    }
  }
  printf("%I64d", ans);
}
