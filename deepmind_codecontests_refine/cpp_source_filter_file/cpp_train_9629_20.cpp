#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + c - 48;
    c = getchar();
  }
  return x * f;
}
int to[maxn], net[maxn], h[maxn], e = 1;
void add(int x, int y) {
  to[++e] = y;
  net[e] = h[x];
  h[x] = e;
}
int k, m, n;
int val[maxn], fa[maxn], dep[maxn], siz[maxn], son[maxn];
int L[maxn], R[maxn], all[maxn], tot = 0;
char c[maxn];
vector<pair<int, int> > Q[maxn];
void dfs(int x) {
  dep[x] = dep[fa[x]] + 1;
  L[x] = ++tot;
  all[tot] = c[x] - 'a';
  siz[x] = 1;
  for (int i = h[x]; i; i = net[i]) {
    int y = to[i];
    dfs(y);
    siz[x] += siz[y];
    if (siz[son[x]] < siz[y]) son[x] = y;
  }
  R[x] = tot;
  return;
}
int num[maxn][26], sum[maxn], ans[maxn];
void solve(int x, int op) {
  for (int i = h[x]; i; i = net[i]) {
    int y = to[i];
    if (y == son[x]) continue;
    solve(y, 0);
  }
  if (son[x]) solve(son[x], 1);
  for (int i = h[x]; i; i = net[i]) {
    int y = to[i];
    if (y == son[x]) continue;
    for (int j = L[y]; j <= R[y]; j++) {
      int now = all[j];
      sum[dep[now]] -= num[dep[now]][c[now] - 'a'];
      num[dep[now]][c[now] - 'a'] ^= 1;
      sum[dep[now]] += num[dep[now]][c[now] - 'a'];
    }
  }
  int len = Q[x].size();
  sum[dep[x]] -= num[dep[x]][c[x] - 'a'];
  num[dep[x]][c[x] - 'a'] ^= 1;
  sum[dep[x]] += num[dep[x]][c[x] - 'a'];
  for (int i = 0; i < len; i++) {
    ans[Q[x][i].second] = sum[Q[x][i].first] <= 1 ? 1 : 0;
  }
  if (op) return;
  for (int i = L[x]; i <= R[x]; i++) {
    int now = all[i];
    sum[dep[now]] -= num[dep[now]][c[now] - 'a'];
    num[dep[now]][c[now] - 'a'] ^= 1;
    sum[dep[now]] += num[dep[now]][c[now] - 'a'];
  }
}
int main() {
  n = read();
  m = read();
  for (int i = 2; i <= n; i++) fa[i] = read(), add(fa[i], i);
  dfs(1);
  scanf("%s", c + 1);
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    Q[x].push_back(make_pair(y, i));
  }
  solve(1, 1);
  for (int i = 1; i <= m; i++) {
    if (ans[i] == 1)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
