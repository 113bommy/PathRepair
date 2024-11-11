#include <bits/stdc++.h>
using namespace std;
int HP[2];
int ATK[2];
int DEF[2];
int main() {
  for (int i = 0; i < 2; ++i) {
    scanf("%d %d %d", HP + i, ATK + i, DEF + i);
  }
  int hc, ac, dc;
  scanf("%d %d %d", &hc, &ac, &dc);
  int ans = 1e9;
  for (int i = 0; i <= 100; ++i) {
    for (int j = 0; j <= 100; ++j) {
      int cur_ATK = ATK[0] + i, cur_DEF = DEF[0] + j;
      int cur_cost = i * ac + j * dc;
      int delta_M = max(0, cur_ATK - DEF[1]),
          delta_Y = max(0, ATK[1] - cur_DEF);
      if (delta_M == 0) {
        continue;
      }
      if (delta_Y != 0) {
        int diff =
            (HP[1] + delta_M - 1) / delta_M - (HP[0] + delta_Y - 1) / delta_Y;
        if (diff >= 0) {
          cur_cost += hc * ((delta_Y - HP[0] % delta_Y) % delta_Y + 1);
          cur_cost += hc * diff * delta_Y;
        }
      }
      if (cur_cost < ans) {
        ans = cur_cost;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
