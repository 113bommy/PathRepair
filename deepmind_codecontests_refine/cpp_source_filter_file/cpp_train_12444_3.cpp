#include <bits/stdc++.h>
using std::getchar;
using std::printf;
int main() {
  char c, s[110];
  s[0] = '+';
  int plus(1), minus(0), n(0), i(1), ans[110];
  ans[0] = 1;
  long long sum(1);
  while ((c = getchar()) != '=') {
    if (c == '+') {
      ++plus;
      s[i] = c;
      ++sum;
      ans[i++] = 1;
    } else if (c == '-') {
      ++minus;
      s[i] = c;
      --sum;
      ans[i++] = 1;
    }
  }
  s[i] = '~';
  c = getchar();
  while ((c = getchar()) != '\n') n = n * 10 + c - '0';
  if ((plus - 1) * n >= minus && plus - n <= minus * n) {
    printf("Possible\n");
    i = 0;
    sum = n - sum;
    while (sum) {
      if (sum > 0) {
        if (s[i] == '+') {
          if (sum > n - 1) {
            ans[i] = n;
            sum -= n - 1;
          } else {
            ans[i] += sum;
            sum = 0;
          }
        }
      } else {
        if (s[i] == '-') {
          if (-sum < n - 1) {
            ans[i] = n;
            sum += n - 1;
          } else {
            ans[i] -= sum;
            sum = 0;
          }
        }
      }
      i++;
    }
    i = 1;
    printf("%d ", ans[0]);
    while (s[i] != '~') {
      printf("%c %d ", s[i], ans[i]);
      ++i;
    }
    printf("= %d\n", n);
  } else
    printf("Impossible\n");
}
