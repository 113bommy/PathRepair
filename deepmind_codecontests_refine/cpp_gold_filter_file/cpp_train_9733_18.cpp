#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a, b, c, d, e, f;
  int x, y, z;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);
  scanf("%d", &e);
  scanf("%d", &f);
  x = n - c - e <= b ? n - c - e : b;
  if (x == n - c - e)
    y = c;
  else
    y = n - b - e <= d ? n - b - e : d;
  z = n - x - y;
  printf("%d %d %d", x, y, z);
}
