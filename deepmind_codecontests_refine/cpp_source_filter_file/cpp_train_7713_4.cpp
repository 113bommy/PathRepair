#include <bits/stdc++.h>
using namespace std;
long dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
long dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
template <class T>
T Abs(T a) {
  return (a < 0 ? -a : a);
}
template <class T>
T gcd(T a, T b) {
  return (b != 0 ? gcd(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return ((a * b) / gcd(a, b));
}
template <class T>
T bigMod(T b, T p, T m) {
  if (p == 0)
    return 1;
  else if (p & 1)
    return (b * bigMod(b, p - 1, m)) % m;
  else {
    T temp = bigMod(b, p >> 1, m);
    return (((temp) * (temp))) % m;
  }
}
template <class T>
T modInverse(T b, T m) {
  return bigMod(b, m - 2, m);
}
template <class T>
T power(T b, T p) {
  T res = 1, x = b;
  while (p) {
    if (p & 1) res *= x;
    x *= x;
    p = p >> 1;
  }
  return res;
}
template <typename T>
inline bool isOn(T mask, T pos) {
  return mask & (1 << pos);
}
template <typename T>
inline int Off(T mask, T pos) {
  return mask ^ (1 << pos);
}
template <typename T>
inline int On(T mask, T pos) {
  return mask | (1 << pos);
}
bool stringMod(string a, long long n) {
  long long num = 0;
  for (long i = 0; i < a.size(); i++) num = ((num * 10) + (a[i] - '0')) % n;
  if (num == 0)
    return 1;
  else
    return 0;
}
bool prime[10000 + 2];
vector<long long> primes;
void seive() {
  for (long long i = 4; i <= 10000; i += 2) prime[i] = 1;
  for (long long i = 3; i * i <= 10000; i += 2) {
    if (prime[i] == 0) {
      for (long long j = 2 * i; j <= 10000; j += i) prime[j] = 1;
    }
  }
  primes.push_back(2);
  for (long long i = 3; i <= 10000; i += 2)
    if (prime[i] == 0) primes.push_back(i);
}
long long a = 0, b = 0, c = 0, d = 0, res = 0, ans = 0, sum = 0, cc = 0, f = 0,
          first = 0, mx = 0, mn = 1 << 29, n, m;
string s, second;
vector<long long> v, vv;
map<long long, long long> mpp;
long long ar[1001000], ar1[1000100], dp[105][105];
void read() {
  cin >> n;
  cin >> m;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    res += ar[i];
  }
}
void rec(long long i, long long j, unsigned long long k) {
  if (k > 10000000000) return;
  if (i == j and k) {
  }
  rec(i + 1, j, k * 10 + 4);
  rec(i, j + 1, k * 10 + 7);
}
long long recc(long long n) {
  a = n;
  if (a < 10) return ++c;
  res = 0;
  while (a) {
    res += a % 10;
    a /= 10;
  }
  c++;
  recc(res);
}
int main() {
  cin >> s;
  if (s.size() == 1 and s[0] == '0') {
    cout << 0;
    return 0;
  }
  if (s.size() == 1 and s[0] <= '9') {
    cout << 1;
    return 0;
  }
  res = 0;
  for (int i = 0; i < s.size(); i++) {
    res += (s[i] - 48);
  }
  b = recc(res);
  cout << b;
  return 0;
}
