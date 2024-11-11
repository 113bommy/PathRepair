#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, r, j, i, n, k;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 4 == 0)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
