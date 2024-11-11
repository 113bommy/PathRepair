#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) { return b ? GCD(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / GCD(a, b); }
int lb(int x) { return x & (-x); }
const long long N = 1e2 + 7;
const long long inf = 1e18 + 1;
const long long mod2 = 998244353;
const long long mod1 = 1e9 + 7;
const int P1 = 13331;
const int P2 = 131;
const double eps = 1e-6;
const double dbinf = 1e13 + 7;
const long long mod3 = 10000 + 7;
int n, m;
string s;
struct node {
  int v, nxt;
  char c;
};
node e[N * N];
int tot;
int head[N];
void add(int u, int v, char c) {
  e[++tot] = {v, head[u], c};
  head[u] = tot;
}
int dp[N][N][25];
bool dfs(int u, int v, int w) {
  if (dp[u][v][w] != -1) {
    return dp[u][v][w];
  }
  for (int i = head[u]; i; i = e[i].nxt) {
    int V = e[i].v;
    if (e[i].c - 'a' < w) continue;
    if (!dfs(v, V, e[i].c - 'a')) {
      dp[u][v][w] = true;
      return true;
    }
  }
  return false;
}
int main() {
  memset(head, 0, sizeof head);
  memset(dp, -1, sizeof dp);
  cin >> n >> m;
  char w;
  for (int i = 1, u = 1, v = 1; i <= m; i++) {
    cin >> u >> v >> w;
    add(u, v, w);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dfs(i, j, 0)) {
        cout << "A";
      } else
        cout << "B";
    }
    cout << "\n";
  }
  return 0;
}
