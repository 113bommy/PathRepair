#include <bits/stdc++.h>
using namespace std;
int inp[4002];
char str[4002];
map<int, int> m;
int main() {
  int a, l, i, j;
  long long int res = (long long int)0;
  scanf("%d%s", &a, str);
  l = strlen(str);
  for (i = 0; i < l; i++) {
    inp[i + 1] = str[i] - '0';
  }
  for (i = 2; i <= l; i++) {
    inp[i] += inp[i - 1];
  }
  for (i = 0; i <= l; i++) {
    for (j = i + 1; j <= l; j++) {
      m[inp[j] - inp[i]]++;
    }
  }
  for (i = 0; i <= l; i++) {
    for (j = i + 1; j <= l; j++) {
      if (a == 0) {
        if (inp[j] - inp[i] == 0) {
          res +=
              2 * (long long int)l * (long long int)(l + 1) / (long long int)2 -
              (long long int)m[0];
        }
      } else {
        if (inp[j] - inp[i] <= a && inp[j] - inp[i] != 0) {
          if (a % (inp[j] - inp[i]) == 0) {
            res += (long long int)m[a / (inp[j] - inp[i])];
          }
        }
      }
    }
  }
  printf("%I64d", res);
}
