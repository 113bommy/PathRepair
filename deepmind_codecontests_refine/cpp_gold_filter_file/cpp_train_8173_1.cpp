#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(long long a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writeln(long long a) {
  write(a);
  puts("");
}
inline void wri(long long a) {
  write(a);
  putchar(' ');
}
const int N = 10005, mod = 1000000007;
const long long mod2 = (long long)mod * mod * 7;
inline long long ksm(long long a, int b) {
  int ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
  }
  return ans;
}
int rnd(int mod) {
  unsigned long long ans = 0;
  for (int i = 0; i < 5; i++) ans = ans << 15 ^ rand();
  return ans % (mod - 1) + 1;
}
vector<long long> BM(vector<long long> x) {
  vector<long long> ls, cur;
  int lf, lt, len = x.size();
  for (int i = 0; i < len; i++) {
    long long t = -x[i] % mod;
    for (unsigned j = 0; j < cur.size(); j++) {
      t = (t + (long long)x[i - j - 1] * cur[j]) % mod;
    }
    if (!t) continue;
    if (!cur.size()) {
      cur.resize(i + 1);
      lf = i;
      lt = t;
      continue;
    }
    long long zs = -t * ksm(lt, mod - 2) % mod;
    vector<long long> c(i - lf - 1);
    c.push_back(-zs);
    for (auto j : ls) c.push_back(j * zs % mod);
    if (c.size() < cur.size()) c.resize(cur.size());
    for (unsigned j = 0; j < cur.size(); j++) c[j] = (c[j] + cur[j]) % mod;
    if (i - lf + ls.size() >= cur.size()) {
      ls = cur;
      lf = i;
      lt = t;
    }
    cur = c;
  }
  for (auto &i : cur) i = (i % mod + mod) % mod;
  return cur;
}
long long f[2][N];
int d[N];
long long solve(int n, vector<pair<int, int> > &v) {
  long long sum = 1;
  vector<long long> h(n), hh(n);
  for (int i = 0; i < n; i++) sum = sum * (hh[i] = rnd(mod)) % mod;
  for (int i = 0; i < n; i++) f[0][i] = rnd(mod);
  for (int i = 0; i < n; i++) h[i] = rnd(mod);
  vector<long long> g(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    int t = i & 1;
    if (i) {
      memset(f[t], 0, sizeof(f[t]));
      for (auto j : v) f[t][j.first] -= f[t ^ 1][j.second];
      for (int j = 0; j < n; j++)
        f[t][j] = (f[t][j] + f[t ^ 1][j] * d[j]) % mod * hh[j] % mod + mod;
    }
    for (int j = 0; j < n; j++) {
      g[i] += h[j] * f[t][j];
      if (g[i] >= mod2) g[i] -= mod2;
    }
    g[i] %= mod;
  }
  g = BM(g);
  if (g.size() == n)
    return g[n - 1] * ksm(sum, mod - 2) % mod;
  else
    exit(0);
}
long long getdet(int n, vector<pair<int, int> > &v) {
  if (!n) return 1;
  return (solve(n, v) * ((n & 1) ? 1 : -1) + mod) % mod;
}
int main() {
  int n = read(), k = read();
  vector<pair<int, int> > v;
  for (int i = 1; i < k; i++) {
    for (int j = 0; j < i; j++) {
      if (i + 1 < n) {
        v.push_back(make_pair(i, j));
        v.push_back(make_pair(j, i));
      }
      d[i]++;
      d[j]++;
    }
  }
  for (int i = k; i < n; i++) {
    for (int j = 0; j < k; j++) {
      int t = read() - 1;
      if (i + 1 < n) {
        v.push_back(make_pair(i, t));
        v.push_back(make_pair(t, i));
      }
      d[i]++;
      d[t]++;
    }
  }
  cout << getdet(n - 1, v) << endl;
}
