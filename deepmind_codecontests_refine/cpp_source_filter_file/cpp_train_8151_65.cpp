#include <bits/stdc++.h>
using namespace std;
void __print(long long x) { cerr << x; }
void __print(long x) { cerr << x; }
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
  long long f = 0;
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
long long Power(long long a, long long n, long long mod) {
  long long res = 1;
  while (n) {
    if (n % 2 != 0) {
      res = ((res % mod) * (a % mod)) % mod;
      n--;
    } else {
      a = ((a % mod) * (a % mod)) % mod;
      n /= 2;
    }
  }
  return res;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long getSum(long long n) {
  long long sum = 0;
  while (n != 0) {
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}
long long myceil(long long n, long long x) {
  long long y;
  if (n % x == 0) {
    y = n / x;
    return y;
  } else {
    y = n / x + 1;
    return y;
  }
}
long long md = 1000000007;
vector<long long> fact, inv;
void inverse(long long n) {
  if (n >= inv.size()) {
    long long size = inv.size();
    size = size == 0 ? 1 : size;
    inv.resize(n + 1);
    inv[0] = 1;
    for (long long i = size; i <= n; i++) inv[i] = Power(fact[i], md - 2, md);
  }
}
void factorial(long long n) {
  if (n >= fact.size()) {
    long long size = fact.size();
    size = size == 0 ? 1 : size;
    fact.resize(n + 1);
    fact[0] = 1;
    for (long long i = size; i <= n; i++) fact[i] = (fact[i - 1] * i) % md;
  }
}
long long ncr(long long n, long long r) {
  return (((fact[n] * inv[r]) % md) * inv[n - r]) % md;
}
long long primes[1300000];
void Sieve() {
  bool IsPrime[1300000];
  memset(IsPrime, true, sizeof(IsPrime));
  for (long long p = 2; p * p < 1300000; p++) {
    if (IsPrime[p] == true) {
      for (long long i = p * p; i < 1300000; i += p) IsPrime[i] = false;
    }
  }
  long long index = 0;
  for (long long p = 2; p < 1300000; p++)
    if (IsPrime[p]) {
      primes[index] = p;
      index++;
    }
}
void q1();
void q2();
void q3();
void q4();
void q5();
void q6();
void q7();
void q8();
void q9();
void q10();
int32_t main() {
  q5();
  return 0;
}
void q1() {
  long long s1, s2, s3, s4;
  cin >> s1 >> s2 >> s3 >> s4;
  set<long long> second;
  second.insert(s1);
  second.insert(s2);
  second.insert(s3);
  second.insert(s4);
  cout << 4 - second.size() << "\n";
}
void q2() {
  string s;
  cin >> s;
  long long n = s.length();
  if (n > 10) {
    cout << s[0] << n - 2 << s[n - 1] << "\n";
  } else {
    cout << s << "\n";
  }
}
void q3() {
  string s;
  cin >> s;
  set<char> ans;
  for (long long i = 0; i < s.length(); i++) {
    ans.insert(s[i]);
  }
  if (ans.size() % 2 == 0) {
    cout << "CHAT WITH HER!"
         << "\n";
  } else {
    cout << "IGNORE HIM!"
         << "\n";
  }
}
void q4() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  s1.append(s2);
  sort(s1.begin(), s1.end());
  sort(s3.begin(), s3.end());
  if (s1 == s3) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
vector<long long> Digits(long long n) {
  long long m = n;
  vector<long long> ans;
  while (m) {
    ans.push_back(m % 10);
    m = m / 10;
  }
  return ans;
}
bool DistinctDigits(vector<long long> a) {
  bool set = true;
  sort(a.begin(), a.end());
  for (long long i = 0; i < a.size() - 1; i++) {
    if (a[i] == a[i + 1]) {
      set = false;
      break;
    }
  }
  return set;
}
void q5() {
  long long n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  cout << (min(min(k * l / nl, p / np), c * d)) / 3 << "\n";
}
