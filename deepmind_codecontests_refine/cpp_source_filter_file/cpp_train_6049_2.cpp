#include <bits/stdc++.h>
using namespace std;
long long powermodm(long long x, long long n, long long M) {
  if (x == 0) return 0;
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x + M) % M;
    x = (x * x + M) % M;
    n = n / 2;
  }
  return result;
}
long long power(long long _a, long long _b) {
  long long _r = 1;
  while (_b) {
    if (_b % 2 == 1) _r = (_r * _a);
    _b /= 2;
    _a = (_a * _a);
  }
  return _r;
}
void build() {}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  build();
  long long n, p, t, k, b;
  string s, h, m;
  cin >> n >> t >> b;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long sum = 0;
  if (n % 2 != 0) {
    if (a[n / 2] == 2) sum += min(t, b);
    for (int i = 1; i <= n / 2; i++) {
      if (a[i - 1] != a[n - i] && a[i - 1] != 2 && a[n - i] != 2) {
        cout << -1;
        return 0;
      } else if (a[i - 1] == a[n - i] && a[i - 1] == 2)
        sum = sum + (2 * min(t, b));
      else if (a[i - 1] != a[n - i] && (a[i - 1] == 1 || a[n - i] == 1))
        sum += b;
      else if (a[i - 1] != a[n - i] && (a[i - 1] == 0 || a[n - i] == 0))
        sum += t;
    }
  } else {
    for (int i = 1; i <= n / 2; i++) {
      if (a[i - 1] != a[n - i] && a[i - 1] != 2 && a[n - i] != 2) {
        cout << -1;
        break;
      } else if (a[i - 1] == a[n - i] && a[i - 1] == 2)
        sum = sum + (2 * min(t, b));
      else if (a[i - 1] != a[n - i] && (a[i - 1] == 1 || a[n - i] == 1))
        sum += b;
      else if (a[i - 1] != a[n - i] && (a[i - 1] == 0 || a[n - i] == 0))
        sum += t;
    }
  }
  cout << sum;
  return 0;
}
