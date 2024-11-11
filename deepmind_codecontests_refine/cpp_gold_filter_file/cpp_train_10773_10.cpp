#include <bits/stdc++.h>
using namespace std;
const int cMax = 5005;
char s[cMax];
long long calc(int x, int y) {
  long long sum = 0, prod = s[x] - '0';
  int i = x + 1;
  while (i <= y) {
    if (s[i] == '+') {
      sum += prod;
      prod = 1;
      i++;
    } else if (s[i] == '*') {
      prod *= 1LL * (s[i + 1] - '0');
      i += 2;
    } else {
      prod = s[i] - '0';
      i++;
    }
  }
  return sum + prod;
}
int main() {
  s[0] = '1', s[1] = '*';
  gets(s + 2);
  int l = strlen(s);
  s[l] = '*', s[++l] = '1';
  int k;
  long long x, sum, prod, ans = -1;
  for (int i = 1; i < l - 1; i++) {
    if (s[i] == '*')
      for (int j = i + 1; j < l; j++) {
        if (s[j] == '*') {
          x = calc(i + 1, j - 1);
          sum = 0, prod = k = 1;
          while (k <= l) {
            if (s[k] == '+') {
              sum += prod;
              k++;
              prod = 1;
            } else if (s[k] == '*') {
              if (i == k) {
                prod *= x;
                k = j;
              } else {
                prod *= 1LL * (s[k + 1] - '0');
                k += 2;
              }
            } else {
              prod = s[k] - '0';
              k++;
            }
          }
          sum += prod;
          ans = ans > sum ? ans : sum;
        }
      }
  }
  printf("%I64d", ans);
  return 0;
}
