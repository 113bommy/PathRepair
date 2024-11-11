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
long long power(long long b, long long p) {
  long long res = 1ll, x = b;
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
double ar[505];
int main() {
  long m, n, a, b;
  double z;
  ios_base::sync_with_stdio(0);
  while (cin >> n >> m) {
    for (long i = 1; i <= n; i++) cin >> ar[i];
    double ans = 0;
    for (long i = 0; i < m; i++) {
      cin >> a >> b >> z;
      ans = max(ans, (ar[a] + ar[b]) / z);
    }
    cout << setprecision(11) << ans << endl;
  }
  return 0;
}
