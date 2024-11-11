#include <bits/stdc++.h>
using namespace std;
int n, k, linkk[401000], t;
int son[401000], f[401000], road[401000], fat[401000], Max[401000];
int id2[401000], mx2[401000], id1[401000], mx1[401000];
int sum[401000];
int ans[401000];
bool flag;
struct node {
  int n, y;
} e[801000];
int read() {
  int sum = 0;
  ;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') sum = sum * 10 + c - 48, c = getchar();
  return sum;
}
void dfs(int x, int fa) {
  for (int i = linkk[x]; i; i = e[i].n)
    if (e[i].y != fa) {
      int y = e[i].y;
      dfs(y, x);
      son[x] += son[y];
      if (son[y] > n / 2)
        sum[x]++;
      else if (son[y] > Max[x])
        Max[x] = son[y];
      if (son[y] > f[x]) f[x] = son[y], road[x] = y;
      Max[x] = max(Max[x], Max[y]);
    }
  son[x]++;
  fat[x] = fa;
  if (n - son[x] > n / 2) sum[x]++;
  if (n - son[x] > f[x]) f[x] = n - son[x], road[x] = fa;
  if (son[x] <= n / 2) Max[x] = max(Max[x], son[x]);
  return;
}
void insert(int x, int y) {
  e[++t].y = y;
  e[t].n = linkk[x];
  linkk[x] = t;
  e[++t].y = x;
  e[t].n = linkk[y];
  linkk[y] = t;
  return;
}
void init() {
  n = read();
  for (int i = 1; i < n; ++i) {
    int x = read(), y = read();
    insert(x, y);
  }
  return;
}
void dfs2(int x, int fa, int sf, int mf) {
  mx1[x] = mx2[x] = -1;
  for (int i = linkk[x]; i; i = e[i].n) {
    int y = e[i].y;
    if (y == fa) continue;
    if (mx1[x] < Max[y]) {
      mx2[x] = mx1[x];
      id2[x] = id1[x];
      mx1[x] = Max[y];
      id1[x] = y;
    } else if (mx2[x] < Max[y]) {
      mx2[x] = Max[y];
      id2[x] = y;
    }
  }
  for (int i = linkk[x]; i; i = e[i].n) {
    int y = e[i].y;
    if (y == fa) continue;
    int fa_1 = 0, fa_2;
    if (n - son[y] <= n / 2) fa_1 = n - son[y];
    if (id1[x] == y)
      fa_2 = mx2[x];
    else
      fa_2 = mx1[x];
    fa_2 = max(fa_2, mf);
    dfs2(y, x, son[x] - son[y] + sf, max(fa_1, fa_2));
  }
  if (mx1[x] < mf) {
    mx2[x] = mx1[x];
    id2[x] = id1[x];
    mx1[x] = mf;
    id1[x] = fa;
  } else if (mx2[x] < mf) {
    mx2[x] = mf;
    id2[x] = fa;
  }
  return;
}
void solve() {
  for (int i = 1; i <= n; ++i) {
    if (sum[i] > 1) printf("0 ");
    if (sum[i] == 0) printf("1 ");
    if (sum[i] == 1) {
      int ans;
      if (road[i] != fat[i])
        ans = (son[road[i]] - Max[road[i]] <= n / 2);
      else {
        if (i == id1[road[i]])
          ans = (n - son[i] - mx2[road[i]] <= n / 2);
        else
          ans = (n - son[i] - mx1[road[i]] <= n / 2);
      }
      printf("%d ", ans);
    }
  }
  return;
}
int main() {
  init();
  dfs(1, 0);
  dfs2(1, 0, 0, 0);
  solve();
  return 0;
}
