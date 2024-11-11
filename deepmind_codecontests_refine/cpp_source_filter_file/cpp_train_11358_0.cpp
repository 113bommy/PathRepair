#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
char buf[1 << 12], *pp1 = buf, *pp2 = buf, nc;
int ny;
inline char gc() {
  return pp1 == pp2 &&
                 (pp2 = (pp1 = buf) + fread(buf, 1, 1 << 12, stdin), pp1 == pp2)
             ? EOF
             : *pp1++;
}
inline long long read() {
  long long x = 0;
  for (ny = 1; nc = gc(), (nc < 48 || nc > 57) && nc != EOF;)
    if (nc == 45) ny = -1;
  if (nc < 0) return nc;
  for (x = nc - 48; nc = gc(), 47 < nc && nc < 58 && nc != EOF;
       x = (x << 3) + (x << 1) + (nc ^ 48))
    ;
  return x * ny;
}
long long m, x, N, p[MAXN], q[MAXN], a[MAXN], cnt, l, Ans;
map<long long, int> id;
vector<long long> phi[50];
inline long long Mul(long long a, long long b, long long Mod) {
  a %= Mod, b %= Mod;
  return (a * b - (unsigned long long)((long double)a / Mod * b) * Mod + Mod) %
         Mod;
}
inline long long Fp(long long x, long long k, long long Mod) {
  long long ans = 1;
  for (; k; k >>= 1, x = Mul(x, x, Mod))
    if (k & 1) ans = Mul(ans, x, Mod);
  return ans;
}
int main() {
  m = read(), x = read();
  for (long long i = 1; i * i <= m; i++)
    if (m % i == 0) {
      a[++cnt] = i;
      if (i * i != m) a[++cnt] = m / i;
    }
  sort(a + 1, a + cnt + 1);
  long long t = m;
  for (int i = 1; i <= cnt; i++) id[a[i]] = i;
  for (long long i = 2; i * i <= t; i++)
    for (; t % i == 0; t /= i, p[++N] = i)
      ;
  if (t != 1) p[++N] = t;
  for (int i = 1; i <= N; i++) q[i] = p[i];
  l = unique(q + 1, q + N + 1) - q - 1;
  for (int i = 1; i <= l; i++) {
    long long t = q[i] - 1;
    for (long long j = 2; j * j <= t; j++)
      for (; t % j == 0; t /= j, phi[i].push_back(j))
        ;
    if (t != 1) phi[i].push_back(t);
  }
  for (int i = 1; i <= cnt; i++) {
    long long t = a[i], ans = 1, k = 1;
    vector<long long> p(0);
    for (int i = 1; i <= l; i++)
      if (t % q[i] == 0) {
        for (auto o : phi[i]) p.push_back(i);
        for (t /= q[i]; t % q[i] == 0; t /= q[i], p.push_back(q[i]))
          ;
      }
    for (auto o : p) k *= o;
    t = k;
    for (auto o : p)
      if (Fp(x, k / o, a[i]) == 1) k /= o, ans *= o;
    Ans += ans;
  }
  cout << Ans << '\n';
  return 0;
}
