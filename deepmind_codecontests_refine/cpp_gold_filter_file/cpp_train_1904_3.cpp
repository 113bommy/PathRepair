#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
const unsigned int M = 1000000007;
long long a[N], b[N];
void solve() {
  int n, m;
  cin >> n >> m;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum == m)
    cout << "YES";
  else
    cout << "NO";
}
int32_t main() {
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
