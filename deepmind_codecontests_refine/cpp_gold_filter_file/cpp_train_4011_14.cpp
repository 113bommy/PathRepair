#include <bits/stdc++.h>
double pi = 3.141592653589793238;
using namespace std;
long long __gcd(long long a, long long b) {
  if (b == 0) return a;
  if (b > a) return __gcd(b, a);
  return __gcd(b, a % b);
}
long long power(long long x, unsigned long long y) {
  long long res = 1;
  x = x % 1000000007;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = ((res * x) % 1000000007 + 1000000007) % 1000000007;
    y = y >> 1;
    x = ((x * x) % 1000000007 + 1000000007) % 1000000007;
  }
  return res % 1000000007;
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
bool checkPrime(long long n) {
  long long count = 0;
  for (long long i = 1; (i * i) <= n; i++) {
    if ((i * i) == n) {
      count++;
      continue;
    }
    if (n % i == 0) count += 2;
  }
  if (count == 2) return true;
  return false;
}
long long lcm(long long a, long long b) { return a * b / (__gcd(a, b)); }
using namespace std;
long long phi(long long n) {
  long long result = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  }
  if (n > 1) result -= result / n;
  return result;
}
vector<long long> prime1;
long long N = 1e7 + 1;
set<long long> s;
void primeSieve() {
  bool *arr = new bool[N];
  for (long long i = 0; i < N; i++) arr[i] = true;
  arr[0] = false;
  arr[1] = false;
  for (long long i = 1; i * i <= N; i++) {
    if (arr[i] == false)
      continue;
    else {
      for (long long j = i * i; j < N; j += i) {
        arr[j] = false;
      }
    }
  }
  for (long long i = 0; i < N; i++) {
    if (arr[i] == true) {
      prime1.push_back(i);
      s.insert(i);
    }
  }
}
long long factors1[2000005];
void factors() {
  for (long long i = 0; i < 2000005; i++) {
    factors1[i] = i;
  }
  for (long long i = 2; i < 2000005; i += 2) {
    factors1[i] = 2;
  }
  for (long long i = 3; i * i < 2000005; i++) {
    if (factors1[i] == i) {
      for (long long j = i * i; j < 2000005; j += i)
        if (factors1[j] == j) factors1[j] = i;
    }
  }
}
long long fac[1000001] = {1};
void factorial() {
  fac[0] = 1;
  for (unsigned long long i = 1; i < 1000001; i++) {
    fac[i] = (((((fac[i - 1]) + 1000000007) % 1000000007) * i) + 1000000007) %
             1000000007;
  }
}
long long C(long long a, long long b) {
  if (a == 0) return 0;
  if (b > a) return 0;
  if (b == 0 || b == a) return 1;
  long long div = ((fac[b] * fac[a - b])) % 1000000007;
  div = power(div, 1000000007 - 2) % 1000000007;
  return (fac[a] * div) % 1000000007;
}
long long ceil(long long a, long long b) { return (a + b - 1) / b; }
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  return (a.first / a.second) > (b.first / b.second);
}
void solve(long long test) {
  long long s, x;
  cin >> s >> x;
  long long bits[128] = {0};
  long long sBits[128] = {0};
  long long temp = x;
  long long cnt = 0;
  long long i = 0;
  while (temp) {
    if (temp & 1) {
      bits[i] = 1;
      cnt++;
    }
    i++;
    temp /= 2;
  }
  long long diff = s - x;
  if (diff < 0) {
    cout << 0 << "\n";
    return;
  }
  if (diff & 1) {
    cout << 0 << "\n";
    return;
  }
  temp = diff;
  i = 0;
  while (temp) {
    if (temp & 1) {
      if (bits[i - 1]) {
        cout << 0 << "\n";
        return;
      }
    }
    i++;
    temp /= 2;
  }
  long long ans = pow(2, cnt);
  if (diff == 0) ans -= 2;
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  solve(0);
  ;
  return 0;
}
