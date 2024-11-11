#include <bits/stdc++.h>
using namespace std;
const long long int hell = 1000000007;
const long long int maxn = 1e5 + 5;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m;
  cin >> n >> m;
  long long int ar[n][m], d[n];
  for (long long int i = 0; i < n; i++) {
    long long int ok = 2e18;
    for (long long int j = 0; j < m; j++) {
      cin >> ar[i][j];
      ok = min(ok, ar[i][j]);
    }
    d[i] = ok;
  }
  cout << *max_element(d, d + n);
}
