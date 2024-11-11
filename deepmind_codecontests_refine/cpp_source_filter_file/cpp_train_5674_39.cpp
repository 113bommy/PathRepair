#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, i, j, a[200][200], max, p, b[200] = {0}, ans;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    max = -1;
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] > max) {
        max = a[i][j];
        p = j;
      }
    }
    b[p]++;
  }
  max = -1;
  for (i = 0; i < m; i++) {
    if (b[i] > max) {
      max = b[i];
      ans = i;
    }
  }
  cout << ans + 1 << endl;
}
