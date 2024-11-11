#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 998244353;
class Solution {
  long long cnt[2];
  vector<int> color;
  long long powMod(long long x, long long p, long long M) {
    long long ans = 1;
    for (long long cur = x; p; p >>= 1, cur = cur * cur % M) {
      if (p & 1) ans = cur * ans % M;
    }
    return ans;
  }
  long long bipartiteTestAndCounting(const vector<vector<int>> &g, int u,
                                     int c = 0) {
    color[u] = c;
    ++cnt[c];
    bool test = true;
    for (int v : g[u]) {
      if (color[v] == -1) {
        test &= bipartiteTestAndCounting(g, v, !c);
      } else if (color[v] == c)
        return false;
    }
    return test;
  }
  long long runGraph(const vector<vector<int>> &g) {
    long long ans = 0;
    color.assign(g.size(), -1);
    for (int i = 0; i < g.size(); ++i) {
      if (color[i] == -1) {
        memset(cnt, 0, sizeof(cnt));
        if (not bipartiteTestAndCounting(g, i)) {
          return 0;
        }
        (ans += powMod(2, cnt[0], MOD) + powMod(2, cnt[1], MOD)) %= MOD;
      }
    }
    return ans;
  }

 public:
  void run(istream &in, ostream &out) {
    int T;
    in >> T;
    while (T--) {
      int n, m;
      in >> n >> m;
      vector<vector<int>> g(n);
      for (int i = 0; i < m; ++i) {
        int u, v;
        in >> u >> v;
        --u, --v;
        g[u].push_back(v), g[v].push_back(u);
      }
      out << runGraph(g) << '\n';
    }
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  Solution().run(std::cin, std::cout);
  return 0;
}
