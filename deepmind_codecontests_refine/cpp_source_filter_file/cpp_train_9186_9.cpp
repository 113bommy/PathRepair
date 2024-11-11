#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return a * (b / gcd(a, b));
}
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int ans = 0;
  if (n == 1) {
    cout << a[0];
    return;
  }
  if (n == 2) {
    cout << (a[0] | a[1]);
    return;
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = i + 1; j < n; j++) {
      for (long long int k = j + 1; k < n; k++) {
        ans = max(ans, a[0] | a[1] | a[2]);
      }
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int TESTS = 1;
  while (TESTS--) {
    solve();
  }
  return 0;
}
