#include <bits/stdc++.h>
using namespace std;
bool isPtSquare(long double x) {
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
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
long long c(long long n, long long m) {
  long long sm = 1;
  for (long long i = 1; i < m + 1; i++) {
    sm *= (n - i + 1);
    sm /= i;
  }
  return sm;
}
long double f(long double n) {
  long double sm = 1;
  for (long long i = 1; i < n + 1; i++) {
    sm *= i;
  }
  return sm;
}
long double pc(long double n, long double k) {
  long double sm = f(n) / f(n - k);
  return sm;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    ;
    vector<long long> v;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      ;
      v.push_back(x);
    };
    sort((v).begin(), (v).end());
    long long ct = 0, j = 0, k = 0, p = 0;
    for (long long i = 0; i < n; i++) {
      ct++;
      j++;
      if (ct < v[i])
        ;
      else if (ct >= v[i]) {
        p += (j - k);
        k++;
      }
    }
    cout << p + 1 << '\n';
  }
  return 0;
}
