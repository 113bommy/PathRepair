#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c = 0, f = 1;
  cin >> n >> m;
  int a[52] = {1};
  for (int i = n; i <= m; i++) {
    f = 1;
    for (int j = 2; j < i; j++)
      if (i % j == 0) {
        f = 0;
        break;
      }
    if (f && i == m) {
      cout << "YES\n";
      return 0;
    } else if (f)
      break;
  }
  cout << "NO\n";
  return 0;
}
