#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
constexpr int Dir4[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
constexpr int Dir8[8][2] = {{-1, -1}, {-1, 1}, {0, -1},
                            {0, 1},   {1, -1}, {1, 1}};
constexpr double EPS = 1e-9;
const double PI = acos(-1);
using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5;
int n;
int64 x[MAXN + 1];
int64 ans = 0;
vector<int> G[MAXN + 1];
unordered_map<int64, int> container[MAXN + 1];
int64 __gcd(int64 a, int64 b) { return (b == 0 ? a : __gcd(b, a % b)); }
void dfs(int now, int from = 0) {
  ++container[now][x[now]];
  if (from) {
    for (auto it : container[from]) {
      int64 gcd = __gcd(x[now], it.first);
      container[now][gcd] += it.second;
      ans = (ans + gcd * it.second) % MOD;
    }
  }
  ans = (ans + x[now]) % MOD;
  for (auto nex : G[now]) {
    if (from == nex) continue;
    dfs(nex, now);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", x + i);
  for (int i = 1, u, v; i <= n - 1; ++i) {
    scanf("%d %d", &u, &v);
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  dfs(1);
  printf("%lld", ans);
  return 0;
}
