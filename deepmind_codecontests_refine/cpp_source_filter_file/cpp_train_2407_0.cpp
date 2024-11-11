#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long n) {
  long long r = 1 % P;
  for (a %= P; n; a = a * a % P, n >>= 1)
    if (n & 1) r = r * a % P;
  return r;
}
long long inv(long long first) {
  return first <= 1 ? 1 : inv(P % first) * (P - P / first) % P;
}
inline int rd() {
  int first = 0;
  char p = getchar();
  while (p < '0' || p > '9') p = getchar();
  while (p >= '0' && p <= '9') first = first * 10 + p - '0', p = getchar();
  return first;
}
const int N = 2e5 + 10;
int n;
vector<int> g[N];
struct _ {
  int first, second, u, v, ans1, ans2;
  bool operator<(const _ &rhs) const {
    if (ans1 != rhs.ans1) return ans1 < rhs.ans1;
    return ans2 < rhs.ans2;
  }
} dp[N][4], tmp[4], ans;
void dfs(int first, int f) {
  dp[first][0] = {first, 0, 0, 0, 0, 0};
  for (int second : g[first])
    if (second != f) {
      dfs(second, first);
      for (int i = 0; i <= 3; ++i) tmp[i] = dp[first][i];
      ++dp[second][0].ans2;
      tmp[0] = max(tmp[0], dp[second][0]);
      if (dp[first][0].ans2) {
        _ ret = dp[first][0];
        ret.second = dp[second][0].first;
        ret.ans2 += dp[second][0].ans2;
        tmp[1] = max(tmp[1], ret);
      }
      if (dp[first][1].ans2) {
        _ ret = dp[first][1];
        ret.u = dp[second][0].first;
        ret.ans2 += dp[second][0].ans2;
        tmp[2] = max(tmp[2], ret);
      }
      if (dp[first][2].ans2) {
        _ ret = dp[first][2];
        ret.v = dp[second][0].first;
        ret.ans2 += dp[second][0].ans2;
        tmp[3] = max(tmp[3], ret);
      }
      if (dp[second][1].ans2) {
        ++dp[second][1].ans1;
        tmp[1] = max(tmp[1], dp[second][1]);
        if (dp[first][0].ans2) {
          _ ret = dp[second][1];
          ret.ans2 += dp[first][0].ans2;
          ret.u = dp[first][0].first;
          tmp[2] = max(tmp[2], ret);
        }
        if (dp[first][1].ans2) {
          _ ret = dp[second][1];
          ret.ans1 += dp[first][1].ans1;
          ret.ans2 += dp[first][1].ans2;
          ret.u = dp[first][0].first;
          ret.v = dp[first][0].second;
          tmp[3] = max(tmp[3], ret);
        }
      }
      if (dp[second][2].ans2) {
        ++dp[second][2].ans2;
        tmp[2] = max(tmp[2], dp[second][2]);
        if (dp[first][0].ans2) {
          _ ret = dp[second][2];
          ret.ans2 += dp[first][0].ans2;
          ret.v = dp[first][0].first;
          tmp[3] = max(tmp[3], ret);
        }
      }
      for (int i = 0; i <= 3; ++i) dp[first][i] = tmp[i];
    }
  if (dp[first][3].ans2) ans = max(ans, dp[first][3]);
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v), g[v].push_back(u);
  }
  dfs(1, 0);
  printf("%d %d\n%d %d\n", ans.first, ans.u, ans.second, ans.v);
}
