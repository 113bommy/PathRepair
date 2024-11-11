#include <bits/stdc++.h>
using namespace std;
char str[1100000], ch;
int i, j, len;
char num[7][5] = {"1689", "1698", "1869", "1896", "1968", "1986", "6198"};
int sswap(int x, int y) {
  char t = str[x];
  str[x] = str[y];
  str[y] = t;
  return 0;
}
bool check() {
  int i;
  int now;
  long long sum = 0;
  for (i = 0; i < len; ++i) {
    now = str[i] - '0';
    switch ((len - i) % 6) {
      case 1:
        sum += now;
        break;
      case 2:
        sum += now * 10;
        break;
      case 3:
        sum += now * 100;
        break;
      case 4:
        sum -= now;
        break;
      case 5:
        sum -= now * 10;
        break;
      case 6:
        sum -= now * 100;
        break;
    }
  }
  return (sum % 7 == 0);
}
int main() {
  gets(str);
  len = strlen(str);
  for (i = 0; i < len; ++i) {
    for (j = 0; j < 10; ++j) {
      if (str[i] == '1') {
        sswap(i, 0);
        continue;
      }
      if (str[i] == '6') {
        sswap(i, 1);
        continue;
      }
      if (str[i] == '8') {
        sswap(i, 2);
        continue;
      }
      if (str[i] == '9') {
        sswap(i, 3);
        continue;
      }
    }
  }
  for (i = 0; i < 10; ++i) {
    for (j = 0; j < 4; ++j) str[j] = num[i][j];
    if (check()) {
      puts(str);
      return 0;
    }
  }
  return 0;
}
