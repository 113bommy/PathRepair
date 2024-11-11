#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k;
  int n, m;
  int p = 100003, x = 10000000;
  cin >> n >> m;
  cout << p << " " << p << endl;
  for (i = 1; i <= n - 2; i++) {
    cout << i << " " << (i + 1) << " 1" << endl;
    p--;
  }
  cout << (n - 1) << " " << (n) << " " << p << endl;
  m -= (n - 1);
  for (i = 1; i < n - 1; i++) {
    for (j = i + 1; j <= n; j++) {
      if (i + 1 == j) continue;
      if (!m) return 0;
      cout << i << " " << j << " " << x << endl;
      m--;
    }
  }
  return 0;
}
