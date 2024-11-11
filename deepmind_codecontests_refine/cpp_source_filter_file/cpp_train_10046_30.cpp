#include <bits/stdc++.h>
using namespace std;
int n, xa, xb, ya, yb, da, db;
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
int main() {
  scanf("%d%d%d%d%d", &n, &xa, &ya, &xb, &yb);
  if (ya == n) da = (3 * n) + xa;
  if (xa == n) da = (2 * n) + ya;
  if (ya == 0) da = n + xa;
  if (xa == 0) da = n - ya;
  if (yb == n) db = (3 * n) + xb;
  if (xb == n) db = (2 * n) + yb;
  if (yb == 0) db = n + xb;
  if (xb == 0) db = n - yb;
  printf("%d", min(abs(da - db), (4 * n) - abs(da - db)));
  return 0;
}
