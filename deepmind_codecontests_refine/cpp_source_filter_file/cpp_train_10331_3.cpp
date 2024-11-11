#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
const long long maxn = 5e5 + 5, MOD = 998244353;
long long ans[maxn], dp[maxn];
bool ma[maxn][31];
long long one[maxn], zero[maxn];
signed F[maxn + 1];
void add(long long pos, long long x) {
  if (!pos) {
    F[0] += x;
    return;
  }
  for (; pos <= maxn; pos += pos & -pos) F[pos] += x;
}
long long get(long long l, long long r) {
  if (l != 1)
    return (get(1, r) - get(1, l - 1) + (l == 0 ? F[0] : 0) + 5ll * MOD) % MOD;
  long long res = 0;
  for (; r > 0; r -= r & -r) res += F[r];
  return res % MOD;
}
signed de[maxn];
struct event {
  signed L, R, B;
};
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k, m;
  cin >> n >> k >> m;
  long long ANS = 1;
  vector<event> V;
  for (long long i = 0; i < m; i++) {
    signed L, R, X;
    cin >> L >> R >> X;
    V.push_back({L, R, X});
    for (long long j = 0; j < k; j++) ma[i][j] = (X >> j & 1);
  }
  for (long long i = 0; i < k; i++) {
    memset(F, 0, sizeof F);
    memset(one, 0, sizeof one);
    memset(zero, 0, sizeof zero);
    memset(de, 0, sizeof de);
    long long ans = 1;
    for (long long j = 0; j < m; j++) {
      if (ma[j][i])
        one[V[j].L]++, one[V[j].R + 1]--;
      else
        de[V[j].R] = max(de[V[j].R], V[j].L);
    }
    signed LAST = 0;
    for (long long j = 0; j <= maxn; j++) assert(F[j] == 0);
    add(0, 1);
    long long one_ = 0;
    for (long long j = 1; j <= n; j++) {
      one_ += one[j];
      if (!one_) add(j, get(LAST, j - 1));
      LAST = max(LAST, de[j]);
    }
    ANS *= get(LAST, n);
    ANS %= MOD;
  }
  cout << ANS;
}
