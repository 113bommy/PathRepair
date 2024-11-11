#include <bits/stdc++.h>
using namespace std;
namespace mine {
long long qread() {
  long long ans = 0, f = 1;
  char c = getchar();
  while (c < '0' or c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while ('0' <= c and c <= '9') ans = ans * 10 + c - '0', c = getchar();
  return ans * f;
}
void write(long long num) {
  if (num < 0) putchar('-'), num = -num;
  if (num >= 10) write(num / 10);
  putchar('0' + num % 10);
}
void write1(long long num) {
  write(num);
  putchar(' ');
}
void write2(long long num) {
  write(num);
  putchar('\n');
}
template <typename T>
inline bool chmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool chmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
bool IN(long long x, long long l, long long r) { return l <= x and x <= r; }
void GG() {
  puts("-1");
  exit(0);
}
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int mm(const int x) { return x >= MOD ? x - MOD : x; }
template <typename T>
void add(T &x, const int &y) {
  x = (x + y >= MOD ? x + y - MOD : x + y);
}
long long qpower(long long x, long long e, int mod = MOD) {
  long long ans = 1;
  while (e) {
    if (e & 1) ans = ans * x % mod;
    x = x * x % mod;
    e >>= 1;
  }
  return ans;
}
long long invm(long long x) { return qpower(x, MOD - 2); }
const int MM = 1e6 + 10;
long long fac[MM], facinv[MM], Inv[MM];
long long Comb(int n, int m) {
  return n < 0 or m < 0 or n < m
             ? 0
             : fac[n] * facinv[m] % MOD * facinv[n - m] % MOD;
}
void PRE() {
  fac[0] = 1;
  for (int i = (1), I = (MM - 1); i <= I; i++) fac[i] = fac[i - 1] * i % MOD;
  facinv[MM - 1] = invm(fac[MM - 1]);
  for (int i = (MM - 1), I = (1); i >= I; i--)
    facinv[i - 1] = facinv[i] * i % MOD;
  Inv[1] = 1;
  for (int i = (2), I = (MM - 1); i <= I; i++)
    Inv[i] = (MOD - MOD / i) * Inv[MOD % i] % MOD;
}
const int N = 1e6 + 10;
map<long long, vector<int> > num;
pair<long long, long long> a[N];
long long f[15][1 << 15], g[15][1 << 15];
vector<int> can[N];
void main() {
  long long n = qread(), K = qread(), D = 0;
  for (int i = (1), I = (n); i <= I; i++)
    a[i].first = qread(), D = gcd(D, a[i].first);
  for (int i = (1), I = (n); i <= I; i++) a[i].second = qread();
  vector<long long> pr;
  for (long long d = 2; d * d <= D; d++)
    if (D % d == 0) {
      pr.push_back(d);
      while (D % d == 0) D /= d;
    }
  if (D > 1) pr.push_back(D);
  int z = ((int)(pr).size());
  for (int i = (1), I = (n); i <= I; i++) {
    long long nw = 1;
    for (auto p : pr)
      while (a[i].first % p == 0) a[i].first /= p, nw *= p;
    num[nw].push_back(a[i].second);
  }
  n = 0;
  for (auto i : num) {
    sort((i.second).begin(), (i.second).end());
    for (int j = (0), I = (((int)(i.second).size()) - 1); j <= I; j++)
      if (j < z) a[++n] = {i.first, i.second[j]};
  }
  for (int s = (1), I = ((1ll << (z)) - 1); s <= I; s++) {
    priority_queue<pair<int, int> > q;
    for (int i = (1), I = (n); i <= I; i++) {
      long long ss = 1, now = a[i].first;
      for (int i = (0), I = (z - 1); i <= I; i++)
        if (s & (1ll << (i)))
          while (now % pr[i] == 0) now /= pr[i], ss *= pr[i];
      if (ss <= K) {
        if (((int)(q).size()) < z)
          q.push({a[i].second, i});
        else if (q.top().first > a[i].second)
          q.pop(), q.push({a[i].second, i});
      }
    }
    while (((int)(q).size())) can[q.top().second].push_back(s), q.pop();
  }
  memset(f, 0x3f, sizeof f);
  f[0][0] = 0;
  for (int i = (1), I = (n); i <= I; i++)
    if (((int)(can[i]).size())) {
      for (int ct = (0), I = (z); ct <= I; ct++)
        for (int s = (0), I = ((1ll << (z)) - 1); s <= I; s++)
          g[ct][s] = f[ct][s];
      for (int ct = (0), I = (z - 1); ct <= I; ct++)
        for (auto ad : can[i])
          for (auto s = ad; s < (1ll << (z)); s = (s + 1) | ad)
            chmin(f[ct + 1][s], g[ct][s ^ ad] + a[i].second);
    }
  long long ans = (1ll << (62));
  for (int ct = (0), I = (z); ct <= I; ct++)
    if (f[ct][(1ll << (z)) - 1] < f[0][1])
      chmin(ans, ct * f[ct][(1ll << (z)) - 1]);
  write(ans >= (1ll << (62)) ? -1 : ans);
}
};  // namespace mine
signed main() {
  srand(time(0));
  mine::main();
  printf("");
}
