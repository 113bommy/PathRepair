#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 20, inf = -50 + 20;
int n, a[N][N], b[N][N];
bool u;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      b[i][a[i][j]]++;
      if (b[i][a[i][j]] == n - a[i][j]) {
        cout << a[i][j] << " ";
        u = 1;
        for (int k = i + 1; k <= n; k++) {
          b[k][a[i][j]] = -inf;
        }
        break;
      }
    }
    if (u == 0) {
      cout << n << " ";
    }
    u = 0;
  }
  return 0;
}
