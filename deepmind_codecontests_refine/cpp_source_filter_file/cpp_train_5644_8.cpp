#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  int a[n];
  for (int i = 0; i < k; i++) a[i] = s[i] - '0';
  for (int i = k; i < n; i++) {
    a[i] = a[i - k];
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (a[i] > s[i] - '0') break;
    if (a[i] < s[i] - '0') ok = false;
  }
  cout << n << '\n';
  if (ok) {
    for (int i = 0; i < n; i++) cout << a[i];
    return;
  }
  int idx = -1;
  for (int i = k - 1; i >= 0; i--) {
    if (a[i] != 9) {
      a[i]++;
      idx = i;
      break;
    }
  }
  for (int i = 0; i < k; i++) {
    if (a[i] == 9 && i != idx) {
      a[i] = 0;
    }
  }
  for (int i = k; i < n; i++) a[i] = a[i - k];
  for (int i = 0; i < n; i++) cout << a[i];
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  while (t--) {
    solve();
  }
}
