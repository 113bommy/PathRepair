#include <bits/stdc++.h>
#pragma optimise GCC(-O2)
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
long long rng(long long lim) {
  uniform_int_distribution<long long> uid(0, lim - 1);
  return uid(rang);
}
long long INF = LLONG_MAX;
const long long M = 1000000007, M2 = 998244353, M3 = 2013265921;
long long powm(long long, long long, long long);
long long modI(long long, long long);
long long PrimRoot(long long p, long long x);
void fft(vector<long long>& a, long long n, bool invert, long long m,
         long long x);
void PolyMult(vector<long long>& a, vector<long long>& b, vector<long long>& v,
              long long m, long long x);
vector<vector<long long>> g;
long long foo(long long x, long long y) { return x + 100 * y; }
vector<long long> col, vis;
void dfs(long long x) {
  vis[x] = 1;
  for (auto xx : g[x])
    if (!vis[xx]) dfs(xx);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  if (n <= 13) {
    vector<long long> tor(1, 0);
    for (long long i = 1; i < n + 1; i++) {
      cout << "? 1 " << i << endl;
      long long x;
      cin >> x;
      tor.push_back(x);
    }
    cout << "! ";
    for (long long i = 1; i < n + 1; i++) {
      long long a = 0;
      for (long long j = 1; j < n + 1; j++)
        if (i != j) a |= tor[j];
      cout << a << " ";
    }
    cout << endl;
    return 0;
  }
  long long mask[n + 1];
  long long ct = n;
  long long counter = 1;
  while (ct) {
    if (__builtin_popcountll(counter) == 4) {
      mask[ct--] = counter;
    }
    counter++;
  }
  long long ans[13];
  memset(ans, 0, 13);
  vector<set<long long>> vs;
  long long curram_madarchod = 13;
  for (long long que = 0; que < 13; que++) {
    set<long long> foo;
    for (long long i = 1; i < n + 1; i++)
      if (mask[i] & (1 << que)) foo.insert(i);
    if (!foo.size()) {
      curram_madarchod = que;
      break;
    }
    vs.push_back(foo);
    cout << "? " << foo.size() << " ";
    for (auto x : foo) cout << x << " ";
    cout << endl;
    cin >> ans[que];
  }
  vector<long long> bencho;
  for (long long j = 1; j < n + 1; j++) {
    long long anss = 0;
    long long eta = mask[j];
    for (long long i = 0; i < curram_madarchod; i++) {
      if (vs[i].find(j) == vs[i].end()) {
        anss |= ans[i];
      }
    }
    bencho.push_back(anss);
  }
  cout << "! ";
  for (long long i = 0; i < n; i++) cout << bencho[i] << " ";
  cout << endl;
}
long long powm(long long a, long long b, long long c = M) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % c;
    a = (a * a) % c;
    b >>= 1;
  }
  return res;
}
long long modI(long long a, long long m = M) {
  long long m0 = m, y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m;
    a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long PrimRoot(long long p, long long x) {
  vector<long long> v;
  long long t = p - 1;
  for (long long i = 2; i * i <= t; i++)
    if (t % i == 0) {
      v.push_back((p - 1) / i);
      while (t % i == 0) t /= i;
    }
  if (t > 1) v.push_back((p - 1) / t);
  for (long long i = x + 1; i < p; i++) {
    long long flag = 0;
    for (auto x : v)
      if (powm(i, x, p) == 1) {
        flag = 1;
        break;
      }
    if (flag == 0) return i;
  }
  return 0;
}
void fft(vector<long long>& a, long long n, bool invert, long long m,
         long long x) {
  long long lg_n = __builtin_ctzll(n);
  for (long long i = 0, y = 0; i < n; i++) {
    for (long long j = 0; j < lg_n; j++)
      if ((1LL << j) & i) y |= (1LL << (lg_n - j - 1));
    if (y > i) swap(a[i], a[y]);
  }
  if (invert) x = modI(x, m);
  for (long long s = 2; s <= n; s <<= 1) {
    long long y = powm(x, (n / s), m);
    for (long long j = 0; j < (n / s); j++) {
      long long r = 1;
      for (long long i = 0; i < s / 2; i++) {
        long long u = a[i + j * s], v = (r * a[i + j * s + (s / 2)]) % m;
        a[i + j * s] = (u + v) % m;
        a[i + j * s + (s / 2)] = (u - v + m) % m;
        r = r * y % m;
      }
    }
  }
  if (invert) {
    long long invn = modI(n, m);
    for (long long i = 0; i < n; i++) a[i] = (a[i] * invn) % m;
  }
  return;
}
void PolyMult(vector<long long>& a, vector<long long>& b, vector<long long>& v,
              long long m, long long x) {
  long long n = 1;
  while (n < ((long long)a.size()) + ((long long)b.size())) n <<= 1;
  vector<long long> fa(a.begin(), a.end());
  fa.resize(n, 0);
  vector<long long> fb(b.begin(), b.end());
  fb.resize(n, 0);
  long long y = powm(x, (m - 1) / n, m);
  fft(fa, n, false, m, y);
  fft(fb, n, false, m, y);
  v.resize(n, 0);
  for (long long i = 0; i < n; i++) v[i] = ((fa[i] * fb[i]) % m);
  fft(v, n, true, m, y);
  return;
}
