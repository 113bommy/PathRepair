#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, d, n, ans = 0, cnt = 0;
  cin >> d >> n;
  int a[2222];
  for (i = 1; i <= n; ++i) cin >> a[i];
  for (i = 1; i < n; ++i) {
    ans += d - a[i];
  }
  cout << ans;
  return 0;
}
