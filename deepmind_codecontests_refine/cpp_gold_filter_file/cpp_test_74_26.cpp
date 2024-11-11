#include <bits/stdc++.h>
namespace std {
template <typename...>
using void_t = void;
}
template <typename T, typename _ = void>
struct is_container : std::false_type {};
template <typename... Ts>
struct is_container_helper {};
template <typename T>
struct is_container<
    T, typename std::conditional<
           false,
           is_container_helper<decltype(std::declval<T>().size()),
                               decltype(std::declval<T>().begin()),
                               decltype(std::declval<T>().end()),
                               decltype(std::declval<T>().cbegin()),
                               decltype(std::declval<T>().cend())>,
           void>::type> : public std::true_type {};
class IO {
  static const int bufSize = 1 << 20;
  char inBuf[bufSize], outBuf[bufSize];
  char *ip1 = inBuf, *ip2 = inBuf;
  int goodReadBit = 1, op1 = -1, op2 = bufSize - 1;
  __inline__ __attribute__((always_inline)) int gc() {
    return ip1 == ip2 && (ip2 = (ip1 = inBuf) + fread(inBuf, 1, bufSize, stdin),
                          ip1 == ip2)
               ? (goodReadBit = 0, EOF)
               : *ip1++;
  }
  template <typename T>
  __inline__ __attribute__((always_inline)) void __RI(T &x) {
    int ch = gc(), neg = 1;
    x = 0;
    for (; !(isdigit(ch) || ch == '-' || ch == EOF); ch = gc()) {
    }
    if (ch == EOF) return;
    if (ch == '-') neg = -1, ch = gc();
    for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - 48) * neg;
  }
  template <typename T>
  __inline__ __attribute__((always_inline)) void __RC(T &x) {
    int ch;
    while (isspace(ch = gc())) {
    }
    if (ch == EOF) return;
    x = ch;
  }
  __inline__ __attribute__((always_inline)) void __RS(std::string &x) {
    char ch;
    x.clear();
    for (ch = gc(); isspace(ch); ch = gc()) {
    }
    if (ch == EOF) return;
    for (; !isspace(ch) && ch != EOF; ch = gc()) x.push_back(ch);
  }

 public:
  __inline__ __attribute__((always_inline)) IO &R(char &x) {
    return __RC(x), (*this);
  }
  __inline__ __attribute__((always_inline)) IO &R(unsigned char &x) {
    return __RC(x), (*this);
  }
  __inline__ __attribute__((always_inline)) IO &R(std::string &x) {
    return __RS(x), (*this);
  }
  template <typename T1, typename T2>
  __inline__ __attribute__((always_inline)) IO &R(std::pair<T1, T2> &x) {
    return R(x.first), R(x.second), (*this);
  }
  template <typename T, typename... Args>
  __inline__ __attribute__((always_inline)) IO &RA(T *a, int n) {
    for (int i = 0; i < n; ++i) R(a[i]);
    return (*this);
  }
  template <typename T, typename... Args>
  __inline__ __attribute__((always_inline)) IO &R(T &x, Args &...args) {
    return R(x), R(args...), (*this);
  }
  template <typename T, typename... Args>
  __inline__ __attribute__((always_inline)) IO &RA(T *a, int n, Args... args) {
    for (int i = 0; i < n; ++i) RA(a[i], args...);
    return (*this);
  }
  template <typename T>
  __inline__ __attribute__((always_inline))
  typename std::enable_if<std::is_integral<T>::value, IO>::type &
  R(T &x) {
    return __RI(x), (*this);
  }
  template <typename T>
  __inline__ __attribute__((always_inline))
  typename std::enable_if<is_container<T>::value, IO>::type &
  R(T &x) {
    for (auto &i : x) R(i);
    return (*this);
  }
  template <typename T>
  __inline__ __attribute__((always_inline)) typename std::enable_if<
      std::is_void<std::void_t<decltype(std::declval<T>().read())>>::value,
      IO>::type &
  R(T &x) {
    return x.read(), (*this);
  }

 private:
  char space = ' ';
  __inline__ __attribute__((always_inline)) void pc(const char &x) {
    if (op1 == op2) flush();
    outBuf[++op1] = x;
  }
  template <typename T>
  __inline__ __attribute__((always_inline)) void __WI(T x) {
    static char buf[sizeof(T) * 16 / 5];
    static int len = -1;
    if (x >= 0) {
      do {
        buf[++len] = x % 10 + 48, x /= 10;
      } while (x);
    } else {
      pc('-');
      do {
        buf[++len] = -(x % 10) + 48, x /= 10;
      } while (x);
    }
    while (len >= 0) {
      pc(buf[len]), --len;
    }
  }

 public:
  __inline__ __attribute__((always_inline)) void flush() {
    fwrite(outBuf, 1, op1 + 1, stdout), op1 = -1;
  }
  __inline__ __attribute__((always_inline)) IO &W(const char &x) {
    return pc(x), (*this);
  }
  __inline__ __attribute__((always_inline)) IO &W(const char *x) {
    while (*x != '\0') pc(*(x++));
    return (*this);
  }
  __inline__ __attribute__((always_inline)) IO &W(const std::string &x) {
    return W(x.c_str()), (*this);
  }
  template <typename T1, typename T2>
  __inline__ __attribute__((always_inline)) IO &W(const std::pair<T1, T2> &x) {
    WS(x.first);
    W(x.second);
    return (*this);
  }
  __inline__ __attribute__((always_inline)) IO &WL() {
    return W('\n'), (*this);
  }
  template <typename T>
  __inline__ __attribute__((always_inline)) IO &WL(const T &x) {
    return W(x), W('\n'), (*this);
  }
  __inline__ __attribute__((always_inline)) IO &WS() {
    return W(space), (*this);
  }
  template <typename T>
  __inline__ __attribute__((always_inline)) IO &WS(const T &x) {
    return W(x), W(space), (*this);
  }
  template <typename T>
  __inline__ __attribute__((always_inline)) IO &WA(T *a, int n) {
    for (int i = 0; i < n; i++) WS(a[i]);
    WL();
    return (*this);
  }
  template <typename T, typename... Args>
  __inline__ __attribute__((always_inline)) IO &W(const T &x,
                                                  const Args &...args) {
    W(x), W(space), W(args...);
    return (*this);
  }
  template <typename T, typename... Args>
  __inline__ __attribute__((always_inline)) IO &WS(const T &x,
                                                   const Args &...args) {
    return W(x), W(space), W(args...), W(space), (*this);
  }
  template <typename... Args>
  __inline__ __attribute__((always_inline)) IO &WL(const Args &...args) {
    return W(args...), W('\n'), (*this);
  }
  template <typename T, typename... Args>
  __inline__ __attribute__((always_inline)) IO &WA(T *a, int n, Args... args) {
    for (int i = 0; i < n; i++) WA(a[i], args...);
    return (*this);
  }
  template <typename T>
  __inline__ __attribute__((always_inline))
  typename std::enable_if<std::is_integral<T>::value, IO>::type &
  W(const T &x) {
    return __WI(x), (*this);
  }
  template <typename T>
  __inline__ __attribute__((always_inline))
  typename std::enable_if<is_container<T>::value, IO>::type &
  W(const T &x) {
    for (auto &i : x) WS(i);
    WL();
    return (*this);
  }
  template <typename T>
  __inline__ __attribute__((always_inline)) typename std::enable_if<
      std::is_void<std::void_t<decltype(std::declval<T>().write())>>::value,
      IO>::type &
  W(const T &x) {
    return x.write(), (*this);
  }
  template <typename T>
  __inline__ __attribute__((always_inline)) IO &operator>>(T &x) {
    R(x);
    return (*this);
  }
  template <typename T>
  __inline__ __attribute__((always_inline)) IO &operator<<(const T &x) {
    W(x);
    return (*this);
  }
  int good() { return goodReadBit; }
  IO() {}
  ~IO() { flush(); }
} io;
const std::int32_t INF = 0x3f3f3f3f;
const std::int64_t INFL = 0x3f3f3f3f3f3f3f3f;
using namespace std;
vector<int> f(vector<int> a) {
  int tot = a[0] + a[1] + a[2];
  tot /= 2;
  return {tot - a[0], tot - a[1], tot - a[2]};
}
int popcount(int x) { return x == 0 ? 0 : __builtin_popcount(x); }
void solveOdd(vector<int> a) {
  int n = min(int(a.size()), 26);
  unordered_map<int, int> hs[20];
  for (int mask = 1; mask < (1 << n); mask++) {
    int l = popcount(mask);
    if (l <= n / 2) {
      int t = 0;
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) t += a[i];
      }
      if (hs[l].count(t)) {
        io.WL("YES");
        vector<int> ans;
        vector<int> x;
        vector<int> y;
        for (int i = 0; i < n; i++) {
          if (mask & (1 << i)) {
            x.push_back(a[i]);
          }
          if (hs[l][t] & (1 << i)) y.push_back(a[i]);
        }
        ans.push_back(0);
        for (int i = 1; i < x.size() * 2; i++) {
          if (i & 1)
            ans.push_back(x[i / 2] - ans.back());
          else
            ans.push_back(y[i / 2 - 1] - ans.back());
        }
        for (int i = 0; i < a.size(); i++) {
          if (i >= 26 || !((mask & (1 << i)) || (hs[l][t] & (1 << i))))
            ans.push_back(a[i]);
        }
        io.W(ans);
        return;
      } else
        hs[l][t] = mask;
    }
  }
  io.WL("NO");
}
int main() {
  int n;
  io >> n;
  vector<int> a(n);
  io >> a;
  if (n == 2) {
    io.WL(a[0] == a[1] ? "YES" : "NO");
    if (a[0] == a[1]) {
      io.WL(0, a[0]);
    }
    return 0;
  }
  set<int> s(a.begin(), a.end());
  if (s.size() < a.size()) {
    io.WL("YES");
    a.assign(s.begin(), s.end());
    io.WS(0, a[0]);
    for (int i = 1; i < a.size(); i++) io.WS(a[i] - a[0]);
    for (int i = a.size() + 1; i < n; i++) io.WS(0);
    io.WL();
    return 0;
  }
  if (n == 3) {
    if ((a[0] + a[1] + a[2]) & 1) {
      io.WL("NO");
      return 0;
    }
    io.WL("YES");
    io.W(f(a));
    return 0;
  }
  int cntOdd = 0;
  for (int i = 0; i < n; i++) {
    cntOdd += a[i] & 1;
  }
  if (cntOdd == n) {
    a.assign(s.begin(), s.end());
    solveOdd(a);
  } else {
    io.WL("YES");
    vector<int> x, y;
    for (int i = 0; i < n; i++) {
      (a[i] & 1 ? x : y).push_back(a[i]);
    }
    if (y.size() >= 3) {
      auto t = f({y[0], y[1], y[2]});
      for (int i = 3; i < y.size(); i++) t.push_back(y[i] - t[0]);
      for (int i = 0; i < x.size(); i++) t.push_back(x[i] - t[0]);
      io.W(t);
    } else {
      auto t = f({y[0], x[0], x[1]});
      for (int i = 1; i < y.size(); i++) t.push_back(y[i] - t[0]);
      for (int i = 2; i < x.size(); i++) t.push_back(x[i] - t[0]);
      io.W(t);
    }
  }
  return 0;
}
