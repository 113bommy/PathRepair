#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  while (a && b)
    if (a > b)
      a %= b;
    else
      b %= a;
  return a + b;
}
template <class T>
void sortf(vector<T> &v) {
  stable_sort(v.begin(), v.end());
}
template <class T>
void sortb(vector<T> &v) {
  stable_sort(v.rbegin(), v.rend());
}
template <class T>
T max3(T a, T b, T c) {
  return max(a, max(b, c));
}
template <class T>
T min3(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (T &t : v) in >> t;
  return in;
}
ostream &operator<<(ostream &out, const vector<char> &v) {
  for (const char &t : v) out << t;
  out << endl;
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  for (const T &t : v) out << t << ' ';
  return out;
}
static void init_iostream_speed() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
}
template <typename T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
template <class T>
void swap(T *a, T *b) {
  T c = *a;
  *a = *b;
  *b = c;
}
template <typename T>
class vector2 : public vector<T> {
 public:
  long long min_ind() {
    return min_element(this->begin(), this->end()) - this->begin();
  }
  long long max_ind() {
    return max_element(this->begin(), this->end()) - this->begin();
  }
  T min() { return *min_element(this->begin(), this->end()); }
  T max() { return *max_element(this->begin(), this->end()); }
  void sortf() { ::sortf(*this); }
  void sortb() { ::sortb(*this); }
  vector2() : vector<T>() {}
  vector2(vector<T> __v) : vector<T>(__v) {}
  vector2(initializer_list<T> __i_l) : vector<T>(__i_l) {}
  vector2(size_t __n, size_t __val = 0) : vector<T>(__n, __val) {}
};
template <class T>
T sum(const vector<T> &vc) {
  T ans = 0;
  for (const T &v : vc) ans += v;
  return ans;
}
long long nextInt() {
  long long t;
  cin >> t;
  return t;
}
long long nextLong() {
  long long t;
  cin >> t;
  return t;
}
constexpr long long MOD = 1000000007;
bool operator<<(const string &a, const string &b) {
  if (a == b) return true;
  if (a.size() != b.size()) return a.size() < b.size();
  return a < b;
}
long long intlen(long long x) {
  long long res = 1;
  while (x /= 10) res++;
  return res;
}
string operator*(const string &s, long long x) {
  string a;
  while (x--) a += s;
  return a;
}
long long factorial(long long x) {
  long long a = 1;
  for (long long i = 1; i <= x; i++) a *= i;
  return a;
}
template <class T>
T reverse(T o) {
  reverse(o.begin(), o.end());
  return o;
}
template <class R, class I>
vector<R> Map(R (*func)(I), const vector<I> &was) {
  vector<R> res;
  res.reserve(was.size());
  for (const auto &e : was) res.push_back(func(e));
  return res;
}
template <class T>
struct reader : public T {
  template <class... Con>
  reader(Con &&...par) : T(par...) {
    cin >> *this;
  }
};
template <>
class reader<long long> {
  long long x;

 public:
  reader() { cin >> x; }
  operator long long &() { return x; }
};
class TaskAnswer {};
void answer() {
  cout << '\n';
  throw TaskAnswer();
}
template <class C, class... Ts>
void answer(C &&cur, Ts &&...args) {
  cout << cur;
  answer(args...);
}
class Answerer {
 private:
  ostream &out;
  void operator()() {
    out << '\n';
    throw TaskAnswer();
  }

 public:
  Answerer(ostream &os) : out(os) {}
  template <class C, class... Ts>
  void operator()(C &&cur, Ts &&...args) {
    out << cur;
    this->operator()(args...);
  }
};
vector<long long> pre_func(const string &s) {
  long long n = s.size();
  vector<long long> p(n);
  for (long long i = 1; i < n; i++) {
    long long j = p[i - 1];
    while (j > 0 && s[j] != s[i]) j = p[j - 1];
    if (s[i] == s[j]) j++;
    p[i] = j;
  }
  return p;
}
long long knut(const string &s, const string &t) {
  auto p = pre_func(s + '$' + t);
  long long n = s.size(), m = t.size();
  for (long long i = n + 1; i <= n + m; i++)
    if (p[i] == n) return i - n - n;
  return -1;
}
vector<long long> z_func(const string &s) {
  long long n = (long long)s.size();
  vector<long long> z(n);
  for (long long i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}
class fastio {
 private:
  FILE *out = stdout;
  FILE *in = stdin;
  FILE *err = stderr;
  template <class T>
  void write(const T &val) {
    this->operator<<(val);
  }
  template <class T>
  void read(T &val) {
    this->operator>>(val);
  }
  template <class T>
  void error(const T &val) {
    this->operator<=(val);
  }

 public:
  fastio() {}
  ~fastio() {}
  fastio &operator>>(char *val) {
    scanf("%s", val);
    return *this;
  }
  fastio &operator<<(const char *val) {
    printf("%s", val);
    return *this;
  }
  fastio &operator<=(const char *val) {
    fprintf(this->err, "%s", val);
    return *this;
  }
  fastio &operator>>(long long &val) {
    scanf("%lld", &val);
    return *this;
  }
  fastio &operator<<(long long val) {
    printf("%lld", val);
    return *this;
  }
  fastio &operator>>(long &val) {
    scanf("%ld", &val);
    return *this;
  }
  fastio &operator<<(long val) {
    printf("%ld", val);
    return *this;
  }
  fastio &operator>>(short &val) {
    scanf("%hd", &val);
    return *this;
  }
  fastio &operator<<(short val) {
    printf("%hd", val);
    return *this;
  }
  fastio &operator>>(char &val) {
    scanf("%c", &val);
    return *this;
  }
  fastio &operator<<(char val) {
    printf("%c", val);
    return *this;
  }
  template <class T, class... AT>
  void write(const T &val, const AT &...args) {
    this->operator<<(val);
    this->write(args...);
  }
  template <class T, class... AT>
  void read(T &val, AT &...args) {
    this->operator>>(val);
    this->read(args...);
  }
  template <class T, class... AT>
  void error(const T &val, const AT &...args) {
    this->operator<=(val);
    this->error(args...);
  }
};
template <class T>
fastio &operator<<(fastio &out, const vector<T> &a) {
  for (const T &x : a) out << x << ' ';
  return out;
}
template <class T>
fastio &operator>>(fastio &in, vector<T> &a) {
  for (long long &x : a) in >> x;
  return in;
}
fastio console;
class yesno {
 private:
  string yes, no;

 public:
  yesno(string y, string n) : yes(y), no(n) {}
  string operator()(bool ok) const { return ok ? this->yes : this->no; }
};
Answerer fanswer(cout);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline void solve();
signed main() {
  init_iostream_speed();
  try {
    solve();
  } catch (TaskAnswer) {
  } catch (...) {
    cout << "0\n";
  }
  cout.flush();
  return 0;
}
inline void stress() {}
inline void solve() {
  reader<long long> n, m;
  reader<vector<long long> > l(m);
  if (sum(l) < n) answer(-1);
  vector<long long> ans(m);
  for (long long i = 0; i < (long long)(m); i++) {
    ans[i] = i;
    if (i + l[i] > n) answer(-1);
  }
  long long e = n;
  for (long long i = m - 1; i > -1; i--)
    if (ans[i] + l[i] < e) {
      ans[i] = e - l[i];
      e = ans[i];
    } else
      break;
  for (long long e : ans) cout << e + 1 << ' ';
  cout << '\n';
}
