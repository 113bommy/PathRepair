#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
struct Gragh {
  int cnt, y[N * 2], z[N * 2], nxt[N * 2], fst[N];
  void clear() {
    cnt = 0;
    memset(fst, 0, sizeof fst);
  }
  void add(int a, int b, int c) {
    y[++cnt] = b, z[cnt] = c, nxt[cnt] = fst[a], fst[a] = cnt;
  }
  int n, m, depth[N], in[N], out[N], _____time;
  int ST[N * 2][20];
  void dfs(int x, int pre) {
    in[x] = ++_____time;
    ST[_____time][0] = x;
    for (int i = fst[x]; i; i = nxt[i])
      if (y[i] != pre) {
        depth[y[i]] = depth[x] + z[i];
        dfs(y[i], x);
        ST[++_____time][0] = x;
      }
    out[x] = _____time;
  }
  void Get_ST(int n) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j < 20; j++) {
        ST[i][j] = ST[i][j - 1];
        int v = i - (1 << (j - 1));
        if (v > 0 && depth[ST[v][j - 1]] < depth[ST[i][j]])
          ST[i][j] = ST[v][j - 1];
      }
  }
  int RMQ(int L, int R) {
    if (L > R) std::swap(L, R);
    int val = floor(log(R - L + 1) / log(2));
    int x = ST[L + (1 << val) - 1][val], y = ST[R][val];
    if (depth[x] < depth[y])
      return x;
    else
      return y;
  }
} graphA, graphB;
std::vector<int> leafA;
std::vector<int> leafB;
int dp[2][2011][2011];
int main() {
  int n;
  std::cin >> n;
  int sizeA;
  int sizeB;
  std::cin >> sizeA;
  graphA.n = sizeA;
  for (int i = 2, c; i <= sizeA; i++) {
    std::cin >> c;
    graphA.add(i, c, 1);
    graphA.add(c, i, 1);
  }
  leafA.resize(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> leafA[i];
  }
  graphA._____time = 0;
  graphA.dfs(1, 0);
  graphA.depth[0] = 10000000;
  graphA.Get_ST(graphA._____time);
  std::cin >> sizeB;
  graphB.n = sizeB;
  for (int i = 2, c; i <= sizeB; i++) {
    std::cin >> c;
    graphB.add(i, c, 1);
    graphB.add(c, i, 1);
  }
  leafB.resize(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> leafB[i];
  }
  graphB._____time = 0;
  graphB.dfs(1, 0);
  graphB.depth[0] = 10000000;
  graphB.Get_ST(graphB._____time);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j <= 1001; ++j) {
      for (int l = 0; l <= 1001; ++l) {
        dp[i][j][l] = 0;
      }
    }
  }
  std::set<std::pair<int, int>> stk[2];
  stk[0].clear();
  stk[1].clear();
  int nowId = 0;
  stk[nowId].insert(std::make_pair(1, 1));
  for (int i = 0; i < n; ++i) {
    for (auto itr = stk[nowId].begin(); itr != stk[nowId].end(); ++itr) {
      int up = (*itr).first;
      int down = (*itr).second;
      {
        int lca = graphA.RMQ(graphA.in[up], graphA.in[leafA[i]]);
        int cost = graphA.depth[leafA[i]] - graphA.depth[lca];
        if (dp[nowId ^ 1][leafA[i]][down] == 0) {
          dp[nowId ^ 1][leafA[i]][down] = dp[nowId][up][down] + cost;
        } else {
          dp[nowId ^ 1][leafA[i]][down] = std::min(
              dp[nowId ^ 1][leafA[i]][down], dp[nowId][up][down] + cost);
        }
        stk[nowId ^ 1].insert(std::make_pair(leafA[i], down));
      }
      {
        int lca = graphB.RMQ(graphB.in[down], graphB.in[leafB[i]]);
        int cost = graphB.depth[leafB[i]] - graphB.depth[lca];
        if (dp[nowId ^ 1][up][leafB[i]] == 0) {
          dp[nowId ^ 1][up][leafB[i]] = dp[nowId][up][down] + cost;
        } else {
          dp[nowId ^ 1][up][leafB[i]] =
              std::min(dp[nowId ^ 1][up][leafB[i]], dp[nowId][up][down] + cost);
        }
        stk[nowId ^ 1].insert(std::make_pair(up, leafB[i]));
      }
      dp[nowId][up][down] = 0;
    }
    stk[nowId].clear();
    nowId ^= 1;
  }
  int ans = 100000000;
  for (int i = 0; i < sizeA; ++i) {
    for (int j = 0; j < sizeB; ++j) {
      if (dp[nowId][i][j] > 0) {
        ans = std::min(ans, dp[nowId][i][j]);
      }
    }
  }
  std::cout << sizeA + sizeB - 2 - ans << std::endl;
  return 0;
}
