#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = ' ';
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = -1;
  }
  while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * f;
}
long long n, sz[80005];
long long ans;
vector<int> g[80005];
void dfs(int u, int fa) {
  long long ans1 = 0, ans2 = 0;
  sz[u] = 1;
  for (int v : g[u]) {
    if (v == fa) continue;
    dfs(v, u);
    sz[u] += sz[v];
    ans1 -= sz[v] * (sz[v] - 1) / 2;
  }
  ans1 += (sz[u] - 1) * sz[u] / 2;
  ans2 += sz[u] * (n - sz[u]);
  ans -= (ans1 * ans1 + ans1 * ans2 * 2);
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a = read(), b = read();
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1, 1);
  cout << (long long)n * (n - 1) / 2 * n * (n - 1) / 2 + ans;
}
