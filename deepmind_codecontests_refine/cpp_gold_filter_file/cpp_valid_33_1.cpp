#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[100000];
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long ans = a[0] * a[1];
    for (long long i = 1; i < (n - 1); i++) ans = max(ans, a[i] * a[i + 1]);
    cout << ans << "\n";
  }
  return 0;
}
