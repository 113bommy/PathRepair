#include <bits/stdc++.h>
using namespace std;
const int N = 200020;
vector<int> g[N];
int cor[N];
int mod = 1000 * 1000 * 1000 + 7;
long long dp[N][2][2];
long long fpow(long long b, long long e) {
  if (!e) return 1;
  long long r = fpow(b, e / 2);
  r = (r * r) % mod;
  return e % 2 ? (r * b) % mod : r;
}
long long solve(int u, int has_black, int need_black) {
  long long &ret = dp[u][has_black][need_black];
  if (ret != -1) return ret;
  if (cor[u] and has_black) {
    return ret = solve(u, 0, 1);
  }
  if (g[u].empty()) {
    if (need_black and !cor[u]) return ret = 0;
    return ret = 1;
  }
  ret = 0;
  if (has_black) ret = solve(u, 0, 1);
  if (cor[u] or has_black) {
    long long aux = 1;
    for (auto v : g[u]) aux = (aux * solve(v, 1, 0)) % mod;
    ret = (ret + aux) % mod;
  } else {
    long long total = 1;
    for (auto v : g[u]) total = (total * solve(v, 1, 0));
    for (auto v : g[u]) {
      long long aux = (total * fpow(solve(v, 1, 0), mod - 2)) % mod;
      aux = (aux * solve(v, 0, 1)) % mod;
      ret = (ret + aux) % mod;
    }
  }
  return ret;
}
int main(void) {
  memset(dp, -1, sizeof dp);
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    g[p].push_back(i);
  }
  for (int i = 0; i < n; i++) scanf("%d", cor + i);
  cout << solve(0, 0, 1) << endl;
  return 0;
}
