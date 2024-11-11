#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i = 0, j = 0;
  cin >> n >> m;
  int eq1 = 0;
  int eq2 = 0;
  int cnt = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      eq1 = (i * i) + j;
      eq2 = i + (j * j);
      if (eq1 == n && eq2 == m) cnt++;
      if (eq1 > n || eq2 > m) break;
    }
  }
  cout << cnt;
  return 0;
}
