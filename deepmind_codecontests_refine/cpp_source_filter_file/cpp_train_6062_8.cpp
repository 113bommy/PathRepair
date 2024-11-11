#include <bits/stdc++.h>
using namespace std;
int t, n, m, a[1007];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cin >> n >> m;
    long long d = 0;
    for (int j = 1; j <= n; ++j) {
      cin >> a[j];
      d = d + a[j];
    }
    if (d >= m)
      cout << m << '\n';
    else
      cout << t << '\n';
  }
  return 0;
}
