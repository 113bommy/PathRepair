#include <bits/stdc++.h>
using namespace std;
struct ofl {
  long double value;
  int precision;
  inline ofl(long double value, int precision)
      : value(value), precision(precision) {}
};
const int seed = hash<string>()("alex256");
const int inf = (int)1e9 + 7;
const int64_t llInf = (int64_t)2e18 + 256;
const int mod = (int)1e9 + 7;
const long double pi = 3.141592653589793238462643383279502884197169399375105821;
const string luck = "🍀";
const char* errText = "error :(";
template <typename T1, typename T2>
inline istream& operator>>(istream& is, pair<T1, T2>& p) {
  return is >> p.first >> p.second;
}
template <typename T1, typename T2>
inline ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << p.first << " " << p.second;
}
template <typename T>
inline istream& operator>>(istream& is, vector<T>& v) {
  for (int i = 0; i < (int)(v.size()); i++) {
    is >> v[i];
  }
  return is;
}
template <typename T>
inline ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0; i < (int)(v.size()); i++) {
    if (i) {
      os << " ";
    }
    os << v[i];
  }
  return os;
}
inline ostream& operator<<(ostream& os, const ofl& o) {
  return os << fixed << setprecision(o.precision) << o.value;
}
inline bool iosOptimize() {
  ios_base::sync_with_stdio(false);
  return true;
}
bool iosOptimized = iosOptimize();
template <typename T>
inline T get() {
  T value;
  cin >> value;
  return value;
}
template <>
inline char get() {
  char c = '\0';
  while (c <= ' ') {
    cin >> c;
  }
  return c;
}
inline string getLn() {
  string s;
  getline(cin, s);
  return s;
}
template <typename T, size_t Count>
struct VectorPacker {};
template <typename T>
struct VectorPacker<T, 0> {};
template <typename T>
inline vector<T> getVector(int size) {
  vector<T> res(size);
  cin >> res;
  return res;
}
template <typename T, typename U, typename... Args>
inline typename VectorPacker<T, sizeof...(Args) + 1>::T getVector(
    U size, Args... sizes) {
  typename VectorPacker<T, sizeof...(Args) + 1>::T res(size);
  for (int i = 0; i < (int)size; i++) {
    res[i] = getVector<T>(sizes...);
  }
  return res;
}
inline void put() {}
template <typename T, typename... Args>
inline void put(const T& value, const Args&... vals) {
  cout << value;
  put(vals...);
}
template <typename... Args>
inline void putLn(const Args&... vals) {
  put(vals...);
  cout << "\n";
}
namespace std {
template <typename T1, typename T2>
struct hash<pair<T1, T2> > {
  inline size_t operator()(const pair<T1, T2>& p) const {
    return hash<T1>()(p.first) ^ hash<T2>()(p.second);
  }
};
};  // namespace std
mt19937_64 rnd(seed);
inline void error(const char* text = errText) {
  ;
  exit(256);
}
template <typename T1, typename T2>
inline void umax(T1& a, const T2& b) {
  if (a < b) {
    a = b;
  }
}
template <typename T1, typename T2>
inline void umin(T1& a, const T2& b) {
  if (a > b) {
    a = b;
  }
}
int64_t gcd(int64_t a, int64_t b) { return b ? gcd(b, a % b) : a; }
int64_t extGcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
  if (!a) {
    x = 0;
    y = 1;
    return b;
  }
  int64_t x1, y1, d = extGcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
inline int addMod(int a, int b, int m = mod) { return ((int64_t)a + b) % m; }
inline int subMod(int a, int b, int m = mod) {
  return ((int64_t)a + m - b) % m;
}
inline int mulMod(int a, int b, int m = mod) { return ((int64_t)a * b) % m; }
inline int divMod(int a, int b, int m = mod) {
  int64_t x, y;
  int64_t g = extGcd(b, m, x, y);
  if (g != 1) {
    ;
    exit(42);
  }
  x = (x % m + m) % m;
  return mulMod(a, x, m);
}
int n = get<int>();
string s = get<string>();
int dp[80][80][80][3];
signed main() {
  vector<int> q(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'V') {
      q[i] = 0;
    } else if (s[i] == 'K') {
      q[i] = 1;
    } else {
      q[i] = 2;
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        for (int l = 0; l < n; l++) {
          dp[i][j][k][l] = inf;
        }
      }
    }
  }
  int ans = inf;
  dp[0][0][0][2] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        for (int l = 0; l < 3; l++) {
          if (i + j + k == n) {
            umin(ans, dp[i][j][k][l]);
          }
          if (dp[i][j][k][l] == inf) {
            continue;
          }
          int ktr[3] = {i, j, k};
          int add[3] = {i, j, k};
          int beforeThis = 0;
          for (int m = 0; m < n; m++) {
            int qur = q[m];
            if (ktr[qur] == 0) {
              if (!(l == 0 && qur == 1)) {
                add[qur]++;
                umin(dp[add[0]][add[1]][add[2]][qur],
                     dp[i][j][k][l] + beforeThis);
                add[qur]--;
              }
              beforeThis++;
            } else {
              ktr[qur]--;
            }
          }
        }
      }
    }
  }
  putLn(ans);
  return 0;
}
