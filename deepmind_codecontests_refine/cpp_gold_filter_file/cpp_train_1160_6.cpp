#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5 + 5;
long long a[mxN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > a[i - 1]) ans += (a[i] - a[i - 1]) * (n - a[i] + 1);
    if (a[i] < a[i - 1]) ans += (a[i - 1] - a[i]) * a[i];
  }
  cout << ans << "\n";
}
