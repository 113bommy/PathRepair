#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
inline int getint() {
  char c = getchar();
  int x = 0, mi = 1;
  while (c != EOF && c != '-' && !isdigit(c)) c = getchar();
  if (c == '-') {
    mi = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x * mi;
}
inline long long getll() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline double getdb() {
  static double x;
  scanf("%lf", &x);
  return x;
}
string getstr() {
  string s;
  char c;
  do {
    c = getchar();
  } while ((c == ' ' || c == '\r' || c == '\n') && c != EOF);
  if (c == EOF) return s;
  do {
    s.push_back(c);
    c = getchar();
  } while (c != ' ' && c != '\n' && c != '\r' && c != EOF);
  return s;
}
bool readingFail = false;
string getline() {
  string s;
  char c;
  while ((c = getchar()) != '\n' && c != '\r' && c != EOF) s.push_back(c);
  if (c == EOF) {
    readingFail = true;
    return s;
  }
  while (!s.empty() && (s.back() == '\n' || s.back() == '\r')) s.pop_back();
  return s;
}
void sc(char* const& x) { scanf("%s", x); }
void sc(int& x) { scanf("%d", &x); }
void sc(long long& x) { scanf("%lld", &x); }
void sc(double& x) { scanf("%lf", &x); }
template <typename T, typename... Args>
void sc(T& v, Args&... args) {
  sc(v);
  sc(args...);
}
void pr(const char* const& s) { printf("%s", s); }
void pr(char* const& s) { printf("%s", s); }
void pr(char const& x) { printf("%c", x); }
void pr(bool const& x) { printf("%d", x); }
void pr(int const& x) { printf("%d", x); }
void pr(long long const& x) { printf("%lld", x); }
void pr(double const& x) { printf("%.12f", x); }
void pr(long double const& x) { printf("%.12f", (double)x); }
template <typename T, typename... Args>
void pr(T const& v, Args const&... args) {
  pr(v);
  pr(' ');
  pr(args...);
}
template <typename... Args>
void prln(Args const&... args) {
  pr(args...);
  pr("\n");
}
template <typename T>
T gcd(T const& x, T const& y) {
  return abs(__gcd(x, y));
}
time_point<system_clock> timing;
void TBegin() { timing = system_clock::now(); }
double TEnd(const char* c = "time: ") {
  auto end = system_clock::now();
  auto d = duration_cast<microseconds>(end - timing);
  auto dt =
      double(d.count()) * microseconds::period::num / microseconds::period::den;
  printf("%s%.10f", c, dt);
  return dt;
}
void TTick(const char* c = "time:") {
  TEnd(c);
  TBegin();
}
void Fin() { freopen("in.txt", "r", stdin); }
template <typename T>
void updmax(
    T& a, T const& b, function<void(void)> f = [] {}) {
  if (a < b) {
    a = b;
    f();
  }
}
template <typename T>
void updmin(
    T& a, T const& b, function<void(void)> f = [] {}) {
  if (b < a) {
    a = b;
    f();
  }
}
template <typename T>
void fill(T a[], T v, int len) {
  for (decltype(0) i = 0, lim__lim = (len); i <= lim__lim; i++) a[i] = v;
}
template <typename T>
int descr(T* from, T* to) {
  sort(from, to);
  return (int)(unique(from, to) - from);
}
template <typename T>
int lbound(T* from, T* to, T const& val) {
  return (int)(lower_bound(from, to, val) - from);
}
template <typename T>
int ubound(T* from, T* to, T const& val) {
  return (int)(upper_bound(from, to, val) - from);
}
template <typename T>
void rmif(vector<T>& v, function<bool(T const&)> cond) {
  v.erase(remove_if(v.begin(), v.end(), cond), v.end());
}
template <typename T>
void rmif(set<T>& v, function<bool(T const&)> cond) {
  for (auto x = v.begin(); x != v.end();) {
    if (cond(*x))
      v.erase(x++);
    else
      ++x;
  }
}
template <typename T>
void rm(set<T>& v, T const& x) {
  while (v.find(x) != v.end()) v.erase(v.find(x));
}
template <typename T>
T sgn(T const& v) {
  return v < 0 ? -1 : v > 0 ? 1 : 0;
}
const int mxn = 305;
char c[mxn][mxn];
int main() {
  int n, m, k;
  sc(n, m, k);
  ;
  for (decltype(1) i = 1, lim__lim = (n); i <= lim__lim; i++) sc(c[i] + 1);
  auto inbound = [&](int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
  };
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  int cnt = 0;
  for (decltype(1) t = 1, lim__lim = (max(n, m)); t <= lim__lim; t++) {
    for (decltype(1) x = 1, lim__lim = (n); x <= lim__lim; x++)
      for (decltype(1) y = 1, lim__lim = (m); y <= lim__lim; y++)
        if (c[x][y] == '*') {
          bool able = true;
          for (decltype(0) h = 0, lim__lim = (3); h <= lim__lim; h++) {
            int cx = dx[h] * t + x;
            int cy = dy[h] * t + y;
            if (!inbound(cx, cy) || c[cx][cy] != '*') {
              able = false;
              break;
            }
          }
          if (able) {
            cnt++;
            if (cnt == k) {
              prln(x, y);
              for (decltype(0) h = 0, lim__lim = (3); h <= lim__lim; h++)
                prln(dx[h] * t + x, dy[h] * t + y);
              return 0;
            }
          }
        }
  }
  prln(-1);
  return 0;
}
