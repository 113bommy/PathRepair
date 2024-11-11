#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[5005], b[5005], c[5005];
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int ok(int k) {
  int sum = 0;
  for (int i = 0; i < m; i++)
    while (k % b[i] == 0) sum--, k /= b[i];
  for (int i = 2; i * i <= k; i++)
    while (k % i == 0) sum++, k /= i;
  if (k > 1) sum++;
  return sum;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  int ans = 0;
  for (int i = 0; i < n; i++) ans += ok(a[i]);
  c[0] = a[0];
  for (int i = 1; i < n; i++) c[i] = gcd(c[i - 1], a[i]);
  int tmp = 1;
  for (int i = n - 1; i >= 0; i--) {
    int d;
    if (c[i] % tmp == 0)
      d = ok(c[i] / tmp);
    else
      continue;
    if (d < 0) ans -= d * (i + 1), tmp = c[i];
  }
  cout << ans;
  return 0;
}
