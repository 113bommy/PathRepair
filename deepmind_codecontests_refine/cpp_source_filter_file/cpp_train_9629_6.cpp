#include <bits/stdc++.h>
using namespace std;
const int maxn = 500500;
std::vector<int> edge[maxn], D[maxn];
char str[maxn];
int dep[maxn], L[maxn], R[maxn];
bool ans[maxn];
vector<pair<int, int> > query[maxn];
struct BIT {
  int C[maxn], N;
  void add(int i, int x) {
    while (i <= N) C[i] += x, i += i & (-i);
  }
  int sum(int x) {
    int ans = 0;
    for (int i = x; i >= 1; i -= i & (-i)) ans += C[i];
    return ans;
  }
  int query(int l, int r) { return sum(r) - sum(l - 1); }
} pp[26];
int top;
void dfs(int u, int dep) {
  D[dep].push_back(u);
  L[u] = ++top;
  for (auto v : edge[u]) dfs(v, dep + 1);
  R[u] = top;
}
int main() {
  int m, n;
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; i++) edge[i].clear(), D[i].clear();
    for (int i = 2; i <= n; i++) {
      int x;
      scanf("%d", &x);
      edge[x].push_back(i);
    }
    scanf("%s", str + 1);
    for (int i = 0; i < 26; i++) {
      memset(pp[i].C, 0, sizeof(pp[i].C));
      pp[i].N = n + 10;
    }
    for (int i = 1; i <= m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      query[v].push_back(make_pair(u, i));
    }
    top = 0;
    dfs(1, 1);
    std::fill(ans, ans + n + 10, 1);
    for (int i = 1; i <= n; i++) {
      if (D[i].empty()) continue;
      for (auto v : D[i]) pp[str[v] - 'a'].add(L[v], 1);
      for (auto Q : query[i]) {
        int tt = 0;
        for (int j = 0; j < 26; j++) {
          int jj = pp[j].query(L[Q.first], R[Q.first]);
          if (jj) tt += jj & 1;
        }
        ans[Q.second] = tt <= 1;
      }
      for (auto v : D[i]) pp[str[v] - 'a'].add(L[v], -1);
    }
    for (int i = 1; i <= m; i++) puts(ans[i] ? "Yes" : "No");
  }
  return 0;
}
