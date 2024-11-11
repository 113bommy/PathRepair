#include <bits/stdc++.h>
using namespace std;
int a, b;
int club(int k) {
  int rlt = (k - 1) / (a + b);
  if (k <= rlt * (a + b) + a) return rlt * 2 + 1;
  return rlt * 2 + 2;
}
int big(int k) {
  int tag = club(k) / 2;
  if (club(k) % 2) return a + 1 + (a + b) * tag;
  return 1 + (a + b) * tag;
}
int small(int k) {
  int tag = club(k) / 2;
  if (club(k) % 2) return (a + b) * tag;
  return (a + b) * (tag - 1) + a;
}
int solve(int st, int en) {
  if (club(en) > club(st) + 5) return max(a + 1, 2 * a - b);
  if (club(en) == club(st)) {
    if (club(en) % 2) return en - st + 1;
    return 1;
  }
  if (club(en) == club(st) + 1) {
    if (club(st) % 2) return a - ((st - 1) % (a + b));
    return ((en - 1) % (a + b)) - a + 2;
  }
  if (club(en) == club(st) + 2) {
    int x = a - ((st - 1) % (a + b)), y = (en - 1) % (a + b) + 1;
    if (club(st) % 2) return max(min(x + y, a), max(x, y + min(x, a - b)));
    return a + 1;
  }
  return max(solve(big(st), en), solve(st, small(en)));
}
int main() {
  int st, en;
  scanf("%d %d %d %d", &a, &b, &st, &en);
  printf("%d\n", solve(st, en));
  return 0;
}
