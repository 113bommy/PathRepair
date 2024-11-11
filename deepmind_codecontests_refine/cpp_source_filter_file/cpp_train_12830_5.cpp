#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 2;
int a[MAX_N];
void solve() {
  int n;
  int ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 1; i <= n; i++) {
    if (a[i] <= i) {
      ans = i;
    }
  }
  cout << ans + 1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
