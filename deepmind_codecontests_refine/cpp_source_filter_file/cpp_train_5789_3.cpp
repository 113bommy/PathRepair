#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[4][4];
  for (int j = 0; j < 4; j++)
    scanf("%d%d%d%d", &a[j][0], &a[j][1], &a[j][2], &a[j][3]);
  if (a[0][3] == 1 && (a[1][0] == 1 || a[2][1] == 1 || a[3][2] == 1 ||
                       a[0][0] == 1 || a[0][1] == 1 || a[0][2] == 1))
    return 0 * printf("YES\n");
  if (a[1][3] == 1 && (a[2][0] == 1 || a[3][1] == 1 || a[0][2] == 1 ||
                       a[1][0] == 1 || a[1][1] == 1 || a[1][2] == 1))
    return 0 * printf("YES\n");
  if (a[2][3] == 1 && (a[3][0] == 1 || a[0][1] == 1 || a[2][2] == 1 ||
                       a[2][0] == 1 || a[2][1] == 1 || a[2][2] == 1))
    return 0 * printf("YES\n");
  if (a[3][3] == 1 && (a[0][0] == 1 || a[1][1] == 1 || a[2][2] == 1 ||
                       a[3][0] == 1 || a[3][1] == 1 || a[3][2] == 1))
    return 0 * printf("YES\n");
  printf("NO\n");
  return 0;
}
