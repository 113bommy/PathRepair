#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
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
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
int isPali(string str) {
  string u;
  for (int i = str.length() - 1; i >= 0; i--) {
    u += str[i];
  }
  if (u == str) {
    return 1;
  }
  return 0;
}
long long int gcd(long long int a, long long int b) {
  if (b != 0) {
    return gcd(b, a % b);
  } else {
    return a;
  }
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
bool checkPrimeNumber(int n) {
  bool isPrime = true;
  if (n == 0 || n == 1) {
    isPrime = false;
  } else {
    for (int i = 2; i <= n / 2; ++i) {
      if (n % i == 0) {
        isPrime = false;
        break;
      }
    }
  }
  return isPrime;
}
bool isPerfectSquare(long double x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
long long int cel(long long int a, long long int b) { return (a + b - 1) / b; }
long long int fib(long long int n) {
  if (n <= 1) return n;
  return fib(n - 1) + fib(n - 2);
}
long long int modFact(long long int n, long long int p) {
  if (n >= p) return 0;
  long long int result = 1;
  for (long long int i = 1; i <= n; i++) result = (result * i) % p;
  return result;
}
long long int digSum(long long int n) {
  long long int sum = 0;
  while (n != 0) {
    sum += n % 10;
    n = n / 10;
  }
  return sum;
}
bool CompFloat(float a, float b) {
  if (abs(a - b) < 1e-9) {
    return true;
  }
  return false;
}
bool isPowerOfTwo(int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
long long int smallest_divisor(long long int n) {
  long long int i;
  for (i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      return i;
    }
  }
  return n;
}
bool isFibonacci(int n) {
  return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}
long long int power(long long int x, long long int y, long long int p) {
  int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  if (a.second == b.second) {
    return a.first > b.first;
  }
  return (a.second > b.second);
}
int32_t mod_inv(int32_t a, int32_t m) {
  int32_t g = m, r = a, x = 0, y = 1;
  while (r != 0) {
    int32_t q = g / r;
    g %= r;
    swap(g, r);
    x -= q * y;
    swap(x, y);
  }
  return x < 0 ? x + m : x;
}
long long int DigLeng(long long int n) { return (long long int)log10(n) + 1; }
void solve() {
  string s = "";
  long long int k;
  cin >> k;
  for (int i = 1; i <= 10000; i++) {
    s += to_string(i);
  }
  cout << s[k - 1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
