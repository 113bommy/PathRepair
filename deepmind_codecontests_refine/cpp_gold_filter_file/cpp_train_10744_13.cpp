#include <bits/stdc++.h>
using namespace std;
int t, r, g, b;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &r, &g, &b);
    if (r > g) swap(r, g);
    if (r > b) swap(r, b);
    if (g > b) swap(g, b);
    if (r + g >= b - 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
