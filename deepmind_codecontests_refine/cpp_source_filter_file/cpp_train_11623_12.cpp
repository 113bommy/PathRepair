#include <bits/stdc++.h>
using namespace std;
int v[4];
int main() {
  for (int i = 0; i < 4; ++i) scanf("%d", v + i);
  int mn = min(v[2], v[3]);
  int mx = max(v[2], v[3]);
  int c = mx;
  int b = max(v[1], c + 1);
  int a = max(v[0], b + 1);
  if (mx <= 2 * mn && v[1] * 2 >= b && v[0] * 2 >= a) {
    printf("%d\n%d\n%d\n", a, b, c);
  } else
    puts("-1");
  return 0;
}
