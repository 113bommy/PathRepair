#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const long long mod = 998244353;
template <class nmsl>
inline void read(nmsl &x) {
  x = 0;
  char ch = getchar(), w = 0;
  while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  x = w ? -x : x;
}
int bianshu, n, hd[N];
long long ans;
long long dp[N], jc[N];
struct abc {
  int nxt, to;
} qwq[N * 2];
inline void addedg(int lai, int qu) {
  qwq[++bianshu].nxt = hd[lai];
  qwq[bianshu].to = qu;
  hd[lai] = bianshu;
}
inline void tree_dp(int u, int f) {
  int sonnum = 0;
  dp[u] = 1;
  for (register int i = hd[u]; i; i = qwq[i].nxt) {
    int v = qwq[i].to;
    if (v == f) continue;
    sonnum++;
    tree_dp(v, u);
    dp[u] = (dp[u] * dp[v]) % mod;
  }
  if (u != 1)
    dp[u] = (dp[u] * jc[sonnum + 1]) % mod;
  else
    dp[u] = (dp[u] * n) % mod, dp[u] = (dp[u] * jc[sonnum]);
}
int main() {
  read(n);
  jc[0] = 1;
  for (register int i = 1; i <= n; i++) jc[i] = jc[i - 1] * i % mod;
  for (register int i = 1, qa, qb; i < n; i++)
    read(qa), read(qb), addedg(qa, qb), addedg(qb, qa);
  tree_dp(1, 0);
  cout << dp[1];
  return 0;
}
