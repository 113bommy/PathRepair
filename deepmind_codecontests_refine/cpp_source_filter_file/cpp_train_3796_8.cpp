#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int a[maxn][4];
int main(int argc, const char* argv[]) {
  int n, k;
  cin >> n >> k;
  memset(a, 0, sizeof(a));
  a[1][0] = 1;
  a[1][1] = 2;
  a[1][2] = 3;
  a[1][3] = 5;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 4; j++) {
      a[i][j] = a[i - 1][j] + 6;
    }
  }
  printf("%d\n", a[n][3] * k);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
