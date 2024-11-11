#include <bits/stdc++.h>
using namespace std;
long long n, a, b, k, m, yi, ans, can, c[2000009];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> a >> b >> k;
  long long s = a + b;
  for (long long i = 1; i <= n; i++) {
    cin >> m;
    if (m % s == 0)
      yi++;
    else if (m % s <= a)
      ans++;
    else
      c[can++] = m % s - a;
  }
  sort(c, c + can);
  long long kb = ceil(double(b) / a);
  for (long long i = 0; i < can; i++) {
    long long kcan = ceil(double(c[i]) / a);
    if (kcan <= kb && k - kcan >= 0) {
      k = k - kcan;
      ans++;
    } else if (yi && kcan > kb && k - kb >= 0) {
      k = k - kb;
      yi--;
      ans++;
    }
  }
  while (yi) {
    if (k - kb >= 0) {
      yi--;
      ans++;
      k = k - kb;
    } else
      break;
  }
  cout << ans;
}
