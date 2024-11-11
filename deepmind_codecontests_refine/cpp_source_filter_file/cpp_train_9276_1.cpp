#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, m, k;
  cin >> n;
  int a[101];
  for (i = 0; i < n; i++) {
    cin >> m;
    for (j = 0; j < m; j++) {
      cin >> k;
      a[k]++;
    }
  }
  for (i = 0; i < 101; i++) {
    if (a[i] == n) cout << i << " ";
  }
  return 0;
}
