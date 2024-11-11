#include <bits/stdc++.h>
int main(void) {
  int i, j, N, count1 = 0, count0 = 0;
  scanf("%d", &N);
  char str[N];
  scanf("%s", str);
  for (i = 0; i < N; i++) {
    if (str[i] == '1')
      count1++;
    else if (str[i] == '0')
      count0++;
  }
  if (N != 1) {
    if (count1 == count0) {
      printf("1\n");
      printf("%s", str);
    } else if (count0 != count1) {
      printf("2\n");
      printf("%c ", str[0]);
      for (j = 1; j < N; j++) {
        printf("%c", str[j]);
      }
    }
  } else if (N == 1) {
    printf("1\n%s", str);
  }
}
