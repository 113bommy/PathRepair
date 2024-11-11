#include <bits/stdc++.h>
using namespace std;
int a[6][6];
int main() {
  int k;
  scanf("%d", &k);
  int len = 0;
  for (int i = 30; i >= 0; --i)
    if (k >= (1 << i)) {
      len = i;
      break;
    }
  a[0][0] = (1 << (len + 1)) - 1, a[0][1] = k, a[0][2] = 0;
  a[1][0] = ((1 << (len + 1)) - 1) ^ k, a[1][1] = (1 << (len + 1)) - 1,
  a[1][2] = 0;
  a[2][0] = 0, a[2][1] = k, a[2][2] = k;
  printf("3 3\n");
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) printf("%d ", a[i][j]);
    printf("\n");
  }
}
