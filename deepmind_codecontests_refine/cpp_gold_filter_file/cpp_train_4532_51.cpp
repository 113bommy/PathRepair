#include <bits/stdc++.h>
using namespace std;
int a[11][11];
int calc(int t1, int t2, int t3, int t4) {
  int res = 0;
  for (int i = t1; i <= t3; i++) {
    for (int j = t2; j <= t4; j++) {
      res += a[i][j];
    }
  }
  return res;
}
int main() {
  int r, c, n, k, t1, t2;
  cin >> r >> c >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> t1 >> t2;
    a[t1][t2] = 1;
  }
  int num = 0;
  int count = 0;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      for (int o = i; o <= r; o++) {
        for (int t = j; t <= c; t++) {
          if (calc(i, j, o, t) >= k) count++;
        }
      }
    }
  }
  cout << count << endl;
  return 0;
}
