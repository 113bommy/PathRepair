#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, ts;
  scanf("%d", &ts);
  while (ts--) {
    scanf("%d %d %d", &a, &b, &c);
    int tot = 0, m;
    m = min(b, c >> 1);
    tot += (m * 3);
    b -= m;
    tot += ((b >> 1) * 3);
    printf("%d\n", tot);
  }
  return 0;
}
