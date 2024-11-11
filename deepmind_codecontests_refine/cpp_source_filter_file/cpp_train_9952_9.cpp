#include <bits/stdc++.h>
using namespace std;
inline int score(int x, int y) {
  for (int i = 1; i <= 5; i++) {
    if (x * (1 << i) > y) return i * 500;
  }
  return 3000;
}
int main() {
  int n;
  scanf("%d", &n);
  int arr[n][5];
  int solves[5];
  memset(solves, 0, sizeof(solves));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d", &arr[i][j]);
      if (arr[i][j] != -1) solves[j]++;
    }
  }
  int ans = -1;
  for (int i = 0; i <= 121; i++) {
    int tot = 0;
    for (int j = 0; j < 5; j++) {
      int dmin = INT_MIN;
      for (int k = 0; k <= i; k++) {
        int sc = score(solves[j] + k, i + n);
        int vsc = 0, psc = 0;
        if (arr[0][j] != -1) vsc = sc - arr[0][j] * (sc / 250);
        if (arr[1][j] != -1) psc = sc - arr[1][j] * (sc / 250);
        dmin = max(dmin, vsc - psc);
        if (arr[0][j] == -1) break;
      }
      tot += dmin;
    }
    if (tot > 0) {
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);
}
