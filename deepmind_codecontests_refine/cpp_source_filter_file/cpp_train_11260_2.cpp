#include <bits/stdc++.h>
using namespace std;
vector<int> g[200010];
const int logn = 19;
int dp[20][200010];
int sub[200010];
int dep[200010];
int nxt[200010];
int tail[200010];
int n;
int distance(int x) {
  cout << "d " << x << endl;
  int ans;
  cin >> ans;
  return ans;
}
int go(int x) {
  cout << "s " << x << endl;
  int ans;
  cin >> ans;
  return ans;
}
int lift(int x, int up) {
  for (int i = logn; i >= 0; i--) {
    if (up >= (1 << i)) {
      up -= 1 << i;
      x = dp[i][x];
    }
  }
  return x;
}
void dfs(int x, int par) {
  sub[x] = 1;
  nxt[x] = -1;
  dp[0][x] = par;
  for (auto i : g[x]) {
    if (i - par) {
      dep[i] = 1 + dep[x];
      dfs(i, x);
      sub[x] += sub[i];
      if (nxt[x] == -1 || sub[nxt[x]] < sub[i]) {
        nxt[x] = i;
      }
    }
  }
}
void build() {
  for (int i = 1; i <= n; i++) {
    if (i == 1 || nxt[dp[0][i]] != i) {
      tail[i] = i;
      for (int j = i; j != -1; j = nxt[j]) {
        tail[i] = j;
      }
    }
  }
  for (int i = 1; i <= logn; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = dp[i - 1][dp[i - 1][j]];
    }
  }
}
int solver(int x, int dist) {
  if (dist == 0) return x;
  int y = tail[x];
  int ydist = distance(y);
  int p = ydist - dist;
  int q = dep[y] - dep[x];
  int up = (p + q) / 2;
  int node = lift(y, up);
  int dist_node = dist - (dep[node] - dep[x]);
  if (dist_node == 0) return x;
  return solver(go(node), dist_node - 1);
}
int main(int argc, char const *argv[]) {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int p, q;
    cin >> p >> q;
    g[p].push_back(q);
    g[q].push_back(p);
  }
  dfs(1, 0);
  build();
  int x = solver(1, distance(1));
  cout << "! " << x << endl;
  return 0;
}
