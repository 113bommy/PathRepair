#include <bits/stdc++.h>
using namespace std;
int n, arr[110], cub[2][110];
int main() {
  int c = 1;
  int x = -1;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] > 0) {
      if (arr[i] == c) {
        cub[0][c] = 1;
        cub[1][c] = i;
        c++;
      }
    }
  }
  if (c == 1) {
    printf("0\n");
    return 0;
  }
  printf("%d\n", c - 1);
  c = 1;
  while (cub[0][c] == 1) {
    printf("%d ", cub[1][c] + 2000);
    c++;
  }
}
