#include <bits/stdc++.h>
using namespace std;
char s[5005];
int len;
long long calc(int a, int b) {
  long long x, y;
  x = 0;
  y = s[a + 1] - '0';
  for (int i = a + 2; i <= b - 2; i += 2) {
    if (s[i] == '+') {
      x += y;
      y = s[i + 1] - '0';
    } else {
      y *= s[i + 1] - '0';
    }
  }
  long long temp = x + y;
  x = 0;
  y = s[1] - '0';
  for (int i = 2; i <= len; i += 2) {
    if (i == a) {
      y *= temp;
      i = b;
    }
    if (s[i] == '+') {
      x += y;
      y = s[i + 1] - '0';
    } else {
      y *= s[i + 1] - '0';
    }
  }
  return x + y;
}
int main() {
  scanf("%s", s + 3);
  s[1] = '1';
  s[2] = '*';
  len = strlen(s + 1);
  s[len + 1] = '*';
  s[len + 2] = '1';
  len += 2;
  long long ans = -1;
  for (int i = 2; i <= len; i += 2) {
    for (int j = i + 2; j <= len; j += 2) {
      if (s[i] == '*' && s[j] == '*') {
        ans = max(ans, calc(i, j));
      }
    }
  }
  printf("%I64d\n", ans);
}
