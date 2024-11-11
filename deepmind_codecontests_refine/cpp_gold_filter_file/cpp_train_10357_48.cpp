#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
const int SIZE = 1e7 + 5;
const double eps = 1e-7;
const long long mod = 1e9 + 7;
const int mx = 1e5 + 1;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
template <typename XPAX>
void ckmax(XPAX &x, XPAX y) {
  x = (x < y ? y : x);
}
template <typename XPAX>
void ckmin(XPAX &x, XPAX y) {
  x = (x > y ? y : x);
}
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int first = 0;
  cerr << '{';
  for (auto &i : x) cerr << (first++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
auto random_address = [] {
  char *p = new char;
  delete p;
  return (uint64_t)p;
};
bool isPrime(long long n) {
  if (n == 0 || n == 1) {
    return false;
  } else {
    for (long long i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        return false;
        break;
      }
    }
  }
  return true;
}
int check1(int n) {
  int ans = 0;
  while (n % 2 == 0) {
    ans++;
    n /= 2;
  }
  for (int i = 3; i * i <= n; i = i + 2) {
    while (n % i == 0) {
      ans++;
      n /= i;
    }
  }
  if (n > 2) {
    ans++;
  }
  return ans;
}
bool isCbrt(long long n) {
  return (round(cbrt(n)) * round(cbrt(n)) * round(cbrt(n))) == n && n > 0;
}
void solve() {}
void test_case() {}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string a[10] = {"zero", "one", "two",   "three", "four",
                  "five", "six", "seven", "eight", "nine"};
  string b[10] = {"ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                  "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  string c[10] = {"twenty", "thirty",  "forty",  "fifty",
                  "sixty",  "seventy", "eighty", "ninety"};
  if (n < 10) {
    cout << a[n];
    return 0;
  }
  if (n >= 10 && n <= 19) {
    cout << b[n % 10];
    return 0;
  }
  if (n % 10 != 0) {
    cout << c[(n / 10) - 2] << "-" << a[(n % 10)];
    return 0;
  }
  cout << c[(n / 10) - 2];
  return 0;
}
