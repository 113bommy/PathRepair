#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int)1e9 + 23111992;
const long long LINF = (long long)1e18 + 23111992;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline unsigned long long isqrt(unsigned long long k) {
  unsigned long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() { return abs((int)mt()); }
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = (0); i < (n); ++i) cin >> a[i];
  auto func = [&](int k) {
    map<int, int> hs;
    int t = a[k];
    for (int i = 2; i * i <= t; i++) {
      while (t % i == 0) hs[i] = 1, t /= i;
    }
    if (1 < t) hs[t] = 1;
    vector<int> res;
    for (auto e : hs) {
      res.push_back(e.first);
    }
    return res;
  };
  auto fuck = [&](int k) {
    vector<int> v1 = func(0);
    vector<int> v2 = func(k);
    vector<int> ver;
    for (auto x : v1) {
      int total = 0;
      for (int i = (0); i < (n); ++i)
        if (i && i != k && a[i] % x) {
          total++;
          if (total == 10) {
            break;
          }
          ver.push_back(i);
        }
    }
    for (auto x : v2) {
      int total = 0;
      for (int i = (0); i < (n); ++i)
        if (i && i != k && a[i] % x) {
          total++;
          if (total == 10) {
            break;
          }
          ver.push_back(i);
        }
    }
    sort((ver).begin(), (ver).end()),
        (ver).erase(unique((ver).begin(), (ver).end()), (ver).end());
    int m = int((ver).size());
    vector<int> b(m), c(m);
    for (int i = (0); i < (m); ++i) {
      int u = ver[i];
      for (int j = (0); j < (int((v1).size())); ++j) {
        if (a[u] % v1[j]) {
          b[i] |= 1 << j;
        }
      }
      for (int j = (0); j < (int((v2).size())); ++j) {
        if (a[u] % v2[j]) {
          c[i] |= 1 << j;
        }
      }
    }
    static bool dp[200][1 << 9][1 << 9];
    static char ru[200][1 << 9][1 << 9];
    static char rv[200][1 << 9][1 << 9];
    int c1 = 1 << int((v1).size());
    int c2 = 1 << int((v2).size());
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = (0); i < (m); ++i) {
      for (int u = (0); u < (c1); ++u)
        for (int v = (0); v < (c2); ++v)
          if (dp[i][u][v]) {
            dp[i + 1][u | b[i]][v] = 1;
            ru[i + 1][u | b[i]][v] = u;
            rv[i + 1][u | b[i]][v] = v;
            dp[i + 1][u][v | c[i]] = 1;
            ru[i + 1][u][v | c[i]] = u;
            rv[i + 1][u][v | c[i]] = v;
          }
    }
    if (dp[m][c1 - 1][c2 - 1]) {
      vector<int> res(n);
      res[k] = 1;
      int x = c1 - 1, y = c2 - 1;
      for (int i = (m)-1; i >= (0); --i) {
        int nx = ru[i + 1][x][y];
        int ny = rv[i + 1][x][y];
        if (y == ny) {
        } else {
          res[ver[i]] = 1;
        }
        x = nx, y = ny;
      }
      cout << "YES\n";
      for (int i = (0); i < (n); ++i) cout << res[i] + 1 << " \n"[i == n - 1];
      exit(0);
    }
  };
  for (int i = (1); i < (min(n, 11)); ++i) {
    fuck(i);
  }
  cout << "NO\n";
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  solve();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
