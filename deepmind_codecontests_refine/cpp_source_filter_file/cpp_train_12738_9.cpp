#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  if (n <= 1)
    cout << "-1";
  else {
    for (long long int i = 1; i <= n; i++) {
      cout << i << " ";
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
