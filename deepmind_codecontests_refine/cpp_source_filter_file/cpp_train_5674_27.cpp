#include <bits/stdc++.h>
using namespace std;
const int N = 107;
const int inf = 1000 * 1000 * 1000 + 7;
int a[N][N];
int b[N];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int mx = 0, mxi;
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      if (a[i][j] > mx) {
        mx = a[i][j];
        mxi = j;
      }
    }
    b[mxi]++;
  }
  int mx = 0, mxi;
  for (int i = 0; i < n; i++) {
    if (b[i] > mx) {
      mx = b[i];
      mxi = i;
    }
  }
  printf("%d", mxi + 1);
  return 0;
}
