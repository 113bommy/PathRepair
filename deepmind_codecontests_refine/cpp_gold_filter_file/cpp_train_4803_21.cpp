#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + (s - '0');
    s = getchar();
  }
  return x * f;
}
const int jzm = 1000000007;
const int zxy = 998244353;
int n, m, i, j, s, o, k;
int ind[100005], tp[100005];
int U[100005], V[100005], W[100005];
struct it {
  int v, w;
  it() { v = w = 0; }
  it(int V, int W) {
    v = V;
    w = W;
  }
};
vector<int> g[100005];
bool flag = 1;
int v[100005];
void dfs(int x) {
  if (!flag) return;
  v[x] = 1;
  for (int i = 0; i < g[x].size(); i++) {
    if (v[g[x][i]] == 1) {
      flag = 0;
      return;
    }
    if (!v[g[x][i]]) dfs(g[x][i]);
  }
  v[x] = 2;
  return;
}
bool check(int ma) {
  flag = 1;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    v[i] = 0;
    ind[i] = 0;
    tp[i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    if (W[i] > ma) {
      g[U[i]].push_back(V[i]);
      ind[V[i]]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!v[i]) dfs(i);
  }
  return flag;
}
queue<int> b;
int pr[100005], ct;
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; i++) {
    U[i] = read();
    V[i] = read();
    W[i] = read();
  }
  int l = 0, r = 1e9, mid;
  while (l < r) {
    mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  check(l);
  for (int i = 1; i <= n; i++) {
    if (ind[i] == 0) {
      b.push(i);
    }
  }
  int cn = 0;
  while (!b.empty()) {
    int t = b.front();
    b.pop();
    tp[t] = ++cn;
    for (int i = 0; i < g[t].size(); i++) {
      ind[g[t][i]]--;
      if (ind[g[t][i]] == 0) b.push(g[t][i]);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (W[i] <= l) {
      if (tp[U[i]] > tp[V[i]]) pr[++ct] = i;
    }
  }
  printf("%d %d\n", l, ct);
  for (int i = 1; i <= ct; i++) printf("%d ", pr[i]);
  putchar('\n');
  return 0;
}
