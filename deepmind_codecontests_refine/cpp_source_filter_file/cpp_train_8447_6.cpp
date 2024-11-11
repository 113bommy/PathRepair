#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool uax(T &x, T y) {
  return (y > x) ? x = y, true : false;
}
template <typename T>
inline bool uin(T &x, T y) {
  return (y < x) ? x = y, true : false;
}
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
template <typename A>
string to_string(A);
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ": " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool f = false;
  string r = "{";
  for (auto x : v) {
    if (f) r += ", ";
    r += to_string(x);
    f = true;
  }
  return r += "}";
}
template <typename A>
string to_string(vector<vector<A>> v) {
  string r;
  for (auto x : v) r += "\n" + to_string(x);
  return r;
}
int Nerr;
template <typename A>
string to_string(A *p) {
  return to_string(vector<A>(p, p + Nerr));
}
void err(istream_iterator<string>) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " =: " << to_string(a) << "; ";
  err(++it, args...);
}
template <typename T>
void kek(T ans) {
  cout << ans << endl;
  exit(0);
}
int const MOD = 1e9 + 7;
long long const INF = 1e18 + 42;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (auto &b : a)
    for (int &x : b) cin >> x;
  vector<int> row(n), col(m);
  auto run = [&]() {
    for (int i = 1; i < n; ++i) {
      int sum = 0;
      for (int j = 0; j < m; ++j) sum += a[i][j] ^ col[j];
      if (sum % m) return;
      row[i] = sum == 0;
    }
    cout << "YES\n";
    for (int x : row) cout << x;
    cout << '\n';
    for (int x : col) cout << x;
    cout << '\n';
    exit(0);
  };
  auto run2 = [&]() {
    int pos = -1;
    for (int i = 1; i < n; ++i) {
      int sum = 0;
      for (int j = 0; j < m; ++j) sum += a[i][j] ^ col[j];
      if (sum % m) {
        if (pos != -1) return;
        pos = i;
        int ok = 1;
        for (row[i] = 0; row[i] < 2; ++row[i]) {
          ok = 1;
          for (int j = 1; j < m && ok; ++j) {
            ok &= (a[i][j] ^ col[j] ^ row[i]) >
                  (a[i][j - 1] ^ col[j - 1] ^ row[i]);
          }
          if (ok) break;
        }
        if (!ok) return;
      } else {
        row[i] = sum == 0;
        if (pos == -1) row[i] ^= 1;
      }
    }
    cout << "YES\n";
    for (int x : row) cout << x;
    cout << '\n';
    for (int x : col) cout << x;
    cout << '\n';
    exit(0);
  };
  for (row[0] = 0; row[0] <= 1; ++row[0]) {
    if (row[0])
      for (int &x : a[0]) x ^= 1;
    for (int p = 0; p <= m; ++p) {
      for (int i = 0; i < m; ++i) {
        col[i] = (a[0][i] == (i < p));
      }
      run();
    }
    run2();
  }
  kek("NO");
}
