#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c), c *= 5;
  int ans = a;
  for (int i = 0; i <= a; ++i) {
    int x = i * b;
    if (x > a) break;
    ans = min(ans, (a - x) % c);
  }
  printf("%d", ans);
  return 0;
}
