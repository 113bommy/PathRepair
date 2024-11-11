#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, R, r;
  double rp;
  scanf("%d %d %d", &n, &R, &r);
  if (n == 1) {
    if (r <= R)
      printf("YES\n");
    else
      printf("NO\n");
    return 0;
  }
  if (n == 2) {
    if (r * 2 <= R)
      printf("YES\n");
    else
      printf("NO\n");
    return 0;
  }
  rp = double(r) / sin(acos(-1.0) / double(n));
  if (rp + double(r) <= double(R))
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
