#include <bits/stdc++.h>
using namespace std;
int ans[111115];
int main() {
  int i, a[10], k, j, len;
  char str[10];
  ans[111111] = 30;
  ans[11112] = 15;
  ans[1113] = 7;
  ans[114] = 2;
  ans[15] = 1;
  ans[1122] = 6;
  ans[123] = 7;
  ans[24] = 2;
  ans[222] = 8;
  ans[33] = 2;
  ans[6] = 1;
  while (scanf("%s", str) != EOF) {
    len = strlen(str);
    sort(str, str + len);
    i = 0;
    k = 0;
    while (i < len) {
      j = i + 1;
      while (j < len && str[j] == str[i]) j++;
      a[k++] = j - i;
      i = j;
    }
    sort(a, a + k);
    int d = 0;
    for (i = 0; i < k; i++) d = d * 10 + a[i];
    printf("%d\n", ans[d]);
  }
  return 0;
}
