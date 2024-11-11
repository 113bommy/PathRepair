#include <bits/stdc++.h>
using namespace std;
const int maxint = INT_MAX;
int mod = 1000000007;
double eps = 1e-9;
inline int ctoi(const char c) { return c - '0'; }
inline char itoc(const int n) { return n + '0'; }
template <typename T>
inline bool in(T x, T l, T r) {
  return l <= x && x <= r;
}
inline int dtoi(const double d) { return int(round(d)); }
inline bool isint(double d) { return abs(d - dtoi(d)) < eps; }
template <typename T1, typename T2>
inline pair<T1, T2> mp(const T1 &a, const T2 &b) {
  return make_pair(a, b);
}
template <class T>
inline void srt(T &a) {
  sort(a.begin(), a.end());
}
template <class T1, class T2>
inline void srt(T1 &a, T2 comp) {
  sort(a.begin(), a.end(), comp);
}
template <class T1, typename T2>
inline int lbs(const T1 &a, const T2 k) {
  return lower_bound(a.begin(), a.end(), k) - a.begin();
}
template <class T1, typename T2>
inline int ubs(const T1 &a, const T2 k) {
  return upper_bound(a.begin(), a.end(), k) - a.begin();
}
template <class T1, class T2>
int count(T1 &a, T2 k) {
  return ubs(a, k) - lbs(a, k);
}
template <class T1, class T2>
int find(T1 &a, T2 k) {
  return count(a, k) ? lbs(a, k) : -1;
}
void expandStack(int size = 67108864) {
  char *p = (char *)malloc(size) + size;
  __asm__("movq %0, %%rsp\n" ::"r"(p));
}
namespace Infinity {
const char CR = '\n';
inline void write(const int n) { printf("%d", n); }
inline void write(const unsigned int n) { printf("%u", n); }
inline void write(const long long int n) { cout << n; }
inline void write(const unsigned long long int n) { cout << n; }
inline void write(const double a) { printf("%d", dtoi(a)); }
inline void writef(const double a, const int n = 15) { printf("%.*f", n, a); }
inline void writef(const long double a, const int n = 18) {
  cout << setprecision(n) << fixed << a;
}
inline void write(const char c) { printf("%c", c); }
inline void write(const char s[] = "") { printf("%s", s); }
inline void write(const string &s) { cout << s; }
inline void write(const pair<int, int> &p) {
  printf("%d %d", p.first, p.second);
}
inline void writes(const int *a, const int l, const int r) {
  for (int i = l; i <= r; i++) printf("%d ", a[i]);
}
template <unsigned int n>
inline void write(const int (&a)[n]) {
  for (unsigned int i = 0; i < n; i++) printf("%d ", a[i]);
}
template <class T>
inline void write(const T a) {
  for (__typeof a.begin() i = a.begin(); i != a.end(); i++) printf("%d ", *i);
}
inline void writeln() { write(CR); }
template <typename T>
inline void writeln(const T &a) {
  write(a);
  write(CR);
}
inline void writefln(const double a, int n) {
  printf("%.*f", n, a);
  write(CR);
}
inline void writefln(const long double a, int n = 18) {
  cout << setprecision(n) << fixed << a << endl;
}
inline void writesln(const int *a, const int l, const int r) {
  for (int i = l; i <= r; i++) printf("%d ", a[i]);
  writeln(CR);
}
template <class T>
inline void writelns(const T a) {
  for (__typeof a.begin() i = a.begin(); i != a.end(); i++) writeln(*i);
}
inline void writelnYN(bool b) { writeln(b ? "YES" : "NO"); }
inline void writelnyn(bool b) { writeln(b ? "Yes" : "No"); }
inline int read(int &n) { return scanf("%d", &n); }
inline int read(long long int &n) { return scanf("%I64d", &n); }
inline char getcc() {
  char c;
  do c = getchar();
  while (c == ' ' || c == '\n');
  return c;
}
inline int getint() {
  int n;
  read(n);
  return n;
}
inline long long int getll() {
  long long int n;
  read(n);
  return n;
}
inline double getdouble() {
  double n;
  scanf("%lf", &n);
  return n;
}
template <unsigned int n>
inline void reads(int (&a)[n]) {
  for (unsigned int i = 0; i < n; i++) a[i] = getint();
}
inline void reads(int *a, int l, int r) {
  for (int i = l; i <= r; i++) a[i] = getint();
}
inline void reads(vector<int> &v, int n) {
  v.clear();
  for (int i = 0; i < n; i++) v.push_back(getint());
}
inline vector<int> getints(int n) {
  vector<int> v;
  for (int i = 0; i < n; i++) v.push_back(getint());
  return v;
}
inline vector<pair<int, int> > getpairs(int n) {
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    int a = getint(), b = getint();
    v.push_back(pair<int, int>(a, b));
  }
  return v;
}
inline void read(string &str, const unsigned int size) {
  char s[size];
  scanf("%s", s);
  str = string(s);
}
inline string getstr(const unsigned int size = 1024) {
  string s;
  read(s, size + 1);
  return s;
}
inline string getln() {
  string s;
  getline(cin, s);
  return s;
}
}  // namespace Infinity
using namespace Infinity;
template <typename T>
inline void clr(T &a) {
  memset(a, 0, sizeof a);
}
template <typename T>
T gcd(T a, T b) {
  while (b) {
    T t = a % b;
    a = b;
    b = t;
  }
  return a;
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <typename T>
T exGcd(T a, T b, T &x, T &y) {
  T d = a;
  if (b) {
    d = exGcd(b, a % b, y, x);
    y -= a / b * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}
template <typename T>
T mps(T l, T r, T k) {
  return ((r - (r % k + k) % k) - (l + (k - l % k) % k)) / k + 1;
}
template <typename T>
T sgn(T a) {
  return a == 0 ? 0 : a > 0 ? 1 : -1;
}
long long int qpow(int a, int b, int c) {
  return b ? qpow(a * a % c, b >> 1, c) * (b & 1 ? a : 1) % c : 1;
}
class StringHash {
  static const int base = 2333;

 public:
  StringHash() : h(0), p(1) {}
  StringHash(string s) : StringHash() {
    for (char c : s) this->append(c);
  }
  void append(char c) {
    h = h * base + c;
    p *= base;
  }
  void prepend(char c) {
    h += c * p;
    p *= base;
  }
  bool operator==(StringHash h1) { return this->h == h1.h; }

 protected:
  unsigned int h;
  unsigned int p;
};
int main() {
  map<char, int> mp1({{'N', 0}, {'S', 1}, {'W', 2}, {'E', 3}});
  map<char, int> mp2({{'N', 1}, {'S', 0}, {'W', 3}, {'E', 2}});
  int n = getint() - 1;
  string s1, s2;
  cin >> s1 >> s2;
  bool flg = true;
  StringHash h1, h2;
  for (int i = n - 1; i >= 0; i--) {
    h1.prepend(mp1[s1[i]]);
    h2.append(mp2[s2[i]]);
    if (h1 == h2) {
      flg = false;
      break;
    }
  }
  writelnYN(flg);
  return 0;
}
