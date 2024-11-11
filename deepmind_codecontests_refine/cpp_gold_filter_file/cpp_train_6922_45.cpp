#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m;
  cin >> n >> m;
  long long int n1, m1;
  cin >> n1 >> m1;
  long long int a[n], b[m];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  for (long long int i = 0; i < m; i++) cin >> b[i];
  if (a[n1 - 1] < b[m - m1])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int32_t main() {
  ios_base ::sync_with_stdio(false), cin.tie(NULL);
  solve();
  return 0;
}
