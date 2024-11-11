#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
const double pi = 3.141592653589793238463;
long long modExp(long long x, long long n, long long M) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % M;
    x = (x * x) % M;
    n = n / 2;
  }
  return result;
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
bool vow(char ch) {
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
bool isPrime(long long n) {
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
long long fast_exp(long long x, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) {
      ans *= x;
      ans %= M;
    }
    n = n >> 1;
    x = (x * x) % M;
  }
  return ans;
}
long long inverse(long long x) { return fast_exp(x, M - 2); }
long long combination(long long n, long long r) {
  if (r == 0)
    return 1;
  else {
    long long ans = n % M;
    ans *= combination(n - 1, r - 1) % M;
    ans %= M;
    ans *= inverse(r) % M;
    ans %= M;
    return ans;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, k, s;
  cin >> n >> k >> s;
  if (k > s or s > k * (n - 1))
    cout << "NO";
  else {
    cout << "YES" << endl;
    long long p = 1;
    while (k > 0) {
      long long q = min(n - 1, s - k + 1);
      k--;
      if (p - q > 0)
        cout << p - q << " ", p = p - q;
      else
        cout << p + q << " ", p = p + q;
      s -= q;
    }
  }
}
