#include <bits/stdc++.h>
void swap(char *buf, int k) {
  int i;
  char a;
  for (i = 0; i < k / 2; i++) {
    a = buf[i];
    buf[i] = buf[k - 1 - i];
    buf[k - 1 - i] = a;
  }
}
int main(void) {
  char buf[101];
  int i, n;
  scanf("%d\n", &n);
  if (!fgets(buf, 101, stdin)) {
    printf("Cannot read\n");
    return 0;
  }
  for (i = 0; buf[i]; i++) {
    if (buf[i] == '\n') {
      buf[i] = 0;
      break;
    }
  }
  for (i = 2; i <= n; i++)
    if (n % i == 0) {
      swap(buf, i);
    }
  printf("%s\n", buf);
  return 0;
}
