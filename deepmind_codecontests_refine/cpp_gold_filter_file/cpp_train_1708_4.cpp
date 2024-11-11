#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int INF = 1000001000;
const long long INFLL = INF * 1LL * INF;
const int mod = 1000 * 1000 * 1000 + 7;
const int mod9 = 1000 * 1000 * 1000 + 9;
const int modr = 99990001;
const long double PI = 3.1415926535897932385;
template <class T>
void zero(T val, T& first) {
  first = val;
}
template <class T, class... Targs>
void zero(T val, T& first, Targs&... Fargs) {
  first = val;
  zero(val, Fargs...);
}
template <class T, class T2>
std::istream& operator>>(std::istream& is, pair<T, T2>& p) {
  return is >> p.first >> p.second;
}
template <class T>
std::istream& readN(T& first, int n, int st = 0) {
  for (int i = st, iend = (st + n - 1); i <= iend; i++) cin >> first[i];
  return cin;
}
template <class T>
std::istream& readS(set<T>& first, int n) {
  T second = *first.rbegin();
  for (int i = 0, iend = (n - 1); i <= iend; i++) {
    cin >> second;
    first.insert(second);
  }
  return cin;
}
template <class T>
std::istream& read(T& first) {
  return cin >> first;
}
template <class T, class... Targs>
std::istream& read(T& first, Targs&... Fargs) {
  return read(first), read(Fargs...);
}
template <class T, class T2>
std::ostream& operator<<(std::ostream& os, pair<T, T2> p) {
  return os << p.first << " " << p.second;
}
template <class T>
std::ostream& operator<<(std::ostream& os, vector<T> v) {
  bool f = true;
  for (auto second : v) {
    if (!f) os << ' ';
    os << second;
    f = false;
  }
  return os;
}
template <class T>
std::ostream& operator<<(std::ostream& os, set<T> v) {
  bool f = true;
  for (auto second : v) {
    if (!f) os << ' ';
    os << second;
    f = false;
  }
  return os;
}
template <class T>
std::ostream& operator<<(std::ostream& os, multiset<T> v) {
  bool f = true;
  for (auto second : v) {
    if (!f) os << ' ';
    os << second;
    f = false;
  }
  return os;
}
template <class T, class T2>
std::ostream& operator<<(std::ostream& os, map<T, T2> v) {
  bool f = true;
  for (pair<T, T2> second : v) {
    if (!f) os << ' ';
    os << second.first << "=>" << second.second;
    f = false;
  }
  return os;
}
template <class T>
std::ostream& outV(T first, char del = ' ') {
  bool f = true;
  for (auto second : first) {
    if (!f) cout << del;
    cout << second;
    f = false;
  }
  return cout;
}
template <class T>
std::ostream& outN(T first, int n = -1, int st = 0) {
  for (int i = st, iend = (n == -1 ? (int)first.size() - 1 : st + n - 1);
       i <= iend; i++) {
    cout << first[i];
    if (i < iend) cout << ' ';
  }
  return cout;
}
template <class T>
std::ostream& outAN(T first, int n = -1, int st = 0) {
  for (int i = st, iend = (n - 1); i <= iend; i++) {
    cout << first[i];
    if (i < iend) cout << ' ';
  }
  return cout;
}
template <class T>
std::ostream& outA2(T first, int n, int m) {
  for (int i = 0, iend = (n - 1); i <= iend; i++) {
    for (int j = 0, jend = (m - 1); j <= jend; j++)
      cout << first[i][j] << (j == m - 1 ? '\n' : ' ');
  }
  return cout;
}
template <class T>
std::ostream& out(T first) {
  return cout << first;
}
template <class T, class... Targs>
std::ostream& out(T first, Targs... Fargs) {
  return out(first) << " ", out(Fargs...);
}
template <typename T>
void srt(T& a, int st, int fn, bool isArr) {
  sort(a + st, a + fn + 1);
}
template <class T>
void srt(T& a, int st = 0, int fn = 0) {
  sort(a.begin() + st, fn ? a.begin() + fn + 1 : a.end());
}
template <typename T>
T rev_num(T a) {
  T r = 0;
  for (; a; a /= 10) r = r * 10 + a % 10;
  return r;
}
template <typename T>
void rev(T& a, int st, int fn, bool isArr) {
  reverse(a + st, a + fn + 1);
}
template <class T>
void rev(T& a, int st = 0, int fn = 0) {
  reverse(a.begin() + st, fn ? a.begin() + fn + 1 : a.end());
}
long long sqr(long long a) { return a * a; };
long long sqr(int a) { return a * 1LL * a; };
long double sqr(long double a) { return a * a; };
long long sqDist(pair<long long, long long> first,
                 pair<long long, long long> second) {
  return sqr(first.first - second.first) + sqr(first.second - second.second);
}
long double dist(pair<long long, long long> first,
                 pair<long long, long long> second) {
  return sqrt(sqDist(first, second));
}
long long phi(int n) {
  int res = n;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      res -= res / i;
    }
  if (n > 1) res -= res / n;
  return res;
}
long long bpm(long long a, long long n = -2, long long m = mod) {
  n = n < 0 ? n + m : n;
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * a) % m;
    a = (a * a) % m;
    n >>= 1;
  }
  return r;
}
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
vector<int> ero_p, ero_l;
void ero(int n) {
  ero_l.resize(n + 1);
  ero_l[0] = -1;
  for (int i = 2, iend = (n); i <= iend; i++)
    if (!ero_l[i]) {
      ero_p.push_back(i);
      ero_l[i] = i;
      for (long long j = i * 1LL * i; j <= n; j += i) {
        ero_l[j] = i;
      }
    }
}
long long gcd_cb(long long a, long long b, long long& first,
                 long long& second) {
  if (!b) {
    first = 1;
    second = 0;
    return a;
  }
  long long x1, y1, g;
  g = gcd_cb(b, a % b, x1, y1);
  first = y1;
  second = x1 - a / b * y1;
  return g;
}
vector<long long> fact;
void fact_prec(int n = 20) {
  fact.resize(n + 1);
  fact[0] = 1;
  for (int i = 1, iend = (n); i <= iend; i++) {
    fact[i] = fact[i - 1] * i;
  }
}
vector<long double> factd;
void fact_precd(int n = 146) {
  factd.resize(n + 1);
  factd[0] = 1;
  for (int i = 1, iend = (n); i <= iend; i++) {
    factd[i] = factd[i - 1] * i;
  }
}
string str(long long a) {
  string r = "";
  for (; a; a /= 10) r += a % 10 + '0';
  rev(r);
  return r;
}
template <class T>
int bitc(T first) {
  int r = 0;
  for (T d = first; d > 0; d >>= 1) {
    r += d & 1;
  }
  return r;
}
int sum_num(long long n) {
  int d = 0;
  for (; n; n /= 10) d += n % 10;
  return d;
}
const int N = 400005;
map<pair<pair<int, int>, int>, pair<pair<int, int>, int> > pv;
set<pair<pair<int, int>, int> > used;
string s;
int m;
int n = 0;
bool ok = false;
pair<pair<int, int>, int> res = {{0, 0}, 0};
void get(int last, int bal, pair<pair<int, int>, int> pvp = {{0, 0}, 0}) {
  pair<pair<int, int>, int> cur = {{last, bal}, n};
  pv[cur] = pvp;
  if (n == m) {
    ok = true;
    res = cur;
    n--;
    return;
  }
  if (used.count(cur)) {
    n--;
    return;
  }
  used.insert(cur);
  int nwbal = bal;
  int mn = last > 0 ? -1 : 1;
  for (int i = 1, iend = (10); i <= iend; i++) {
    nwbal += mn;
    if (s[i - 1] == '1' && i != -mn * last && !ok) {
      if (nwbal * bal < 0 || !n) {
        n++;
        get(i * mn, nwbal, cur);
      }
    }
  }
  n--;
}
int main() {
  read(s, m);
  get(0, 0);
  puts(res.second ? "YES" : "NO");
  ;
  if (res.second != 0) {
    vector<int> ans;
    while (res.second) {
      ans.push_back(abs(res.first.first));
      res = pv[res];
    }
    rev(ans);
    out(ans) << "\n";
  }
  return 0;
}
