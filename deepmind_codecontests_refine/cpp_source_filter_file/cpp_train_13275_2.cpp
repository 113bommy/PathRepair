#include <bits/stdc++.h>
using namespace std;
int x;
int main() {
  cin >> x;
  int dir = -1;
  if (x < 0) dir = 1;
  x = abs(x);
  x %= 360;
  int thei, thev = 360;
  for (int i = 0; i < 4; i++, x += dir * 90) {
    int tx = x;
    tx = abs(tx) % 360;
    if (tx > 180) tx = 360 - tx;
    if (thev > tx) thev = tx, thei = i;
  }
  printf("%d\n", thei);
  return 0;
}
