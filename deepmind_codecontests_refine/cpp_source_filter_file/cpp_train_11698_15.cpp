#include <bits/stdc++.h>
using namespace std;
int ping[3][2] = {0};
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int kind, x, y;
    scanf("%d%d%d", &kind, &x, &y);
    ping[kind][0] = x, ping[kind][1] = y;
  }
  if (ping[1][0] >= ping[1][1])
    puts("LIVE");
  else
    puts("DEAD");
  if (ping[2][0] >= ping[2][1])
    puts("LIVE");
  else
    puts("DEAD");
  return 0;
}
