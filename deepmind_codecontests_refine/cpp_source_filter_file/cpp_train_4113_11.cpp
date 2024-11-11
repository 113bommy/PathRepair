#include <bits/stdc++.h>
using namespace std;
int N, a[(int)1e6 + 1][2], chk[401], res[401];
int main() {
  scanf("%d", &N);
  for (int i = 2; i <= N * 2; i++)
    for (int j = 1; j < i; j++) {
      int x;
      scanf("%d", &x);
      a[x][0] = i;
      a[x][1] = j;
    }
  for (int i = 1e6; i >= 0; i--) {
    if (a[i][0] && !chk[a[i][0]] && !chk[a[i][1]]) {
      chk[a[i][0]] = chk[a[i][1]] = 1;
      res[a[i][0]] = a[i][1];
      res[a[i][1]] = a[i][0];
    }
  }
  for (int i = 1; i <= 2 * N; i++) printf("%d ", res[i]);
  printf("\n");
  return 0;
}
