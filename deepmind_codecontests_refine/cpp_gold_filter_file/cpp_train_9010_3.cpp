#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, B, ans;
int co[N], sx[N], sy[N];
int mp[N][N], id[N], fl[N];
int mat[N], to[N];
bool vis[N], Mat[N];
bool dfs(int x) {
  for (int i = (int)(1); i <= (int)(n + m); i++)
    if (mp[x][i] && !vis[i]) {
      vis[i] = 1;
      if (!mat[i] || dfs(mat[i])) return mat[i] = x, to[x] = i, 1;
    }
  return 0;
}
struct node {
  int x, y, st, T;
} Ans[5000005];
int ans_top;
const int OUT_BUF = 100000000;
char out[OUT_BUF];
int out_top;
void write(int x) {
  if (!x) {
    out[out_top++] = '0';
    return;
  }
  static int a[15], top;
  for (top = 0; x; a[++top] = x % 10, x /= 10)
    ;
  for (; top; out[out_top++] = a[top--] + '0')
    ;
}
void writespace(int x) {
  write(x);
  out[out_top++] = ' ';
}
void writeln(int x) {
  write(x);
  out[out_top++] = '\n';
}
int main() {
  scanf("%d%d%d", &n, &m, &B);
  for (int i = (int)(1); i <= (int)(m); i++) scanf("%d", &co[i]);
  for (int i = (int)(1); i <= (int)(m); i++) id[i] = i;
  for (int i = (int)(1); i <= (int)(n); i++) {
    int cnt, x, y;
    scanf("%d", &cnt);
    while (cnt--) {
      scanf("%d%d", &x, &y);
      mp[i][x] = y;
      sx[i] += y;
      sy[x] += y;
    }
  }
  for (int i = (int)(1); i <= (int)(m); i++)
    for (int j = (int)(i + 1); j <= (int)(m); j++)
      if (sy[id[i]] > sy[id[j]]) swap(id[i], id[j]);
  int p = m;
  for (; p && B >= co[id[p]]; B -= co[id[p]], --p)
    ;
  for (int i = (int)(1); i <= (int)(n); i++) ans = max(ans, sx[i]);
  for (int i = (int)(1); i <= (int)(p); i++) ans = max(ans, sy[id[i]]);
  for (int i = (int)(p + 1); i <= (int)(m); i++)
    ans = max(ans, (sy[id[i]] + 1) / 2);
  for (int i = (int)(p + 1); i <= (int)(m); i++) {
    sy[id[i]] = 0;
    fl[id[i]] = 1;
    for (int j = (int)(1); j <= (int)(n); j++) {
      int x = id[i], y = x + m, v = mp[j][x];
      mp[j][x] = mp[j][y] = v / 2;
      if (v & 1) mp[j][sy[x] < sy[y] ? x : y]++;
      sy[x] += mp[j][x];
      sy[y] += mp[j][y];
    }
  }
  writeln(ans);
  for (int i = (int)(1); i <= (int)(m); i++) write(fl[i]);
  out[out_top++] = '\n';
  m *= 2;
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(n); j++) {
      mp[i][j + m] = ans - max(sx[i], sy[j + m]);
      sx[i] += mp[i][j + m];
      sy[j + m] += mp[i][j + m];
    }
  for (int i = (int)(1); i <= (int)(m); i++)
    for (int j = (int)(1); j <= (int)(m); j++) {
      mp[i + n][j] = ans - max(sx[i + n], sy[j]);
      sx[i + n] += mp[i + n][j];
      sy[j] += mp[i + n][j];
    }
  for (int i = (int)(1); i <= (int)(m); i++)
    for (int j = (int)(1); j <= (int)(n); j++) {
      mp[i + n][j + m] = ans - max(sx[i + n], sy[j + m]);
      sx[i + n] += mp[i + n][j + m];
      sy[j + m] += mp[i + n][j + m];
    }
  for (int i = (int)(1); i <= (int)(n + m); i++) Mat[i] = 1;
  for (int T = 0; T < ans;) {
    for (int i = (int)(1); i <= (int)(n + m); i++)
      if (Mat[i]) {
        memset(vis, 0, sizeof(vis));
        dfs(i);
        Mat[i] = 0;
      }
    int mn = 1e9;
    for (int i = (int)(1); i <= (int)(n + m); i++)
      if (to[i]) mn = min(mn, mp[i][to[i]]);
    for (int i = (int)(1); i <= (int)(n + m); i++)
      if (to[i]) {
        if (i <= n && to[i] <= m) Ans[++ans_top] = (node){i, to[i], T, mn};
        if (!(mp[i][to[i]] -= mn)) Mat[i] = 1, mat[to[i]] = 0;
      }
    T += mn;
  }
  writeln(ans_top);
  for (int i = (int)(1); i <= (int)(ans_top); i++) {
    writespace(Ans[i].x);
    writespace((Ans[i].y - 1) % (m / 2) + 1);
    writespace(Ans[i].st);
    writeln(Ans[i].T);
  }
  fwrite(out, 1, out_top, stdout);
}
