#include <bits/stdc++.h>
using namespace std;
long long a, b, k, ans = 0, p = 1, f[500000];
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  cin >> a >> b >> k;
  long long i, j;
  long long temp;
  for (i = 2; i <= k; i++) p = p * i / gcd(p, i);
  if (a - b <= p) {
    for (i = b + 1; i <= a; i++) {
      f[i - b] = f[i - 1 - b] + 1;
      for (j = 2; j <= k; j++)
        if (i - b - i % j >= 0) f[i - b] = min(f[i - b], f[i - b - i % j] + 1);
    }
    cout << f[a - b] << endl;
    return 0;
  }
  for (i = 1; i <= p; i++) {
    f[i] = f[i - 1] + 1;
    for (j = 2; j <= k; j++)
      if (i - i % j >= 0) f[i] = min(f[i], f[i - i % j] + 1);
  }
  ans = f[a - a / p * p];
  temp = b / p * p;
  if (temp < b) temp += p;
  ans += (a / p * p - temp) / p * f[p];
  b -= b / p * p;
  if (b == 0) {
    cout << ans << endl;
    return 0;
  }
  f[b] = 0;
  for (i = b + 1; i <= p; i++) {
    f[i] = f[i - 1] + 1;
    for (j = 2; j <= k; j++)
      if (i - i % j >= b) f[i] = min(f[i], f[i - i % j] + 1);
  }
  ans += f[p];
  cout << ans << endl;
}
