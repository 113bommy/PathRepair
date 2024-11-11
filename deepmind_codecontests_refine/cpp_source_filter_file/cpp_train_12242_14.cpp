#include <bits/stdc++.h>
using namespace std;
const int NN = 3e5 + 5, Mod = 1e9 + 7, NS = 6e5 + 5;
int Ml(int x, int y) { return (long long)x * y % Mod; }
int Ad(int x, int y) { return ((x + y) > Mod) ? (x + y - Mod) : (x + y); }
int Dc(int x, int y) { return ((x - y) < 0) ? (x - y + Mod) : (x - y); }
int N, ans, ls, lt, pw[NN], cf;
char s[NN], t[NN];
int gcd(int x, int y) { return (!y) ? x : gcd(y, x % y); }
void AllSame() {
  if (ls != lt) return;
  for (int i = 1; i <= ls; ++i)
    if (s[i] != t[i] && s[i] != '?' && t[i] != '?') return;
  int o = 1;
  for (int i = 1; i <= ls; ++i)
    if (s[i] == '?' && t[i] == '?') o = Ml(o, 2);
  cf = o;
  ans = Ad(ans, Ml(o, Ml(Dc(pw[N + 1], 2), Dc(pw[N + 1], 2))));
}
int ksm(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1, x = Ml(x, x))
    if (y & 1) ret = Ml(ret, x);
  return ret;
}
int na[2], nb[2], nw[2], fac[NS], iac[NS];
void Init() {
  fac[0] = 1;
  for (int i = 1; i <= ls + lt; ++i) fac[i] = Ml(fac[i - 1], i);
  iac[ls + lt] = ksm(fac[ls + lt], Mod - 2);
  for (int i = ls + lt - 1; i >= 0; --i) iac[i] = Ml(iac[i + 1], i + 1);
}
int binom(int x, int y) {
  if (x < 0 || y < 0 || x < y) return 0;
  return Ml(fac[x], Ml(iac[y], iac[x - y]));
}
int Cal(int x, int y, int c) {
  if (c < 0) {
    swap(x, y);
    c = -c;
  }
  return binom(x + y, y - c);
}
int mu[NN], prime[NN], ptot;
bool notp[NN];
void IInit() {
  mu[1] = 1;
  notp[1] = 1;
  for (int i = 2; i <= N; ++i) {
    if (!notp[i]) {
      prime[++ptot] = i;
      mu[i] = -1;
    }
    for (int j = 1; j <= ptot; ++j) {
      if ((long long)i * prime[j] > N) break;
      notp[i * prime[j]] = 1;
      if (i % prime[j] != 0)
        mu[i * prime[j]] = -mu[i];
      else
        mu[i * prime[j]] = 0;
    }
  }
  for (int i = 1; i <= N; ++i)
    if (mu[i] < 0) mu[i] += Mod;
}
int main() {
  scanf("%s%s%d", s + 1, t + 1, &N);
  pw[0] = 1;
  for (int i = 1; i <= N + 1; ++i) pw[i] = Ml(pw[i - 1], 2);
  ls = strlen(s + 1);
  lt = strlen(t + 1);
  Init();
  for (int i = 1; i <= ls; ++i) {
    if (s[i] == 'A')
      ++na[0];
    else if (s[i] == 'B')
      ++nb[0];
    else
      ++nw[0];
  }
  for (int i = 1; i <= lt; ++i) {
    if (t[i] == 'A')
      ++na[1];
    else if (t[i] == 'B')
      ++nb[1];
    else
      ++nw[1];
  }
  AllSame();
  for (int c = -nw[1]; c <= nw[0]; ++c) {
    int ca = na[0] - na[1] + c, cb = (nb[1] - nb[0]) + (nw[1] - nw[0]) + c;
    if ((ca >= 0 && cb <= 0) || (ca <= 0 && cb >= 0)) continue;
    if (ca < 0 && cb < 0) {
      ca = -ca;
      cb = -cb;
    }
    int g = gcd(ca, cb);
    int con = pw[N / max(ca / g, cb / g) + 1] - 2;
    con = Ml(con, Cal(nw[0], nw[1], -c));
    ans = Ad(ans, con);
  }
  if (ls == lt) {
    int xd = Cal(nw[0], nw[1], na[0] - na[1]) - cf;
    IInit();
    for (int d = 1; d <= N; ++d) {
      int ho = 0;
      for (int i = 1; i <= N / d; ++i)
        ho = Ad(ho, Ml(mu[i], Ml(N / d / i, N / d / i)));
      ans = Ad(ans, Ml(Ml(ho, pw[d]), xd));
    }
  }
  printf("%d\n", ans);
  return 0;
}
