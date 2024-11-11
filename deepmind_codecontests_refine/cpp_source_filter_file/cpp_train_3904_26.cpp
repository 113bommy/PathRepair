#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int level(int x, int y) { return min(x, n - x - 1) + min(y, m - y - 1); }
int main() {
  scanf("%d%d%d", &n, &m, &k);
  bool dead = false;
  for (int i = 0; i < (int)k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    if (level(x, y) <= 4) dead = true;
  }
  puts(dead ? "YES" : "NO");
  return 0;
}
