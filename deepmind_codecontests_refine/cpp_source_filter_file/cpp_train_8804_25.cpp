#include <bits/stdc++.h>
using namespace std;
namespace IO {
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin.exceptions(cin.failbit);
  if (s.size()) {
    setIn(s + ".inp");
    setOut(s + ".out");
  } else {
  }
}
}  // namespace IO
using namespace IO;
namespace Function {
template <typename T1, typename T2>
void amax(T1 &a, T2 b) {
  if (typeid(a).name() == typeid(int).name() &&
      typeid(b).name() == typeid(long long).name()) {
    cout << "Error on amax";
    exit(0);
  }
  if (a < b) a = b;
}
template <typename T1, typename T2>
void amin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T>
void compress(vector<T> &a) {
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
}
template <typename T>
long long sqr(T x) {
  return 1LL * x * x;
}
template <typename T1, typename T2>
long long gcd(T1 a, T2 b) {
  return (b == 0 ? a : gcd(b, a % b));
}
template <typename T1, typename T2>
long long lcm(T1 a, T2 b) {
  return 1LL * a / gcd(a, b) * b;
}
}  // namespace Function
using namespace Function;
namespace Output {
void print(int x) { cout << x << "\n"; }
void print(unsigned int x) { cout << x << "\n"; }
void print(long unsigned int x) { cout << x << "\n"; }
void print(long long x) { cout << x << "\n"; }
void print(unsigned long long x) { cout << x << "\n"; }
void print(float x) { cout << x << "\n"; }
void print(double x) { cout << x << "\n"; }
void print(long double x) { cout << x << "\n"; }
void print(char x) { cout << x << "\n"; }
void print(const char *x) { cout << x << "\n"; }
void print(string x) { cout << x << "\n"; }
void print(bool x) { cout << x << "\n"; }
template <class T, class... Ts>
void print(T t, Ts... ts) {
  cout << t << " ";
  print(ts...);
}
template <typename T1, typename T2>
void print(pair<T1, T2> a) {
  print(a.first, a.second);
}
template <typename T>
void print(T a) {
  for (auto it : a) {
    print(it);
  }
}
template <class T, class... Ts>
void prine(T t, Ts... ts) {
  print(t, ts...);
  exit(0);
}
}  // namespace Output
using namespace Output;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int INF = 1e9;
const long long INFL = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
long long Bit[N * 2];
struct pack {
  int x, y, h;
  bool operator>(pack A) const { return (y == A.y ? x > A.x : y > A.y); }
} a[N];
void inc(int i, long long val) {
  for (; i < N; i += i & -i) {
    amax(Bit[i], val);
  }
}
long long val(int i) {
  long long res = 0;
  for (; i > 0; i -= i & -i) {
    amax(res, Bit[i]);
  }
  return res;
}
int main() {
  setIO();
  int n;
  cin >> n;
  vector<int> p;
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y >> a[i].h;
    p.push_back(a[i].x);
    p.push_back(a[i].y);
  }
  compress(p);
  for (int i = 0; i < n; i++) {
    a[i].x = lower_bound(p.begin(), p.end(), a[i].x) - p.begin() + 1;
    a[i].y = lower_bound(p.begin(), p.end(), a[i].y) - p.begin() + 1;
  }
  sort(a, a + n, greater<pack>());
  long long res = 0;
  for (int i = 0; i < n; i++) {
    long long x = val(a[i].y - 1) + a[i].h;
    amax(res, x);
    inc(a[i].x, x);
  }
  print(res);
  return 0;
}
