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
inline long double getdb() {
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
string getline() {
  string s;
  char c;
  do {
    c = getchar();
  } while ((c == '\r' || c == '\n') && c != EOF);
  if (c == EOF) return s;
  do {
    s.push_back(c);
    c = getchar();
  } while (c != '\n' && c != '\r' && c != EOF);
  return s;
}
void sc(char* x) { scanf("%s", x); }
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
void rmif(vector<T>& v, function<bool(T)> cond) {
  v.erase(remove_if(v.begin(), v.end(), cond), v.end());
}
template <typename T>
void rmif(set<T>& v, function<bool(T)> cond) {
  for (auto x = v.begin(); x != v.end();) {
    if (cond(*x))
      v.erase(x++);
    else
      ++x;
  }
}
using px = pair<int, pair<int, int>>;
int main() {
  int n, m, k;
  sc(n, m, k);
  ;
  vector<px> ans;
  set<px> a, s;
  for (decltype(1) i = 1, lim__lim = (n); i <= lim__lim; i++) {
    px g;
    sc(g.first, g.second.first);
    g.second.second = i;
    a.insert(g);
  }
  int dmg = 0, t = 0, c = m;
  while (true) {
    t++;
    c -= dmg;
    c = min(m, c + k);
    if (c <= 0) break;
    for (auto& i : a)
      if (i.first * m >= c * 100)
        s.insert(px{i.second.first, {i.first, i.second.second}});
    rmif<px>(a, [&](px x) { return x.first * m >= c * 100; });
    if (dmg <= k && s.size() == 0) {
      prln("NO");
      return 0;
    }
    if (s.empty()) continue;
    auto iter = prev(s.end());
    dmg += iter->first;
    ans.push_back(px{t, {iter->second.second, 0}});
    s.erase(iter);
  }
  prln("YES");
  prln(t - 1, (int)ans.size());
  for (auto& i : ans) prln(i.first - 1, i.second.first);
  return 0;
}
