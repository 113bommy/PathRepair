#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int maxn = 5e5 + 11;
const int MOD = 1e9 + 7;
int N, M, K, u[maxn], v[maxn], p[maxn];
long long c[maxn], pw[maxn];
int gf(int x) { return x == p[x] ? x : p[x] = gf(p[x]); }
vector<int> G[maxn], ver;
map<long long, vector<int>> edge;
int main() {
  cin >> N >> M >> K;
  pw[0] = 1;
  for (int i = 1; i <= N; i++) pw[i] = pw[i - 1] * 2 % MOD;
  for (int i = 1; i <= N; i++) scanf("%lld", &c[i]);
  for (int i = 1; i <= N; i++) p[i] = i;
  for (int i = 1; i <= M; i++) {
    scanf("%d%d", &u[i], &v[i]);
    G[u[i]].push_back(v[i]);
    G[v[i]].push_back(u[i]);
    edge[c[u[i]] ^ c[v[i]]].push_back(i);
  }
  long long res = 0;
  for (auto e : edge) {
    ver.clear();
    int cc = N;
    for (int i : e.second) {
      int gu = gf(u[i]), gv = gf(v[i]);
      if (gu != gv) p[gu] = gv, --cc;
      ver.push_back(u[i]);
      ver.push_back(v[i]);
    }
    for (int x : ver) p[x] = x;
    res = (res + pw[cc]) % MOD;
  }
  long long ans = 1LL * ((1LL << K) - edge.size()) % MOD * pw[N] % MOD;
  ans = (ans + res) % MOD;
  cout << ans << endl;
  return 0;
}
