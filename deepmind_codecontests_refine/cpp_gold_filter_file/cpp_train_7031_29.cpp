#include <bits/stdc++.h>
using namespace std;
int p[4];
int main() {
  int a, b, i, res;
  while (scanf("%d%d%d%d%d%d", &p[0], &p[1], &p[2], &p[3], &a, &b) != EOF) {
    res = 0;
    sort(p, p + 4);
    if (a < p[0]) res += p[0] - a;
    if (b < p[0]) res = b - a + 1;
    printf("%d\n", res);
  }
}
