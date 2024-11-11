#include <bits/stdc++.h>
using namespace std;
struct outFloat {
  int precision;
  long double value;
  outFloat(long double v, int p) : precision(p), value(v) {}
};
const int inf = 123456789;
const long long llInf = 123456789012345678;
const long double pi = 3.14159265358979323846;
const int maxN = 2000000;
int init() {
  ios_base::sync_with_stdio(0);
  srand(time(NULL));
  return 0;
}
int initializer = init();
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &p) {
  for (int i = 0; i < p.size(); i++) is >> p[i];
  return is;
}
class inputer {
 private:
  istream *istr;

 public:
  inputer(istream &is) : istr(&is) {}
  template <typename T>
  void get(T &n) {
    (*istr) >> n;
  }
  template <typename T, typename... Args>
  void get(T &n, Args &...args) {
    get(n);
    get(args...);
  }
  template <typename... Args>
  void getLn(Args &...args) {
    get(args...);
    getLn();
  }
  template <typename T>
  operator T() {
    T n;
    get(n);
    return n;
  }
  void getLn() {
    string s;
    getline(cin, s);
  }
  template <typename T>
  void getv(vector<T> &v, int size) {
    v.resize(size);
    (*istr) >> v;
  }
};
string delim = " ";
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << p.first << delim << p.second;
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &p) {
  for (int i = 0; i < p.size(); i++) {
    if (i != 0) os << delim;
    os << p[i];
  }
  return os;
}
ostream &operator<<(ostream &os, const outFloat &of) {
  os << setprecision(of.precision) << of.value;
  return os;
}
class outputer {
 private:
  ostream *ostr;

 public:
  outputer(ostream &os) : ostr(&os) {}
  template <typename T>
  void put(const T &n) {
    (*ostr) << n;
  }
  template <typename T, typename... Args>
  void put(const T &n, const Args &...args) {
    put(n);
    put(args...);
  }
  template <typename... Args>
  void putLn(const Args &...args) {
    put(args...);
    putLn();
  }
  template <typename T>
  outputer &operator=(const T &n) {
    put(n);
    return *this;
  }
  void putLn() { (*ostr) << "\n"; }
  template <typename T>
  void putv(vector<T> v, int size, string delim) {
    for (int i = 0; i < size; i++) {
      if (i != 0) (*ostr) << delim;
      (*ostr) << v[i];
    }
  }
};
inputer in(cin);
outputer out(cout);
char getChar() {
  char c = 0;
  while (c <= ' ') cin >> c;
  return c;
}
bool willItBeAC() {
  return true;
  ;
}
int getMyRating() { return 2121; }
bool prime(long long n) {
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
vector<long long> divs(long long n) {
  vector<long long> v;
  long long i = 2;
  while (i * i <= n)
    if (n % i == 0) {
      n /= i;
      v.push_back(i);
    } else
      i++;
  v.push_back(n);
  return v;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long extGcd(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1, d = extGcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
template <typename T>
class fenwick {
 private:
  vector<T> t;
  int n;

 public:
  fenwick(int nn) { init(nn); }
  void init(int nn) {
    n = nn;
    t.assign(n, 0);
  }
  T sum(int r) {
    T result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) result += t[r];
    return result;
  }
  void inc(int i, T delta) {
    for (; i < n; i = (i | (i + 1))) t[i] += delta;
  }
  T sum(int l, int r) { return sum(r) - sum(l - 1); }
  T get(int i) { return sum(i, i); }
  void put(int i, T v) { inc(i, v - sum(i, i)); }
  int size() { return n; }
};
int main() {
  long double px = in, py = in, vx = in, vy = in, a = in, b = in, c = in,
              d = in;
  long double k = sqrt(vy * vy + vx * vx);
  out.putLn(outFloat(px + vx * b / k, 10), ' ', outFloat(py + vy * b / k, 10));
  out.putLn(outFloat(px - vy * a / 2 / k, 10), ' ',
            outFloat(py + vx * a / 2 / k, 10));
  out.putLn(outFloat(px - vy * c / 2 / k, 10), ' ',
            outFloat(py + vx * c / 2 / k, 10));
  out.putLn(outFloat(px - vy * c / 2 / k - vx * d / k, 10), ' ',
            outFloat(py + vx * c / 2 / k - vy * d / k, 10));
  out.putLn(outFloat(px + vy * c / 2 / k - vx * d / k, 10), ' ',
            outFloat(py + vx * c / 2 / k - vy * d / k, 10));
  out.putLn(outFloat(px + vy * c / 2 / k, 10), ' ',
            outFloat(py + vx * c / 2 / k, 10));
  out.putLn(outFloat(px + vy * a / 2 / k, 10), ' ',
            outFloat(py + vx * a / 2 / k, 10));
  return 0;
}
