#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int x, y, z;
int cnt;
int main() {
  scanf("%d%d%d%d%d%d", &a, &b, &c, &x, &y, &z);
  cnt = (a == x) + (b == y) + (c == z);
  if (cnt >= 1)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
