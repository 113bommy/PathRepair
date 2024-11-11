#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
const long long int M = 1e9 + 7;
int a[N], ans;
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if (n <= 2 or n % 2 == 0) {
    cout << -1;
    return;
  }
  for (int i = n / 2; i; i--) {
    ans += max(a[2 * i], a[2 * i + 1]);
    a[i] = max(0, a[i] - max(a[2 * i], a[2 * i + 1]));
  }
  cout << ans + a[1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  cout << "\n";
  return 0;
}
