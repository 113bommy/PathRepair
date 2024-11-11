#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j = 0, count, t = 0;
  int m, n;
  char a[1001];
  gets(a);
  n = strlen(a);
  for (i = 0; i < n - 2; i++) {
    if (a[i] == 'W' && a[i + 1] == 'U' && a[i + 2] == 'B') {
      i += 2;
      t++;
    } else {
      if (t >= 1 && j != 0) putchar(' ');
      printf("%c", a[i]);
      j = 1;
      t = 0;
    }
  }
  puts("");
  return 0;
}
