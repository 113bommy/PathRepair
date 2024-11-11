#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, a, b, rows, ans = -1;
  bool start, end;
  scanf("%d %d %d %d", &n, &m, &a, &b);
  if ((a - 1) % m == 0)
    start = true;
  else
    start = false;
  if ((b % m == 0) || b == n)
    end = true;
  else
    end = false;
  rows = (b - 1) / m - (a - 1) / m;
  if (rows == 0)
    ans = 1;
  else if (start && end)
    ans = 1;
  else if (rows == 1)
    ans = 2;
  else if (start || end)
    ans = 2;
  else if ((a - 1) % m + 1 == (b - 1) % m)
    ans = 2;
  else if (!start && !end)
    ans = 3;
  assert(ans != -1);
  printf("%d\n", ans);
}
