#include <bits/stdc++.h>
using namespace std;
int get() {
  char c;
  while (c = getchar(), (c < '0' || c > '9') && (c != '-'))
    ;
  bool flag = (c == '-');
  if (flag) c = getchar();
  int x = 0;
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - 48;
    c = getchar();
  }
  return flag ? -x : x;
}
void output(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  int len = 0, data[10];
  while (x) {
    data[len++] = x % 10;
    x /= 10;
  }
  if (!len) data[len++] = 0;
  while (len--) putchar(data[len] + 48);
  putchar('\n');
}
int main() {
  int n = get();
  if (n == 1) {
    printf("2\n");
    printf("NY\n");
    printf("YN\n");
    return 0;
  }
  static bool ans[1000][1000];
  memset(ans, 0, sizeof(ans));
  int depth = 1;
  int a = n / 2, b = a + 1;
  while (b > 2) {
    int c = a / 2, d = c + 1;
    if (a == c * 2) {
      ans[depth * 4 - 2][depth * 4 + 2] = true;
      ans[depth * 4 - 2][depth * 4 + 3] = true;
      ans[depth * 4 - 1][depth * 4 + 2] = true;
      ans[depth * 4 - 1][depth * 4 + 3] = true;
    } else {
      ans[depth * 4 - 2][depth * 4 + 2] = true;
      ans[depth * 4 - 2][depth * 4 + 4] = true;
      ans[depth * 4 - 1][depth * 4 + 2] = true;
      ans[depth * 4 - 1][depth * 4 + 4] = true;
    }
    if (b == d * 2) {
      ans[depth * 4][depth * 4 + 4] = true;
      ans[depth * 4][depth * 4 + 5] = true;
      ans[depth * 4 + 1][depth * 4 + 4] = true;
      ans[depth * 4 + 1][depth * 4 + 5] = true;
    } else {
      ans[depth * 4][depth * 4 + 2] = true;
      ans[depth * 4][depth * 4 + 4] = true;
      ans[depth * 4 + 1][depth * 4 + 2] = true;
      ans[depth * 4 + 1][depth * 4 + 4] = true;
    }
    a = c;
    b = d;
    depth++;
  }
  ans[depth * 4 - 2][depth * 4 + 2] = true;
  ans[depth * 4 - 1][depth * 4 + 2] = true;
  ans[depth * 4][depth * 4 + 2] = true;
  ans[depth * 4 + 1][depth * 4 + 2] = true;
  if (b == 2) {
    ans[depth * 4][depth * 4 + 3] = true;
    ans[depth * 4 + 1][depth * 4 + 3] = true;
  }
  ans[depth * 4 + 2][1] = true;
  ans[depth * 4 + 3][1] = true;
  ans[0][2] = true;
  if (n & 1)
    ans[0][4] = true;
  else
    ans[0][3] = true;
  int m = depth * 4 + 4;
  output(m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) {
      if (ans[i][j] || ans[j][i])
        putchar('Y');
      else
        putchar('N');
      if (j == m - 1) putchar('\n');
    }
  return 0;
}
