#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int i, j, k = 0, l, m, n, o, p, q, r, po[11];
  cin >> n;
  p = n;
  n += n - 1;
  r = 0;
  po[0] = 1;
  for (i = 1; i <= 10; i++) po[i] = po[i - 1] * 10;
  while (n > 0) {
    k++;
    if (n % 10 != 9) {
      r = 1;
    }
    n /= 10;
    q = q * 10 + 9;
  }
  n = p;
  if (!r) {
    cout << 1 << endl;
    return;
  }
  if (n + n - 1 < 9) {
    cout << (n * (n + 1)) / 2;
    return;
  }
  j = i = po[k - 1] - 1;
  long long int ans = 0;
  p = 2 * n - 1;
  while (i <= p) {
    if (n >= i) {
      ans += i / 2;
    } else {
      ans += max(0LL, n - (i / 2));
    }
    i += j + 1;
  }
  cout << ans << endl;
}
int main() {
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
