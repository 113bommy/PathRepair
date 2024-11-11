#include <bits/stdc++.h>
using namespace std;
const int MOD = 119 << 23 | 1;
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
void chemthan() {
  int n;
  cin >> n;
  vector<vector<int> > adj(n);
  for (int i = (0); i < (n - 1); ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v), adj[v].push_back(u);
  }
  vector<vector<int> > dp(n, vector<int>(5));
  function<void(int, int)> dfs = [&](int u, int p) {
    dp[u][0] = 1;
    vector<int> x, y, z, t;
    x.push_back(1);
    for (int v : adj[u]) {
      if (v ^ p) {
        dfs(v, u);
        dp[u][0] = mult(dp[u][0], dp[v][1] + dp[v][2]);
        x.push_back((dp[v][1] + dp[v][2]) % MOD);
        y.push_back((dp[v][0] + dp[v][1]) % MOD);
        z.push_back((dp[v][1] + dp[v][2]) % MOD);
        t.push_back(((long long)dp[v][1] + dp[v][2] + dp[v][4]) % MOD);
      }
    }
    y.push_back(1), z.push_back(1), t.push_back(1);
    for (int i = (1); i < (int((x).size())); ++i) x[i] = mult(x[i], x[i - 1]);
    for (int i = (int((y).size()) - 1) - 1; i >= (0); --i)
      y[i] = mult(y[i], y[i + 1]);
    for (int i = (int((z).size()) - 1) - 1; i >= (0); --i)
      z[i] = mult(z[i], z[i + 1]);
    for (int i = (int((t).size()) - 1) - 1; i >= (0); --i)
      t[i] = mult(t[i], t[i + 1]);
    int ptr = 0, flag = 0;
    for (int v : adj[u]) {
      if (v ^ p) {
        ptr++;
        if (!flag) {
          addmod(dp[u][1], mult(x[ptr - 1], mult(t[ptr], dp[v][3])));
        } else {
          addmod(dp[u][3], mult(x[ptr - 1], mult(t[ptr], dp[v][3])));
          addmod(dp[u][4], mult(x[ptr - 1], mult(y[ptr], dp[v][3])));
        }
      } else {
        flag = 1;
        addmod(dp[u][2], mult(x[ptr], t[ptr]));
        addmod(dp[u][3], mult(x[ptr], z[ptr]));
      }
    }
  };
  dfs(0, -1);
  int res = 0;
  addmod(res, dp[0][0]);
  addmod(res, dp[0][1]);
  cout << res << "\n";
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
