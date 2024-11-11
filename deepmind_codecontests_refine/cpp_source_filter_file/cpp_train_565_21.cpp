#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main() {
  int n, mn, s, i, j, t;
  scanf("%d", &n);
  char ch;
  t = 0;
  for (i = 0; i <= n - 1; i++) {
    scanf("%c", &ch);
    if (ch == 'H')
      a[i] = 0;
    else
      a[i] = 1;
    t += a[i];
  }
  mn = 1000000;
  for (i = 1; i <= n; i++) {
    s = 0;
    for (j = 1; j <= t; j++) {
      s += 1 - a[(i + j) % n];
    }
    if (mn > s) mn = s;
  }
  printf("%d", mn);
}
