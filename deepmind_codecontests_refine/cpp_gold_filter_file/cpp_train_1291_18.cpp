#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, h;
  scanf("%d%d", &r, &h);
  int ans = 2 * (h / r);
  h %= r;
  if (h >= sqrt(3) * r * 0.5)
    ans += 3;
  else if (h * 2 >= r)
    ans += 2;
  else
    ans += 1;
  printf("%d", ans);
  printf("\n");
}
