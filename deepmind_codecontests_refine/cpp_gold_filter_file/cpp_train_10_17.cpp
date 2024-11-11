#include <bits/stdc++.h>
using namespace std;
int l, r, d, n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &l, &r, &d);
    if (l <= d) d = ((int)(r / d) + 1) * d;
    printf("%d\n", d);
  }
  return 0;
}
