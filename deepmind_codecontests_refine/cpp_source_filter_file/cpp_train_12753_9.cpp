#include <bits/stdc++.h>
using namespace std;
bool isprime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i += 6) {
    if ((n % i == 0) || (n % (i + 2) == 0)) return false;
  }
  return true;
}
long long power(long long x, long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else {
    if (y > 0)
      return (x * temp * temp);
    else
      return ((temp * temp) / x);
  }
}
bool sortbysec(const pair<pair<long long, long long>, long long> &a,
               const pair<pair<long long, long long>, long long> &b) {
  return (a.second < b.second);
}
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first - a.second < b.first - b.second;
}
bool p2(long long n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
const long long N = 2e5 + 10;
const long long mod = 1e9 + 7;
const double pi = 3.141592653589793238460;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  ;
  long long v;
  cin >> v;
  long long v1;
  cin >> v1;
  ;
  long double k = v + v1;
  long double t = (long double)n / k;
  long double p = t * (long double)v;
  if (p == (long long)p) return cout << (long long)p, 0;
  cout << fixed << setprecision(1) << p;
  return 0;
}
