#include <bits/stdc++.h>
using namespace std;
long long n, m, b = 1;
long long Ne[100005 * 4], E[100005 * 4], HEAD[100005];
long long s, e, lca, h, ans;
long long Rt[100005];
long long Dep[100005], F[100005], mo = 1e9 + 7, cnt = 1;
long long Q[100005], C[100005], D[100005], FO[102];
long long Cnt[61][2], tot, fo;
long long Lian[61][2], Ch[75][75], o;
void ADD(long long s, long long e) { Ne[++b] = HEAD[s], HEAD[s] = b, E[b] = e; }
void Insert(long long a) {
  if (!a) return;
  for (long long i = 60; i >= 0; i--) {
    if (a & (1ll << i)) {
      if (FO[i])
        a ^= FO[i];
      else {
        FO[i] = a;
        tot++;
        break;
      }
    }
  }
}
void DO(long long q, long long i) {
  fo = (1ll << (tot - h)) % mo;
  fo = (1ll * fo * Cnt[i][q]) % mo;
  fo = ((1ll << i) % mo) * fo % mo;
  o = 0;
  for (long long k = q ^ 1; k <= h; k += 2) o = (o + Ch[h][k]) % mo;
  fo = 1ll * fo * o % mo;
  ans += fo;
  ans %= mo;
}
void DFS(long long i, long long f, long long rt) {
  F[i] = f, Dep[i] = Dep[f] + 1;
  for (long long q = 0; q <= 60; q++) {
    o = (Q[i] & (1ll << q)) > 0;
    (Cnt[q][0] += Lian[q][o]) %= mo;
    (Cnt[q][1] += Lian[q][o ^ 1]) %= mo;
    Lian[q][o]++;
  }
  for (long long z = HEAD[i]; z; z = Ne[z]) {
    if (Dep[E[z]]) {
      Insert(Q[E[z]] ^ D[z >> 1] ^ Q[i]);
      continue;
    }
    Q[E[z]] = Q[i] ^ D[z >> 1];
    DFS(E[z], i, rt);
  }
}
signed main() {
  scanf("%lld %lld", &n, &m);
  for (long long i = 1; i <= m; i++) {
    scanf("%lld %lld %lld", &s, &e, &C[i]);
    ADD(s, e), ADD(e, s), D[i] = C[i];
  }
  Ch[0][0] = 1;
  for (long long i = 1; i <= 10; i++) {
    Ch[i][0] = 1;
    for (long long j = 1; j <= i; j++) {
      Ch[i][j] = (Ch[i - 1][j] + Ch[i - 1][j - 1]) % mo;
    }
  }
  for (long long q = 1; q <= n; q++)
    if (!Dep[q]) {
      memset(FO, 0, sizeof(FO));
      memset(Cnt, 0, sizeof(Cnt));
      memset(Lian, 0, sizeof(Lian));
      tot = 0;
      DFS(q, 0, q);
      for (long long i = 60; i >= 0; i--)
        for (long long j = i - 1; j >= 0; j--)
          if (FO[i] & (1ll << j)) FO[i] ^= FO[j];
      for (long long i = 0; i <= 60; i++) {
        h = 0;
        for (long long j = 60; j >= 0; j--) h += ((FO[j] & (1ll << i)) > 0);
        DO(0, i);
        DO(1, i);
      }
    }
  printf("%lld", ans);
  return 0;
}
