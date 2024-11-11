#include <bits/stdc++.h>
int main() {
  int n;
  int inp[26];
  memset(inp, 0, 26 * sizeof(int));
  char temp[20];
  scanf("%d", &n);
  while (n--) {
    scanf("%s", &temp);
    inp[temp[0] - 'a']++;
  }
  int Res = 0;
  for (int i = 0; i < 26; i++) {
    if (inp[i] > 2) {
      int a, b;
      a = inp[i] >> 1;
      b = inp[i] - a;
      Res += (a * (a - 1)) >> 1;
      Res += (b * (b - 1)) >> 1;
    }
  }
  printf("%d\n", Res);
}
