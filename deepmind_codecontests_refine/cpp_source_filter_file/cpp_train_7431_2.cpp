#include <bits/stdc++.h>
using namespace std;
const int xx[] = {0, 1, 0, -1, -1, 1, -1, 1};
const int yy[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};
char str[1004];
char str1[1004];
int main() {
  int i, j, k, x, l, n, mn, t, mx, m, sum, u, e, p, num, a, b, w, z, y, d, ans;
  char ch, ch1;
  bool key = 1, flag = 1;
  scanf("%s", str);
  scanf("%s", str1);
  x = y = 0;
  for (i = 0; str[i]; i++)
    if (str[i] == '1') x++;
  for (i = 0; str1[i]; i++)
    if (str[i] == '1') y++;
  if (x % 2) x++;
  if (x >= y)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
