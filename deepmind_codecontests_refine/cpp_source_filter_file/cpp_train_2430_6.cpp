#include <bits/stdc++.h>
using namespace std;
long long int n, base, num;
char a[1000005], b[1000005];
long long int cal(long long int x, long long int y) {
  long long int mul = x, res = 1;
  while (y != 0) {
    if (y % 2) res = (res * mul) % base;
    mul = (mul * mul) % base;
    y /= 2;
  }
  return res;
}
long long int cal_power() {
  long long int i, s = num, res = 1, noww, j;
  for (i = n; i >= 1; i--) {
    if (b[i] != '0') {
      res = (res * cal(s, b[i] - '0')) % base;
    }
    noww = 1;
    for (j = 1; j <= 10; j++) noww = (noww * s) % base;
    s = noww;
  }
  return res;
}
int main() {
  long long int i, s, cost, res, mul, pri;
  bool have;
  scanf("%s%s", a + 1, b + 1);
  cin >> base;
  n = strlen(a + 1);
  s = 1;
  num = 0;
  have = false;
  for (i = n; i >= 1; i--) {
    if (!have) {
      num = (num + (((a[i] - '0') + 10 - 1) % 10) * s) % base;
      if (a[i] != '0') have = true;
    } else {
      num = (num + (a[i] - '0') * s) % base;
    }
    s = (s * 10) % base;
  }
  res = num;
  s = 1;
  num = 0;
  n = strlen(a + 1);
  for (i = 1; i <= n; i++) {
    num = (num + ((a[i] - '0') * s)) % base;
    s = (s * 10) % base;
  }
  n = strlen(b + 1);
  have = false;
  s = 1;
  mul = 0;
  for (i = n; i >= 1; i--) {
    if (have) continue;
    if (b[i] == '0') {
      b[i] = '9';
      continue;
    }
    b[i] = ((b[i] - '0') - 1) + '0';
    have = true;
  }
  pri = (res * cal_power()) % base;
  if (pri == 0)
    cout << base << endl;
  else
    cout << pri << endl;
  return 0;
}
