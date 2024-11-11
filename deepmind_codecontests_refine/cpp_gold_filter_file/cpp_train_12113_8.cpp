#include <bits/stdc++.h>
using namespace std;
int x, t, a, b, da, db, i, j, p, ans = 0;
int main() {
  scanf("%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db);
  i = 0;
  for (i = 0; i < t; i++)
    for (j = 0; j < t; j++) {
      if (a - i * da + b - j * db == x) ans = 1;
    }
  for (i = 0; i < t; i++)
    if (a - i * da == x || b - i * db == x) ans = 1;
  if (ans == 1 || x == 0)
    printf("YES");
  else
    printf("NO");
  return 0;
}
