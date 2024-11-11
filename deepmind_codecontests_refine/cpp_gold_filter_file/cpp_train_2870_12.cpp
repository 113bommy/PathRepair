#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int n, m;
  cin >> n >> m;
  long long int mn = INT_MAX;
  while (m--) {
    long long int a, b;
    cin >> a >> b;
    mn = min(b - a + 1, mn);
  }
  cout << mn << '\n';
  for (long long int i = 0; i < n; i++) cout << i % mn << " ";
  return 0;
}
