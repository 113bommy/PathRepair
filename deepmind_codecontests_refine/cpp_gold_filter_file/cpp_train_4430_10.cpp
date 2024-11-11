#include <bits/stdc++.h>
int main() {
  int i, arr[25] = {2,  3,  4,  5,  7,  9,  11, 13, 17, 19,
                    23, 25, 29, 31, 37, 41, 43, 47, 49},
         count = 0;
  for (i = 0; i < 19; i++) {
    printf("%d\n", arr[i]);
    fflush(stdout);
    char res[10];
    scanf("%s", res);
    char y[10] = "yes";
    if (strcmp(res, y) == 0) {
      count++;
    }
  }
  if (count == 1 || count == 0)
    printf("prime\n");
  else
    printf("composite\n");
  return 0;
}
