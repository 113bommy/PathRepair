#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string p, q;
  cin >> p >> q;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 0; i < p.length(); i++) {
    a[i + 1] = p[i] - 'a';
    b[i + 1] = q[i] - 'a';
  }
  for (int i = n; i >= 0; i--) {
    a[i] += b[i];
    if (i != 0) {
      a[i - 1] += a[i] / 26;
      a[i] = a[i] % 26;
    }
  }
  for (int i = 0; i <= n; i++) {
    int rem = a[i] % 2;
    a[i] /= 2;
    if (i + 1 <= n) {
      a[i + 1] += rem * 26;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << (char)('a' + a[i]);
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tcs = 1;
  while (tcs--) solve();
  return 0;
}
