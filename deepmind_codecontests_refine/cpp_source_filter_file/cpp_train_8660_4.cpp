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
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = (0); i < (n); ++i) cin >> s[i];
  if (s[n - 1][m - 1] == 'R') {
    cout << 0 << "\n";
    return;
  }
  vector<vector<int> > row(n, vector<int>(m));
  vector<vector<int> > col(n, vector<int>(m));
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) {
      if (i) {
        col[i][j] += col[i - 1][j];
      }
      if (j) {
        row[i][j] += row[i][j - 1];
      }
      row[i][j] += s[i][j] == '.';
      col[i][j] += s[i][j] == '.';
    }
  auto calc_right = [&](int u, int v) { return row[u][m - 1] - row[u][v]; };
  auto calc_down = [&](int u, int v) { return col[n - 1][v] - col[u][v]; };
  auto updfen = [&](vector<int>& fen, int p, int val) {
    p++;
    for (; p < int((fen).size()); p += p & -p) {
      addmod(fen[p], val);
    }
  };
  auto queryfen = [&](vector<int>& fen, int p) {
    p++;
    int res = 0;
    for (; 0 < p; p -= p & -p) {
      addmod(res, fen[p]);
    }
    return res;
  };
  int res = 0;
  vector<vector<int> > fens(m, vector<int>(n + 1));
  int x = calc_right(0, 0);
  for (int i = (0); i < (x + 1); ++i) {
    int y = calc_down(0, i);
    updfen(fens[i], 1, 1);
    updfen(fens[i], y + 1, MOD - 1);
  }
  if (n == 1) {
    if (x == m - 1) {
      addmod(res, 1);
    }
  }
  for (int i = (1); i < (n); ++i) {
    vector<int> fen(m + 1);
    auto upd = [&](int p, int val) {
      p++;
      for (; p < int((fen).size()); p += p & -p) {
        addmod(fen[p], val);
      }
    };
    auto query = [&](int p) {
      p++;
      int res = 0;
      for (; 0 < p; p -= p & -p) {
        addmod(res, fen[p]);
      }
      return res;
    };
    for (int j = (0); j < (m); ++j) {
      int t = queryfen(fens[j], i);
      int x = calc_right(i, j);
      upd(i + 1, t);
      upd(i + x + 1, (MOD - t) % MOD);
    }
    if (i == n - 1) {
      addmod(res, query(m - 1));
    }
    for (int j = (0); j < (m); ++j) {
      int t = query(j);
      int y = calc_down(i, j);
      updfen(fens[j], i + 1, t);
      updfen(fens[j], i + y + 1, (MOD - t) % MOD);
    }
  }
  addmod(res, queryfen(fens[m - 1], n - 1));
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
  solve();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
