#include <bits/stdc++.h>
using namespace std;
const int MX = 3e5 + 9;
const long double eps = -0.00000001;
const long long mod = 1e9 + 7;
int a[MX], l[MX], r[MX];
int main() {
  long long n, m, ans = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i];
  }
  for (int i = 0; i < n; i++) {
    long long c = 0;
    for (int j = l[i]; j <= r[i]; j++) {
      c += a[j];
    }
    if (c >= 0) {
      ans += c;
    }
  }
  cout << ans;
  return 0;
}
