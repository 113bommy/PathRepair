#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T>
int sz(const T& a);
template <typename T>
int unq(vector<T>& a);
template <typename T>
T powi(T x, int i);
template <typename T>
T sqr(const T& x);
template <typename T, typename U>
auto maxx(const T& t, const U& u) -> typename common_type<T, U>::type;
template <typename T, typename U>
auto minn(const T& t, const U& u) -> typename common_type<T, U>::type;
template <typename T, typename U>
bool smin(T& t, const U& u);
template <typename T, typename U>
bool smax(T& t, const U& u);
template <typename T, typename U, typename... V>
auto maxx(const T& t, const U& u, const V&... v) ->
    typename common_type<T, U, V...>::type;
template <typename T, typename U, typename... V>
auto minn(const T& t, const U& u, const V&... v) ->
    typename common_type<T, U, V...>::type;
template <typename T, typename U, typename... V>
bool smin(T& t, const U& u, const V&... v);
template <typename T, typename U, typename... V>
bool smax(T& t, const U& u, const V&... v);
template <typename T>
inline string to_string(const vector<T>& x);
template <typename T>
inline string to_string(const vector<T>& x, int i);
template <typename T>
inline string to_string(const vector<T>& x, int i, int j);
namespace InputReader {
const int N = 1 << 16;
char buffer[N];
char* iptr = buffer + N;
char* endptr = buffer + N;
bool hasMore = true;
int bytesRead;
inline bool reloadBuffer();
inline int gc();
inline bool read(char& x);
inline bool read(char* x);
inline bool read(string& x);
inline bool readln(char* x);
inline bool readln(string& x);
template <typename T>
inline bool readz(T& x);
inline bool read(int& x);
inline bool read(long long& x);
template <typename T>
inline bool read(vector<T>& a);
template <typename T>
inline bool reada(T* a, int n);
template <typename T, typename... U>
inline bool read(T& x, U&... y);
inline int ni();
inline long long nl();
inline string ns();
inline vector<int> nvi(int n);
inline vector<long long> nvl(int n);
}  // namespace InputReader
using InputReader::ni;
using InputReader::nl;
using InputReader::ns;
using InputReader::nvi;
using InputReader::nvl;
using InputReader::read;
using InputReader::reada;
using InputReader::readln;
namespace OutputWriter {
const int N = 1 << 16;
char buffer[N];
char* iptr = buffer;
char* const endptr = buffer + N;
int bytesWritten = 0;
void flushBuffer();
void pc(const int& c);
inline bool print(const char& c);
inline bool print(const char* a);
inline bool print(char* a);
inline bool print(const string& s);
template <typename T>
inline bool printz(T x);
inline bool print(const int& x);
inline bool print(const long long& x);
inline bool print(const double& x);
template <typename T, typename... U>
inline bool print(const T& t, const U&... u);
inline bool println();
template <typename T>
inline bool println(const T& x);
template <typename T, typename... U>
inline bool println(const T& t, const U&... u);
}  // namespace OutputWriter
using OutputWriter::print;
using OutputWriter::println;
bool solve(int testNumber);
void solve();
int localTestCases = 1, testCount = 1;
int MXITR = (int)1e7;
const int inf = (int)1e9 + 7;
const long long infl = (long long)4.6e18 + 7;
const int md = (int)1e9 + 7;
const bool multipleTestCases = 0;
bool solve(int testNumber) {
  int n;
  string s;
  InputReader::read(n, s);
  vi dp(n, 0);
  dp[0] = s[0] == 'x';
  for (int i = 1, i$ = n - 1; i <= i$; ++i)
    if (s[i] == 'x') dp[i] = dp[i - 1] + 1;
  int ans = 0;
  for (int i = 0, i$ = n; i < i$; ++i)
    if (s[i] == 'x') {
      int c = 1, j = i + 1;
      while (j <= n - 1 and s[j] == 'x') ++c, ++j;
      ans += c - 2;
      i = j;
    }
  OutputWriter::println(ans);
  ;
  return true;
}
void solve() {
  if (false) InputReader::read(localTestCases);
  for (int i = 0; i < localTestCases; ++i) {
    if (multipleTestCases) InputReader::read(testCount);
    for (int testNumber = 1; testNumber <= testCount; ++testNumber)
      solve(testNumber);
  }
  OutputWriter::flushBuffer();
}
int main() {
  if (false) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  } else {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  auto t1 = high_resolution_clock::now();
  solve();
  auto t2 = high_resolution_clock::now();
  duration<double> t = t2 - t1;
  if (false) printf("\n\nTime taken: %.5fs\n", t.count());
  fclose(stdin);
  fclose(stdout);
  return 0;
}
template <typename T>
int sz(const T& a) {
  return (int)a.size();
}
template <typename T>
int unq(vector<T>& a) {
  int n = a.size();
  int m = unique(a.begin(), a.end()) - a.begin();
  a.resize(m);
  return n - m;
}
template <typename T>
T powi(T x, int i) {
  T r = 1;
  while (i) {
    if (i & 1) r *= x;
    x *= x;
    i /= 2;
  }
  return r;
}
template <typename T>
T sqr(const T& x) {
  return x * x;
}
template <typename T, typename U>
auto maxx(const T& t, const U& u) -> typename common_type<T, U>::type {
  return (t > u) ? t : u;
}
template <typename T, typename U>
auto minn(const T& t, const U& u) -> typename common_type<T, U>::type {
  return (t < u) ? t : u;
}
template <typename T, typename U>
bool smin(T& t, const U& u) {
  return (u < t) ? (t = u, true) : false;
}
template <typename T, typename U>
bool smax(T& t, const U& u) {
  return (u > t) ? (t = u, true) : false;
}
template <typename T, typename U, typename... V>
auto maxx(const T& t, const U& u, const V&... v) ->
    typename common_type<T, U, V...>::type {
  return maxx(maxx(t, u), v...);
}
template <typename T, typename U, typename... V>
auto minn(const T& t, const U& u, const V&... v) ->
    typename common_type<T, U, V...>::type {
  return minn(minn(t, u), v...);
}
template <typename T, typename U, typename... V>
bool smin(T& t, const U& u, const V&... v) {
  if (auto m = minn(u, v...); m < t) return (t = m, true);
  return false;
}
template <typename T, typename U, typename... V>
bool smax(T& t, const U& u, const V&... v) {
  if (auto m = maxx(u, v...); m > t) return (t = m, true);
  return false;
}
template <typename T>
inline string to_string(const vector<T>& x) {
  return to_string(x, 0, (int)x.size() - 1);
}
template <typename T>
inline string to_string(const vector<T>& x, int i) {
  return to_string(x, i, (int)x.size() - 1);
}
template <typename T>
inline string to_string(const vector<T>& x, int i, int j) {
  string s = to_string(x[i]);
  for (int k = i + 1; k <= j; ++k) s += ' ' + to_string(x[k]);
  return s;
}
inline bool InputReader::reloadBuffer() {
  bytesRead = fread(buffer, sizeof(buffer[0]), N, stdin);
  iptr = buffer;
  endptr = buffer + bytesRead;
  hasMore = (bytesRead != 0);
  return hasMore;
}
inline int InputReader::gc() {
  if (iptr == endptr)
    if (!reloadBuffer()) return EOF;
  return *iptr++;
}
inline bool InputReader::read(char& x) {
  int c = gc();
  while (isspace(c) and c != EOF) c = gc();
  if (c == EOF) {
    x = (char)0;
    if (false) assert(false);
    return false;
  }
  x = (char)c;
  return true;
}
inline bool InputReader::read(char* a) {
  int c = gc();
  while (isspace(c) and c != EOF) c = gc();
  if (c == EOF) {
    *a = '\0';
    if (false) assert(false);
    return false;
  }
  while (!isspace(c) and c != EOF) {
    *a++ = (char)c;
    c = gc();
  }
  *a = '\0';
  return true;
}
inline bool InputReader::read(string& s) {
  static char t[(int)2e6 + 10];
  if (!read(t)) return false;
  s.assign(t);
  return true;
}
inline bool InputReader::readln(char* a) {
  int c = gc();
  while (isspace(c) and c != EOF) c = gc();
  if (c == EOF) {
    *a = '\0';
    if (false) assert(false);
    return false;
  }
  while ((c != '\n' and c != '\r' and c != '\f') and c != EOF) {
    *a++ = (char)c;
    c = gc();
  }
  *a = '\0';
  return true;
}
inline bool InputReader::readln(string& s) {
  static char t[(int)2e6 + 10];
  if (!readln(t)) return false;
  s.assign(t);
  return true;
}
template <typename T>
inline bool InputReader::readz(T& x) {
  int c = gc();
  bool negative = false;
  x = 0;
  while (isspace(c) and c != EOF and c != '-') c = gc();
  if (c == '-') {
    negative = true;
    c = gc();
  }
  if (c == EOF) {
    if (false) assert(false);
    return false;
  }
  while (isdigit(c)) {
    x = x * 10 + (c - '0');
    c = gc();
  }
  if (negative) x = -x;
  return true;
}
inline bool InputReader::read(int& x) { return readz<int>(x); }
inline bool InputReader::read(long long& x) { return readz<long long>(x); }
template <typename T, typename... U>
inline bool InputReader::read(T& x, U&... y) {
  bool b1 = read(x);
  bool b2 = read(y...);
  return b1 and b2;
}
template <typename T>
inline bool InputReader::read(vector<T>& a) {
  bool b = true;
  for (auto& e : a) b &= read(e);
  return b;
}
inline int InputReader::ni() {
  int _;
  read(_);
  return _;
}
inline long long InputReader::nl() {
  long long _;
  read(_);
  return _;
}
inline string InputReader::ns() {
  string _;
  read(_);
  return _;
}
inline vector<int> InputReader::nvi(int n) {
  vector<int> v(n);
  for (int& e : v) read(e);
  return v;
}
inline vector<long long> InputReader::nvl(int n) {
  vector<long long> v(n);
  for (long long& e : v) read(e);
  return v;
}
inline void OutputWriter::flushBuffer() {
  int r = fwrite(buffer, sizeof(buffer[0]), bytesWritten, stdout);
  if (false) assert(r == bytesWritten);
  iptr = buffer;
  bytesWritten = 0;
}
inline void OutputWriter::pc(const int& c) {
  *iptr = (char)c;
  ++bytesWritten;
  if (++iptr == endptr) flushBuffer();
}
inline bool OutputWriter::print(const char& c) {
  pc(c);
  return true;
}
inline bool OutputWriter::print(char* a) {
  while (*a != '\0') pc(*a++);
  return true;
}
inline bool OutputWriter::print(const char* a) {
  while (*a != '\0') pc(*a++);
  return true;
}
inline bool OutputWriter::print(const string& s) {
  for (const char& c : s) pc(c);
  return true;
}
template <typename T>
inline bool OutputWriter::printz(T x) {
  if (x < 0) {
    pc('-');
    x = -x;
  }
  static int t[64];
  if (x == 0) {
    pc('0');
    return true;
  }
  int* ptr = t;
  int* const startptr = t;
  while (x > 0) {
    *ptr++ = x % 10;
    x /= 10;
  }
  do {
    pc(*--ptr + '0');
  } while (ptr != startptr);
  return true;
}
inline bool OutputWriter::print(const int& x) { return printz<int>(x); }
inline bool OutputWriter::print(const long long& x) {
  return printz<long long>(x);
}
inline bool OutputWriter::print(const double& x) {
  static char a[64];
  sprintf(a, "%.12f", x);
  return print(a);
}
template <typename T, typename... U>
inline bool OutputWriter::print(const T& t, const U&... u) {
  print(t);
  print(' ');
  return print(u...);
}
inline bool OutputWriter::println() {
  pc('\n');
  return true;
}
template <typename T>
inline bool OutputWriter::println(const T& x) {
  print(x);
  return println();
}
template <typename T, typename... U>
inline bool OutputWriter::println(const T& t, const U&... u) {
  print(t);
  print(' ');
  return println(u...);
}
