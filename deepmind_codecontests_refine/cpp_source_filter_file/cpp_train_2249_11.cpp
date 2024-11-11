#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9 + 7;
const int N = (int)1e7 + 7;
char c[105][105];
int main() {
  int n, m, x, y;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
    }
  }
  int mni, mnj, mxi, mxj, ans = 0;
  mni = mnj = inf;
  mxi = mxj = -inf;
  int bl = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (c[i][j] == 'B') {
        mni = min(mni, i);
        mnj = min(mnj, j);
        mxi = max(mxi, i);
        mxj = max(mxj, j);
        bl++;
      }
    }
  }
  int raz = max(mxi - mni + 1, mxj - mnj + 1);
  if (mni == n) {
    raz = 1;
  }
  if (raz > n || raz > m) {
    puts("-1");
  } else {
    cout << raz * raz - bl;
  }
}
