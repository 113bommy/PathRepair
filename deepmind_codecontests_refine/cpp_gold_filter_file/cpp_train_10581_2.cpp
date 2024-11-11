#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const double pi = 3.141592653589793238463;
long long modularExponentiation(long long x, long long n, long long M) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % M;
    x = (x * x) % M;
    n = n / 2;
  }
  return result;
}
long long fast_exp(long long x, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans *= x;
    n = n >> 1;
    x = x * x;
  }
  return ans;
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, m;
  cin >> n >> m;
  vector<long double> v;
  for (long long i = 0; i < n; i++) {
    long double a, b;
    cin >> a >> b;
    long double w = a / b;
    v.push_back(w * m);
  }
  sort(v.begin(), v.end());
  cout << fixed << setprecision(10) << v[0];
}
