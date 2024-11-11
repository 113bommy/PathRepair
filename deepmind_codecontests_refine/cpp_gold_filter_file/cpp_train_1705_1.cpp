#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, j, i, k, n, m;
  cin >> n >> m;
  if (n == m) {
    cout << n + 1 << "\n";
    for (i = 0; i <= m; i++) {
      printf("%d %d\n", m - i, i);
    }
  } else if (n < m) {
    cout << n + 1 << "\n";
    for (i = 0; i <= n; i++) {
      printf("%d %d\n", i, i + 1);
    }
  } else {
    cout << m + 1 << "\n";
    for (i = 0; i <= m; i++) {
      printf("%d %d\n", i + 1, i);
    }
  }
  return 0;
}
