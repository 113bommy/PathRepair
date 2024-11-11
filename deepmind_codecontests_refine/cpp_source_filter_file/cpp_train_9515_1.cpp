#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int N = 1e6 + 100;
long long int pr[N] = {0};
long long int SEr() {
  for (long long int i = 2; i < N; i++) {
    if (pr[i] == 0) {
      for (long long int j = 2 * i; j < N; j += i) pr[j]++;
    }
  }
  return 0;
}
bool isPrime(long long int n) {
  if (pr[n] == 0)
    return true;
  else
    return false;
}
long long int power(long long int a, long long int b) {
  a %= mod;
  long long int res = 1;
  while (b > 0) {
    if (b % 2) {
      res *= a;
      res %= mod;
    }
    a *= a;
    a %= mod;
    b /= 2;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
long long int lcm(long long int a, long long int b) {
  return ((a / gcd(a, b)) * b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int T = 1;
  while (T--) {
    long long int n;
    cin >> n;
    long long int a[n], i, sum = 0, count = 0, ans = 0;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) {
      count += a[i];
    }
    for (i = 0; i < n; i++) {
      if (a[i] == 1)
        a[i] = -1;
      else
        a[i] = 1;
    }
    for (i = 0; i < n; i++) {
      sum += a[i];
      if (sum > ans) {
        ans = sum;
      }
      if (sum < 0) {
        sum = 0;
      }
    }
    cout << count + ans;
  }
  return 0;
}
