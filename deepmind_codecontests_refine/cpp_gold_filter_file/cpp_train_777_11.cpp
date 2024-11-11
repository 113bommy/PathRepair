#include <bits/stdc++.h>
int inp() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum;
}
int head[200010], nxt[400010], end[400010], size[200010];
double w[200010], value[400010];
int cou = 0;
void link(int a, int b, int v) {
  nxt[++cou] = head[a];
  head[a] = cou;
  end[cou] = b;
  value[cou] = v;
}
double sum, _f, f[200010];
void _dfs(int cur, int last, double dis) {
  sum += pow(dis, 1.5) * w[cur];
  _f += 1.5 * pow(dis, 0.5) * w[cur];
  for (int x = head[cur]; x != -1; x = nxt[x])
    if (end[x] != last) _dfs(end[x], cur, dis + value[x]);
}
bool used[200010];
int tot, root, min;
void dfs0(int cur, int last) {
  size[cur] = 1;
  int max = 0;
  for (int x = head[cur]; x != -1; x = nxt[x]) {
    if (end[x] != last && !used[end[x]]) {
      dfs0(end[x], cur);
      max = std::max(max, size[end[x]]);
      size[cur] += size[end[x]];
    }
  }
  max = std::max(max, tot - size[cur]);
  if (max < min) {
    min = max;
    root = cur;
  }
}
int rt;
double ans = 1e22;
int dfs(int cur) {
  dfs0(cur, 0);
  tot = size[cur];
  min = 2147483647;
  dfs0(cur, 0);
  cur = root;
  used[cur] = true;
  double fsum = 0;
  sum = 0;
  for (int x = head[cur]; x != -1; x = nxt[x]) {
    _f = 0;
    _dfs(end[x], cur, value[x]);
    f[end[x]] = _f;
    fsum += _f;
  }
  if (sum < ans) {
    ans = sum;
    rt = cur;
  }
  for (int x = head[cur]; x != -1; x = nxt[x])
    if (fsum - (f[end[x]] * 2.0) < 0 && !used[end[x]]) return dfs(end[x]);
  return cur;
}
int main() {
  memset(head, -1, sizeof(head));
  int n = inp();
  for (int i = 1; i <= n; i++) w[i] = inp();
  for (int i = 1; i < n; i++) {
    int u = inp();
    int v = inp();
    int w = inp();
    link(u, v, w);
    link(v, u, w);
  }
  dfs(1);
  printf("%d %.10lf\n", rt, ans);
}
