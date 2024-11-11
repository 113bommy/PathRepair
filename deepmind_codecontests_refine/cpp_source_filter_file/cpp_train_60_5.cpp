#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int maxn = 1e5 + 50;
int n, fa[maxn], K[maxn], deep[maxn], id[maxn];
vector<int> G[maxn];
long long a[maxn], b[maxn];
void Dfs(int u, int f = 0) {
  for (auto&& v : G[u]) {
    if (v == f) continue;
    deep[v] = deep[u] + 1;
    Dfs(v, u);
  }
}
int main(int argc, char* argv[]) {
  n = read();
  for (int i = 1; i <= n; ++i) scanf("%I64d", b + i);
  for (int i = 1; i <= n; ++i) scanf("%I64d", a + i);
  for (int i = 2; i <= n; ++i) {
    fa[i] = read(), K[i] = read();
    G[fa[i]].emplace_back(i);
  }
  K[1] = 1;
  for (int i = 1; i <= n; ++i) id[i] = i;
  Dfs(1);
  sort(id + 1, id + n + 1,
       [](const int& x, const int& y) { return deep[x] > deep[y]; });
  for (int i = 1; i <= n;) {
    int j = i;
    while (j <= n && deep[id[j]] == deep[id[i]]) ++j;
    for (int k = i; k < j; ++k) {
      int x = id[k];
      if (b[x] >= a[x]) b[fa[x]] += (b[x] - a[x]);
    }
    for (int k = i; k < j; ++k) {
      int x = id[k];
      if (b[x] < a[x]) {
        double z = (double)b[fa[x]] - (double)(a[x] - b[x]) * (double)K[x];
        if (b[fa[x]] < -3e18) {
          puts("NO");
          return 0;
        }
        b[fa[x]] -= (a[x] - b[x]) * K[x];
      }
    }
    i = j;
  }
  if (b[0] < 0) {
    puts("NO");
    return 0;
  }
  puts("YES");
  return 0;
}
