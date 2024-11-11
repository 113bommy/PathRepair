#include <bits/stdc++.h>
using namespace std;
int n;
int num;
char c;
char str[int(3 * 10e5 + 1)];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %c", &num, &c);
    scanf("%s", str);
    int flag = 1;
    for (int j = 0; j < num; j++) {
      if (str[j] != c) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      printf("0\n");
      continue;
    }
    for (int j = 1; j < num; ++j) {
      flag = 0;
      for (int k = j; k < num; k += j) {
        if (str[j] != c) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        printf("1\n%d\n", j);
        break;
      }
    }
    if (flag) {
      printf("2\n%d %d\n", num - 1, num);
    }
  }
  return 0;
}
