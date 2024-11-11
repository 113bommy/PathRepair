#include <bits/stdc++.h>
char s[5000100];
long long a = 0, b = 0, k = 1, pcount[5000100], sum = 0;
int main() {
  gets(s);
  int len = strlen(s);
  for (int i = 1; i <= len; i++) {
    a = s[i - 1] - 'A' + a * 3;
    b = b + (s[i - 1] - 'A') * k;
    if (a == b) {
      pcount[i] = pcount[i / 2] + 1;
    }
    sum = sum + pcount[i];
    k *= 3;
  }
  printf("%lld", sum);
  return 0;
}
