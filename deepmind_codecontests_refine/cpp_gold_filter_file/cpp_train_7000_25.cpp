#include <bits/stdc++.h>
using namespace std;
inline long long int GCD(long long int x, long long int y) {
  if (x < y) swap(x, y);
  if (x == 0) return y;
  if (y == 0) return x;
  return GCD(x % y, y);
}
long long int phi(long long int n) {
  long long int result = n;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  }
  if (n > 1) result -= result / n;
  return result;
}
long long int power(long long int x, long long int n, long long int mod) {
  long long int res = 1;
  x %= mod;
  while (n) {
    if (n & 1) {
      res = ((res * x) % mod + mod) % mod;
    }
    x = ((x * x) % mod + mod);
    n >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n;
  cin >> n;
  long long int c = (n + 1) / 2;
  vector<long long int> a(n + 1);
  for (long long int i = 1; i <= c; i++) {
    cin >> a[i];
  }
  cin >> a[c + 1];
  for (long long int i = c + 2; i <= n; i++) {
    a[i] = a[i - 1];
  }
  vector<long long int> pre(n + 2, 0);
  for (long long int i = n; i >= 1; i--) {
    pre[i] = pre[i + 1] + a[i];
  }
  long long int k = n;
  long long int mark = 1;
  for (long long int i = 1; i <= mark;) {
    if (pre[i] - pre[i + k] > 0) {
      i++;
      continue;
    } else {
      while (k >= 1) {
        if (pre[i] - pre[i + k] <= 0)
          k--;
        else
          break;
      }
      mark = n - k + 1;
      i++;
    }
  }
  if (k == 0) k = -1;
  cout << k << endl;
}
