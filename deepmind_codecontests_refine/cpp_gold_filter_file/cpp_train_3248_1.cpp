#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int N = 1e6 + 6;
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
  }
  return res;
}
long long gcd(long long a, long long b) {
  while (b > 0) {
    long long t = a % b;
    a = b, b = t;
  }
  return a;
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long is_prime(long long n) {
  if (n <= 1 || n > 3 && (n % 2 == 0 || n % 3 == 0)) return 0;
  for (long long i = 5, t = 2; i * i <= n; i += t, t = 6 - t)
    if (n % i == 0) return 0;
  return 1;
}
int main() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long l = 0, sum = 0, p = 0, b = 0, z = 0;
  map<long long, long long> m;
  vector<long long> v;
  map<long long, long long> m1;
  for (long long i = 0; i < n; i++) {
    if (a[i] < 0) {
      if (m1[abs(a[i])] <= 0)
        b = 1;
      else
        m1[abs(a[i])]--;
    }
    if (a[i] > 0) {
      if (v.size() == 0) {
        if (m[a[i]] != 0) {
          b = 1;
          break;
        } else
          m[a[i]] = i + 1;
      } else {
        if (m[a[i]] <= z)
          m[a[i]] = i + 1;
        else {
          b = 1;
          break;
        }
      }
      m1[a[i]]++;
    }
    sum += a[i];
    l++;
    if (sum == 0) {
      v.push_back(l);
      z += l;
      l = 0;
      sum = 0;
    }
    if (b == 1) break;
  }
  long long k = 0;
  for (int i = 0; i < v.size(); i++) k += v[i];
  if (k != n || b)
    cout << -1 << "\n";
  else {
    cout << v.size() << endl;
    for (long long i = 0; i < v.size(); i++) cout << v[i] << " ";
  }
  return 0;
}
