#include <bits/stdc++.h>
using namespace std;
inline void scanint(int &x) {
  register int c = 0;
  x = 0;
  int flag = 0;
  for (; ((c != 45) && (c < 48 || c > 57)); c = getchar())
    ;
  for (; ((c == 45) || (c > 47 && c < 58)); c = getchar()) {
    if (c == 45)
      flag = 1;
    else
      x = (x << 1) + (x << 3) + c - 48;
  }
  if (flag) x = -x;
}
int main() {
  int t, n, m, i, j, k, l, ans, count, temp, sum, flag;
  char a[20], b[20];
  scanf("%d %s %s", &n, a, b);
  if (b[0] == 'w') {
    if (n == 1)
      cout << "52";
    else if (n == 2)
      cout << "52";
    else if (n == 3)
      cout << "52";
    else if (n == 4)
      cout << "52";
    else if (n == 5)
      cout << "53";
    else if (n == 6)
      cout << "53";
    else if (n == 7)
      cout << "52";
  } else {
    if (n <= 29)
      cout << "12";
    else if (n == 30)
      cout << "11";
    else
      cout << "7";
  }
  return 0;
}
