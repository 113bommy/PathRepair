#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, t1, t2, t3;
  scanf("%d%d%d%d%d%d", &x, &y, &z, &t1, &t2, &t3);
  int sum1 = t1 * abs(x - y);
  int sum2 = t3 * 2 + t2 * (abs(x - y) + abs(z - x));
  if (sum1 < sum2)
    printf("NO\n");
  else
    printf("YES\n");
}
