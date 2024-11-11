#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f;
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
  int ans = 2 * (e + d) * (c + b) - (b * b + e * e);
  printf("%d\n", ans);
}
