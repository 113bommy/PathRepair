#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, l, r, ans;
  scanf("%d %d %d %d", &n, &p, &l, &r);
  if (l == 1 && r == n)
    ans = 0;
  else if (l == 1)
    ans = abs(p - r) + 1;
  else if (r == 1)
    ans = abs(p - l) + 1;
  else if (abs(p - r) < abs(p - l))
    ans = abs(p - r) + r - l + 2;
  else
    ans = abs(p - l) + r - l + 2;
  printf("%d\n", ans);
}
