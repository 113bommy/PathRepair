#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, l, a, b, c, d, num, i, flag, an, ans;
  char str[100];
  long long min_ = -1000000002, max_ = 1000000002;
  scanf("%d", &t);
  scanf("\n");
  while (t--) {
    a = b = c = d = num = 0, flag = 0, ans = an = 0;
    gets(str);
    l = strlen(str);
    if (str[0] == '>' && str[1] == ' ') {
      a = 1;
      if (str[2] == '-') {
        i = 3;
        flag = 1;
      } else
        i = 2;
    } else if (str[0] == '>') {
      c = 1;
      if (str[3] == '-') {
        i = 4;
        flag = 1;
      } else
        i = 3;
    } else if (str[0] == '<' && str[1] == ' ') {
      b = 1;
      if (str[2] == '-') {
        i = 3;
        flag = 1;
      } else
        i = 2;
    } else {
      d = 1;
      if (str[3] == '-') {
        i = 4;
        flag = 1;
      } else
        i = 3;
    }
    for (i; i < l; i++) {
      if (str[i] < '0' || str[i] > '9') {
        if (str[i] == 'Y') {
          an = 1;
          break;
        } else if (str[i] == 'N') {
          if (a) {
            a = 0;
            d = 1;
          } else if (b) {
            b = 0;
            c = 1;
          } else if (c) {
            c = 0;
            b = 1;
          } else if (d) {
            d = 0;
            a = 1;
          }
          break;
        }
      } else {
        num = num * 10 + (str[i] - '0');
      }
    }
    if (flag) num = -num;
    if (a) {
      if (min_ <= num) {
        min_ = num + 1;
      }
    } else if (b) {
      if (max_ >= num) {
        max_ = num - 1;
      }
    } else if (c) {
      if (min_ < num) {
        min_ = num;
      }
    } else {
      if (max_ > num) max_ = num;
    }
  }
  if (min_ > max_) {
    printf("Impossible\n");
  } else
    printf("%I64d\n", min_);
  return 0;
}
