#include <bits/stdc++.h>
using namespace std;
long long int i, j, k;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  long long int mn = 1e9 + 5;
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long int mn1 = 1e9;
  for (i = 0; i < n; i++) {
    long long int x = (v[i] - i);
    if (x < 0) x = 0;
    if (x % n == 0)
      x = (i) + (x);
    else
      x = (i) + ((x / n) + 1) * n;
    if (x < mn1) {
      mn = i + 1;
      mn1 = x;
    }
  }
  cout << mn;
}
signed main() {
  solve();
  return 0;
}
