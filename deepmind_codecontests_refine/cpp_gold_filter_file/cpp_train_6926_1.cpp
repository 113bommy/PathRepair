#include <bits/stdc++.h>
using namespace std;
int year(int x, int lzs) {
  if (lzs) {
    int mp(10);
    while (mp <= x) mp *= 10;
    for (int i = 0; i < lzs; i++) mp *= 10;
    int py = year(x, lzs - 1);
    for (int i = 0;; i++) {
      int y = i * mp + x;
      if (y <= py) continue;
      return y;
    }
  }
  if (x < 10) {
    if (x == 9) return 1989;
    return (1990 + x);
  }
  int mp(100);
  while (mp <= x) mp *= 10;
  mp /= 10;
  int plzs(0);
  int pmp(10);
  while (pmp <= x % mp) pmp *= 10;
  while (pmp < mp) {
    plzs++;
    pmp *= 10;
  }
  int py = year(x % mp, plzs);
  mp *= 10;
  for (int i = 0;; i++) {
    int y = i * mp + x;
    if (y <= py) continue;
    return y;
  }
}
int n;
char c;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x(0);
    int lzs(0);
    c = '\n';
    while ((c < '0') || (c > '9')) {
      c = getchar();
    }
    do {
      if ((!x) && (c == '0')) lzs++;
      x = x * 10 + c - '0';
      c = getchar();
    } while ((c >= '0') && (c <= '9'));
    if (!x) lzs--;
    cout << year(x, lzs) << endl;
  }
  return 0;
}
