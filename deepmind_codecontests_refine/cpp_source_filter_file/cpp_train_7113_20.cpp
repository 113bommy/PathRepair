#include <bits/stdc++.h>
using namespace std;
int MOD(int a, int b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
long long int max3(long long int a, long long int b, long long int c) {
  return max(c, max(a, b));
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int max(long long int a, long long int b) { return (a > b) ? a : b; }
long long int min(long long int a, long long int b) { return (a < b) ? a : b; }
long long int gcd(long long int a, long long int b) {
  if (b == 1)
    return 1;
  else if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
int k;
int fn(int x) {
  int ctr = 0;
  int cnt = 0;
  while (x >= pow(k, cnt)) {
    ctr += x / pow(k, cnt);
    cnt++;
  }
  return ctr;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, i, j, l;
  cin >> n >> k;
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  int lo, up;
  lo = 1;
  up = 1000000000;
  int x1 = (lo + up) / 2;
  while (lo < up) {
    if (fn(x1) < n)
      lo = x1 + 1;
    else
      up = x1 - 1;
    x1 = (lo + up) / 2;
  }
  if (fn(x1) == n)
    cout << x1 << '\n';
  else
    cout << x1 + 1 << '\n';
  return 0;
}
