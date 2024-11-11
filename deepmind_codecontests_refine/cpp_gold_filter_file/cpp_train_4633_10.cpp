#include <bits/stdc++.h>
using namespace std;
vector<int> g[440];
int rst[220][220];
char buffer[220];
char s[220];
int vv[220];
int n, len, m;
int key = 1;
int dfs(int k, int u) {
  int len = g[u].size();
  for (int i = 0; i < (len); ++i) {
    int v = g[u][i];
    if (rst[k][v >> 1] == (~v & 1))
      return 0;
    else if (rst[k][v >> 1] == 2) {
      rst[k][v >> 1] = (v & 1);
      if (!dfs(k, v)) return 0;
    }
  }
  return 1;
}
int go(int k, int v) {
  for (int i = 0; i < (len); ++i) rst[k + 1][i] = rst[k][i];
  if (rst[k + 1][k] == v)
    return 1;
  else if (rst[k + 1][k] == !v)
    return 0;
  else {
    rst[k + 1][k] = v;
    return dfs(k + 1, (k << 1) | (rst[k + 1][k]));
  }
}
void print() {
  for (int i = 0; i < (len); ++i) s[i] += 'a';
  s[len] = 0;
  key = 0;
  cout << s << endl;
}
int DFS(int k, int eq) {
  if (k == len) {
    print();
    return 1;
  }
  if (eq && (rst[k][k] == 2 || rst[k][k] == vv[buffer[k]])) {
    if (go(k, vv[buffer[k]])) {
      s[k] = buffer[k];
      if (DFS(k + 1, eq)) return 1;
    }
  }
  int t = eq ? buffer[k] + 1 : 0;
  if (t < n && rst[k][k] != (!vv[t]) && go(k, vv[t])) {
    s[k] = t;
    return DFS(k + 1, 0);
  }
  int v = vv[t];
  while (t < n && vv[t] == v) ++t;
  if (t < n && rst[k][k] != (!vv[t]) && go(k, vv[t])) {
    s[k] = t;
    return DFS(k + 1, 0);
  }
  return 0;
}
void solve() {
  scanf("%s", buffer);
  n = strlen(buffer);
  for (int i = 0; i < (n); ++i) vv[i] = (buffer[i] != 'V');
  cin >> len >> m;
  for (int i = 0; i < (m); ++i) {
    int a, b;
    char x[2], y[2];
    scanf("%d%s%d%s", &a, x, &b, y);
    --a;
    --b;
    int u = (a << 1) | (x[0] != 'V');
    int v = (b << 1) | (y[0] != 'V');
    g[u].push_back(v);
    g[v ^ 1].push_back(u ^ 1);
  }
  scanf("%s", buffer);
  for (int i = 0; i < (len); ++i) buffer[i] -= 'a';
  for (int i = 0; i < (len); ++i) rst[0][i] = 2;
  if (!DFS(0, 1)) cout << -1 << endl;
}
int main() {
  solve();
  return 0;
}
