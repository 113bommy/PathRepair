#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, a, b, l, ara[105];
  cin >> m >> n;
  memset(ara, 0, sizeof ara);
  for (int j = 1; j <= n; j++) {
    cin >> a;
    for (int i = a; i <= m; i++) {
      if (ara[i] == 0) {
        ara[i] = a;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << ara[i] << " ";
  }
  return 0;
}
