#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, x;
  cin >> n >> x;
  int a[n], b[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + n, greater<int>());
  bool flag = true;
  for (int i = 0; i < n; i++) {
    if (a[i] + b[i] > n) {
      flag = false;
      break;
    }
  }
  cout << (flag ? "YES\n" : "NO\n");
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
