#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, a, b, A[1001] = {0}, j, k;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    A[a] = 1;
    A[b] = 1;
  }
  for (i = 1; i <= n; i++) {
    if (A[i] != 1) {
      break;
    }
  }
  cout << n - 1 << endl;
  for (j = 1; j <= n; j++) {
    if (i == j) continue;
    cout << i << ' ' << j << endl;
  }
  return 0;
}
