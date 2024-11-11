#include <bits/stdc++.h>
using namespace std;
const int prime = 999983;
const int INF = 0x7FFFFFFF;
const long long INFF = 0x7FFFFFFFFFFFFFFF;
const double pi = acos(-1.0);
const double inf = 1e18;
const double eps = 1e-6;
const long long mod = 1e9 + 7;
long long qpow(long long a, long long b) {
  long long s = 1;
  while (b > 0) {
    if (b & 1) s = s * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return s;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int dr[2][4] = {1, -1, 0, 0, 0, 0, -1, 1};
const int maxn = 2e5 + 10;
vector<int> G[maxn];
int topo[maxn];
int sg[maxn], deg[maxn], mem[maxn];
int Xor[maxn];
long long h[maxn];
int main(void) {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) scanf("%lld", &h[i]);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    deg[v]++;
  }
  queue<int> q;
  int cnt = 1;
  for (int i = 1; i <= n; ++i)
    if (deg[i] == 0) q.push(i);
  while (!q.empty()) {
    int p = q.front();
    q.pop();
    topo[cnt++] = p;
    for (auto c : G[p]) {
      deg[c]--;
      if (deg[c] == 0) q.push(c);
    }
  }
  for (int i = n; i >= 1; --i) {
    int u = topo[i];
    for (auto c : G[u]) mem[sg[c]] = i;
    while (mem[sg[u]] == i) sg[u]++;
    Xor[sg[u]] ^= h[i];
  }
  int index = -1;
  for (int i = 0; i < maxn; ++i)
    if (Xor[i] != 0) index = i;
  if (index == -1) return 0 * puts("LOSE");
  for (int i = 1; i <= n; ++i) {
    if (sg[i] == index && ((h[i] ^ Xor[index]) < h[i])) {
      h[i] ^= Xor[index];
      for (auto c : G[i]) {
        h[c] ^= Xor[sg[c]];
        Xor[sg[c]] = 0;
      }
      break;
    }
  }
  puts("WIN");
  for (int i = 1; i <= n; ++i) printf("%lld ", h[i]);
  return 0;
}
