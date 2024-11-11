#include <bits/stdc++.h>
#pragma GCC optimize "03"
using namespace std;
const long long int inf = INT_MAX;
const long double eps = 0.0000001;
const long double PI = acos(-1.0);
const long long int MOD = 1e9 + 7;
const long long int N = 1e5 + 5;
long long int ans;
long long int sorted(long long int a[], long long int l, long long int r) {
  for (long long int i = l; i < r - 1; i++) {
    if (a[i] > a[i + 1]) return 0;
  }
  return 1;
}
void func(long long int a[], long long int l, long long int r) {
  long long int n = r - l;
  if (sorted(a, l, r)) ans = max(ans, n);
  if (n <= 1) return;
  func(a, l, r / 2);
  func(a, l + n / 2, r);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ans = 0;
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  func(a, 0, n);
  cout << ans;
  return 0;
}
