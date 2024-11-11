#include <bits/stdc++.h>
using namespace std;
int hp_y, atk_y, def_y, hp_m, atk_m, def_m, hp_cost, atk_cost, def_cost, ans;
bool win(int p1_hp, int p1_atk, int p1_def, int p2_hp, int p2_atk, int p2_def) {
  if (p1_def > p2_atk && p1_atk > p2_def) {
    return (true);
  }
  int prev_hp1 = -1;
  int prev_hp2 = -1;
  while (true) {
    p1_hp -= max(0, p2_atk - p1_def);
    p2_hp -= max(0, p1_atk - p2_def);
    if (prev_hp1 == p1_hp && prev_hp2 == p2_hp) {
      break;
    }
    if (p1_hp <= 0 || p2_hp <= 0) {
      break;
    }
    prev_hp1 = p1_hp;
    prev_hp2 = p2_hp;
  }
  return (p1_hp > 0 && p2_hp <= 0);
}
int main() {
  scanf("%d %d %d", &hp_y, &atk_y, &def_y);
  scanf("%d %d %d", &hp_m, &atk_m, &def_m);
  scanf("%d %d %d", &hp_cost, &atk_cost, &def_cost);
  int start_val = 0;
  if (atk_y < def_m) {
    start_val = def_m - atk_y;
  }
  ans = -1;
  for (int i = 0; i <= 1000; ++i) {
    for (int j = start_val; atk_y + j <= 200; ++j) {
      for (int k = 0; def_y + k <= 200; ++k) {
        if (win(hp_y + i, atk_y + j, def_y + k, hp_m, atk_m, def_m)) {
          int cost = i * hp_cost + j * atk_cost + k * def_cost;
          if (ans == -1 || ans > cost) {
            ans = cost;
          }
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
