#include <bits/stdc++.h>
using namespace std;
int a[400005];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int t1, t2;
    cin >> t1 >> t2;
    ++a[t1];
    ++a[t2];
  }
  int one = 0, two = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 1) ++one;
    if (a[i] == 2) ++two;
  }
  if (two == 2 && one == n - 2) {
    cout << "bus topology";
    return 0;
  }
  two = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 2) ++two;
  }
  if (two == n) {
    cout << "ring topology";
    return 0;
  }
  one = 0, two = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == n - 1) ++two;
    if (a[i] == 1) ++one;
  }
  if (two == 1 && one == n - 1) {
    cout << "star topology";
    return 0;
  }
  cout << "unknown topology";
  return 0;
}
