#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, i, j, x, cnt = 0;
  cin >> n;
  for (i = 0; i + 1 < n; i++) {
    for (j = i + 1; j < n; j++) {
      x = i ^ j;
      if (x >= j && (i + j > x && j + x > i && x + i > j) && x <= n) {
        cnt++;
      }
    }
  }
  cout << cnt;
  return 0;
}
