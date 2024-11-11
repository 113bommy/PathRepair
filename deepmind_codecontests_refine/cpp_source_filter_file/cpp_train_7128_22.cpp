#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T SQR(T x) {
  return x * x;
}
template <typename T>
inline void UPDATE_MIN(T &x, T y) {
  if (y < x) {
    x = y;
  }
}
template <typename T>
inline void UPDATE_MAX(T &x, T y) {
  if (x < y) {
    x = y;
  }
}
template <typename T>
inline int ARGMAX(T cont) {
  return max_element(cont.begin(), cont.end()) - cont.begin();
}
template <typename T>
inline int ARGMIN(T cont) {
  return min_element(cont.begin(), cont.end()) - cont.begin();
}
template <typename T>
inline int hamming(T x) {
  return __builtin_popcountll((long long)x);
}
int hamming(int x) { return __builtin_popcount(x); }
int hamming(long x) { return __builtin_popcountl(x); }
int hamming(long long x) { return __builtin_popcountll(x); }
vector<string> split(const string &s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
template <typename T, typename... Args>
inline string arrStr(T arr, int n) {
  stringstream s;
  s << "[";
  for (__typeof(n - 1) i = (0), __tmpvar__end89 = (n - 1); i < __tmpvar__end89;
       i++)
    s << arr[i] << ",";
  s << arr[n - 1] << "]";
  return s.str();
}
template <class T>
inline string TOSTR(const T &x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
inline void PR(void) {}
inline void PR(int x) { printf("%d", x); }
inline void PR(long long x) { printf("%lld", x); }
inline void PR(size_t x) { printf("%llu", (unsigned long long)x); }
inline void PR(const char *s) { printf("%s", s); }
inline void PR(double f) { printf("%.10f", f); }
inline void PR(long double f) { printf("%.10f", (double)f); }
template <typename T>
inline void PR(vector<T> &vec) {
  auto sz = vec.size();
  for (auto x : vec) {
    PR(x);
    (--sz) ? putc(0x20, stdout) : 0;
  }
}
template <typename T>
inline void PRS(T x) {
  PR(x);
  putc(0x20, stdout);
}
template <typename T>
inline void PRN(T x) {
  PR(x);
  putc(0x0a, stdout);
}
void PRN(void) { putc(0x0a, stdout); }
struct pairhash {
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};
const int MOD = 1000 * 1000 * 1000 + 7;
const double PI = 3.1415926535897932384626433832795l;
template <typename T>
inline T gcd(T a, T b) {
  return a ? gcd(b % a, a) : b;
}
inline void addto(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}
inline void subto(int &a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  if (a >= MOD) a -= MOD;
}
inline int sub(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  if (a >= MOD) a -= MOD;
  return a;
}
inline void multo(int &a, int b) { a = (long long)a * b % MOD; }
inline int mul(int a, int b) { return (long long)a * b % MOD; }
inline int mulmod(int a, int b, int mod) { return (long long)a * b % mod; }
inline int powmod(int a, int e, int mod) {
  int x;
  for (x = 1; e > 0; e >>= 1) {
    if (e & 1) x = mulmod(x, a, mod);
    a = mulmod(a, a, mod);
  }
  return x;
}
inline int invmod_prime(int a, int mod) { return powmod(a, mod - 2, mod); }
inline long long invmod_LL(long long p) {
  long long q = p;
  for (long long a = p * p; a != 1; a *= a) q *= a;
  return q;
}
int N, M, K, L, E, Q, SX, SY;
char m[2005][2005] = {};
char nei[2005][2005] = {};
inline bool valid(int x, int y) {
  return (0 <= x && x < SX) && (0 <= y && y < SY);
}
int main() {
  ios_base::sync_with_stdio(0);
  scanf("%d%d", &SY, &SX);
  for (__typeof(SY) y = (0), __tmpvar__end223 = (SY); y < __tmpvar__end223;
       y++) {
    {
      scanf("%s", m[y]);
      N = strlen(m[y]);
    };
  }
  for (__typeof(SY) y = (0), __tmpvar__end224 = (SY); y < __tmpvar__end224;
       y++) {
    for (__typeof(SX) x = (0), __tmpvar__end225 = (SX); x < __tmpvar__end225;
         x++) {
      if (m[y][x] == '.') {
        for (__typeof(2) dx = (-1), __tmpvar__end227 = (2);
             dx < __tmpvar__end227; dx++)
          for (__typeof(2) dy = (-1), __tmpvar__end227 = (2);
               dy < __tmpvar__end227; dy++) {
            if (dx && dy) continue;
            if (!(dx || dy)) continue;
            if (valid(x + dx, y + dy) && m[y + dy][x + dx] == '.') {
              nei[y + dy][x + dx]++;
            }
          }
      }
    }
  }
  deque<pair<int, int>> q;
  for (__typeof(SY) y = (0), __tmpvar__end238 = (SY); y < __tmpvar__end238; y++)
    for (__typeof(SX) x = (0), __tmpvar__end238 = (SX); x < __tmpvar__end238;
         x++) {
      if (m[y][x] == '*') continue;
      if (nei[y][x] == 0) {
        printf("Not unique 1");
        exit(0);
      };
      if (nei[y][x] == 1) q.push_back({y, x});
    }
  while (q.size()) {
    auto p = q.front();
    q.pop_front();
    int y = p.first;
    int x = p.second;
    if (nei[y][x] != 1) {
      printf("Not unique 2");
      exit(0);
    };
    for (__typeof(2) dx = (-1), __tmpvar__end249 = (2); dx < __tmpvar__end249;
         dx++)
      for (__typeof(2) dy = (-1), __tmpvar__end249 = (2); dy < __tmpvar__end249;
           dy++) {
        if (dx && dy) continue;
        if (!(dx || dy)) continue;
        if (valid(x + dx, y + dy) && m[y + dy][x + dx] == '.') {
          if (dx == -1) {
            m[y][x] = '>';
            m[y + dy][x + dx] = '<';
          }
          if (dx == 1) {
            m[y][x] = '<';
            m[y + dy][x + dx] = '>';
          }
          if (dy == -1) {
            m[y][x] = 'v';
            m[y + dy][x + dx] = '^';
          }
          if (dy == 1) {
            m[y][x] = '^';
            m[y + dy][x + dx] = 'v';
          }
          1;
          for (__typeof(2) Dx = (-1), __tmpvar__end270 = (2);
               Dx < __tmpvar__end270; Dx++)
            for (__typeof(2) Dy = (-1), __tmpvar__end270 = (2);
                 Dy < __tmpvar__end270; Dy++) {
              if (Dx && Dy) continue;
              if (!(Dx || Dy)) continue;
              int x2 = x + dx + Dx;
              int y2 = y + dy + Dy;
              if (valid(x2, y2) && m[y2][x2] == '.') {
                nei[y2][x2]--;
                if (nei[y2][x2] == 1) {
                  q.push_back({y2, x2});
                }
              }
            }
        }
      }
  }
  for (__typeof(SY) y = (0), __tmpvar__end285 = (SY); y < __tmpvar__end285;
       y++) {
    1;
  }
  1;
  1;
  for (__typeof(SY) y = (0), __tmpvar__end288 = (SY); y < __tmpvar__end288; y++)
    for (__typeof(SX) x = (0), __tmpvar__end288 = (SX); x < __tmpvar__end288;
         x++) {
      1;
      if (m[y][x] == '.') {
        printf("Not unique 3");
        exit(0);
      };
    }
  for (__typeof(SY) y = (0), __tmpvar__end292 = (SY); y < __tmpvar__end292;
       y++) {
    puts(m[y]);
  }
  return 0;
}
