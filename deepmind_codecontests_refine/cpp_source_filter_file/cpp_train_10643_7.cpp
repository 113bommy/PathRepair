#include <bits/stdc++.h>
int f(char ch) {
  int ret = 0;
  for (int i = 0; i <= 8; ++i) {
    if (ch & (1 << i)) {
      ret |= (1 << (8 - i));
    }
  }
  return ret;
}
int main() {
  char str[128];
  gets(str);
  int pre = 0;
  for (int i = 0; str[i]; ++i) {
    int ret = f(str[i]);
    printf("%d\n", (((pre - ret) % 256) + 256) % 256);
    pre = ret;
  }
  return 0;
}
