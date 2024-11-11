#include <bits/stdc++.h>
using namespace std;
long long int n, m, a, b;
void solve() {
  cin >> a >> b;
  n = min(a, b);
  m = max(a, b);
  if (m % 2 == 0)
    cout << m / 2 * n << endl;
  else
    cout << (m - 1) / 2 * n + n / 2 + (n % 2) << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) solve();
}
