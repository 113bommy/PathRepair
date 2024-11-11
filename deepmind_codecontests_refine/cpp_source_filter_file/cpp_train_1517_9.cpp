#include <bits/stdc++.h>
const int N = 100005;
const int M = 200005;
const int mod = 1000000007;
using LL = long long;
int n, m, head[N], tot;
struct edge {
  int to, nxt;
  LL cost;
} e[M << 1];
void addedge(int x, int y, LL z) {
  e[++tot] = (edge){y, head[x], z};
  head[x] = tot;
  e[++tot] = (edge){x, head[y], z};
  head[y] = tot;
}
const int LN = 60;
LL p[LN];
int rank = 0, w[2][LN];
void insert(LL v) {
  for (int i = LN - 1; ~i; i--)
    if (v >> i & 1) {
      if (!p[i]) p[i] = v, rank++;
      v ^= p[i];
    }
}
void clear() {
  rank = 0;
  for (int i = 0; i < LN; i++) p[i] = w[0][i] = w[1][i] = 0;
}
LL W[N];
void dfs(int x) {
  for (int i = 0; i < LN; i++) w[W[x] >> i & 1][i]++;
  for (int i = head[x]; i; i = e[i].nxt)
    if (!~W[e[i].to]) {
      W[e[i].to] = W[x] ^ e[i].cost;
      dfs(e[i].to);
    } else {
      insert(W[x] ^ W[e[i].to] ^ e[i].cost);
    }
}
inline void reduce(int &x) { x += x >> 31 & mod; }
int ans = 0;
int C(int x) { return (static_cast<LL>(x) * (x - 1) >> 1) % mod; }
int calc(int p) {
  bool flag = 0;
  for (int i = 0; i < LN; i++)
    if (::p[i] >> p & 1) flag = 1;
  int ans = 0, number = 0;
  if (flag)
    number = (1LL << rank - 1) % mod;
  else
    number = (1LL << rank) % mod;
  ans = static_cast<LL>(number) * w[0][p] % mod * w[1][p] % mod;
  if (flag)
    number = (1 << rank - 1) % mod;
  else
    number = 0;
  reduce(ans +=
         static_cast<LL>(number) * (C(w[0][p]) + C(w[1][p])) % mod - mod);
  return ans;
}
int pow(int p) { return (1LL << p) % mod; }
int main() {
  std::scanf("%d%d", &n, &m);
  std::memset(W, -1, sizeof W);
  for (int i = 1; i <= m; i++) {
    int x, y;
    LL z;
    std::scanf("%d%d%I64d", &x, &y, &z);
    addedge(x, y, z);
  }
  for (int i = 1; i <= n; i++)
    if (!~W[i]) {
      W[i] = 0;
      clear();
      dfs(i);
      for (int j = 0; j < LN; j++) {
        int val = calc(j);
        reduce(ans += (static_cast<LL>(val) * pow(j)) % mod - mod);
      }
    }
  std::printf("%d\n", ans);
  return 0;
}
