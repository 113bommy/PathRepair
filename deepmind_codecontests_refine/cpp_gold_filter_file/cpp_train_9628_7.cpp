#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, dd, uui;
  cin >> n >> k;
  char a[343][345];
  if (k > ceil(n / 2.0) * ceil(n / 2.0) + (n / 2) * (n / 2)) {
    cout << "NO";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = 'S';
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = (i + 1) % 2 + 1; j <= n; j += 2) {
      if (k > 0) a[i][j] = 'L';
      k--;
      if (k < 0) break;
    }
    if (k < 0) break;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cout << a[i][j];
    cout << "\n";
  }
  return 0;
}
