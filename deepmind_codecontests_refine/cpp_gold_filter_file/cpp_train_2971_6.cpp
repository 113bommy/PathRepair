#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f;
  while (cin >> a >> b >> c >> d >> e >> f) {
    int ron = -1;
    int val[] = {e, f, a, b, c, d};
    for (int i = 5; i >= 0; i--)
      if (val[i] == 0) {
        ron = (i & 1) == 0;
        break;
      }
    if (ron == -1) ron = b * d * f > a * c * e;
    printf("%s\n", ron ? "Ron" : "Hermione");
  }
  return 0;
}
