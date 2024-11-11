#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const long long INF = 1e18;
const long double EPS = 1e-12;
long long inv[100005];
int pr[100005];
long long mod;
long long mod_pow(long long x, long long p) {
  if (p == 0) {
    return 1LL;
  }
  if (p == 1) {
    return x;
  }
  long long tmp = mod_pow(x, p / 2LL);
  tmp = tmp * tmp;
  tmp %= mod;
  if (p % 2 == 1) {
    tmp *= x;
    tmp %= mod;
  }
  return tmp;
}
int main() {
  int n;
  cin >> n;
  for (int i = (int)2; i < (int)n + 1; i++) {
    pr[i] = 1;
  }
  for (int i = (int)2; i < (int)n + 1; i++) {
    if (pr[i] == 1) {
      for (int j = 2; i * j <= n; i++) {
        pr[i * j] = 0;
      }
    }
  }
  if (n == 1) {
    cout << "YES" << endl;
    cout << "1" << endl;
    return 0;
  }
  if (n == 4) {
    cout << "YES" << endl;
    cout << "1" << endl;
    cout << "3" << endl;
    cout << "2" << endl;
    cout << "4" << endl;
    return 0;
  }
  if (pr[n] == 0) {
    cout << "NO" << endl;
    return 0;
  }
  mod = n;
  for (int i = (int)1; i < (int)n + 1; i++) {
    inv[i] = mod_pow((long long)(i), mod - 2);
  }
  cout << "YES" << endl;
  cout << "1" << endl;
  for (int i = (int)2; i < (int)n; i++) {
    long long x = (long long)(i);
    x *= inv[x - 1];
    x %= mod;
    cout << x << endl;
  }
  cout << n << endl;
  return 0;
}
