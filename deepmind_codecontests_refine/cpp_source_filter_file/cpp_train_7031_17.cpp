#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
const double eps = 1e-12;
const long long MOD = 1e9 + 7;
const double PI = acos(-1.0);
const long long INF = 1e18;
long long power_mod(long long a, long long b, long long p) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2)
    return a * (power_mod((a * a) % p, b / 2, p)) % p;
  else
    return power_mod((a * a) % p, b / 2, p);
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2)
    return a * power(a * a, b / 2);
  else
    return power(a * a, b / 2);
}
long long div_mod(long long a, long long b, long long p) {
  return a * power(b, p - 2) % p;
}
void solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(a + b, c + d) << "\n";
}
long long maximum(long long n) {
  long long ans = -1;
  while (n != 0) {
    if (n % 10 > ans) ans = n % 10;
    n = n / 10;
  }
  return ans;
}
bool check(long long n) {
  if (n == 1 || n == 2 || n == 5 || n == 8 || n == 0) return true;
  return false;
}
long long convert(long long n) {
  if (n == 1)
    return 1;
  else if (n == 2)
    return 5;
  else if (n == 5)
    return 2;
  else if (n == 8)
    return 8;
  else if (n == 0)
    return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long p1, p2, p3, p4, a, b, i;
  cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
  p1 = min(p1, p2);
  p3 = min(p3, p4);
  p4 = min(p1, p3);
  if (a == b && a < p4) {
    cout << "1";
    return 0;
  }
  if (p4 < a) {
    cout << "0";
  } else if (p4 >= a && p4 <= b) {
    cout << p4 - a;
  } else {
    cout << b - a;
  }
  return 0;
}
