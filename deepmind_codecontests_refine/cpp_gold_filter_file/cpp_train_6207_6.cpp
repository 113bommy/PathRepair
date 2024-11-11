#include <bits/stdc++.h>
using namespace std;
char ans[4][102];
int main() {
  int n;
  scanf("%d", &n);
  if (n == 1) {
    printf("a\na\nb\nb\n");
  }
  if (n == 2) {
    printf("aa\nbb\naa\nbb\n");
  }
  if (n > 2) {
    for (int i = 0; i < (int)(n); ++i) ans[0][i] = 'a' + ((i / 2) % 2) * 2;
    for (int i = 0; i < (int)(n); ++i) ans[1][i] = 'b' + ((i / 2) % 2) * 2;
    ans[2][0] = 'z';
    for (int i = 0; i < (int)(n); ++i)
      if (i) ans[2][i] = 'a' + (((i - 1) / 2) % 2) * 2;
    ans[3][0] = 'z';
    for (int i = 0; i < (int)(n); ++i)
      if (i) ans[3][i] = 'b' + (((i - 1) / 2) % 2) * 2;
    if (n % 2) {
      ans[0][n - 1] = 'z';
      ans[1][n - 1] = 'z';
    } else {
      ans[2][n - 1] = 'z';
      ans[3][n - 1] = 'z';
    }
    for (int i = 0; i < (int)(4); ++i) printf("%s\n", ans[i]);
  }
  return 0;
}
