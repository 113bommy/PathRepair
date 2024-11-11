#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s, a, b;
  char c;
  string str;
  cin >> n;
  cin >> str;
  m = ((str[0] - '0') * 10) + (str[1] - '0');
  s = ((str[3] - '0') * 10) + (str[4] - '0');
  if (n == 12) {
    if (m < 1) {
      m = 1;
    }
    if (m > 12) {
      b = m % 10;
      a = m / 10;
      m = b;
      if (m == 0) m++;
    }
  } else if (n == 24) {
    if (m > 23) {
      m = m % 10;
    }
  }
  if (s > 59) {
    a = s / 10;
    b = s % 10;
    if (a > 5) a = 5;
    s = a * 10 + b;
  }
  printf("%02d:%02d\n", m, s);
  return 0;
}
