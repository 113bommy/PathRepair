#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, i, j;
  cin >> n;
  int m;
  cin >> m;
  int a[n];
  long sum;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum == m)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, j, a, t;
  cin >> t;
  while (t--) {
    solve();
  }
}
