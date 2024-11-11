#include <bits/stdc++.h>
using namespace std;
int a[105][105], n, i, j, cnt, r, c;
int main() {
  cin >> n >> r >> c;
  cnt = 1;
  memset(a, 0, sizeof a);
  for (i = 0; i < r; i++) {
    if (i & 1) {
      for (j = c - 1; j >= 0; j++) {
        a[i][j] = cnt;
        cnt++;
        if (cnt > n) break;
      }
    } else {
      for (j = 0; j < c; j++) {
        a[i][j] = cnt;
        cnt++;
        if (cnt > n) break;
      }
    }
    if (cnt > n) break;
  }
  if (cnt <= n) {
    cout << -1 << endl;
    return 0;
  }
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      cout << a[i][j];
      if (j != c - 1) cout << " ";
    }
    cout << endl;
  }
  return 0;
}
