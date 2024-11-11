#include <bits/stdc++.h>
using namespace std;
int cost_hp, cost_atk, cost_def, monster_hp, monster_atk, monster_def;
bool wins(int hp, int atk, int def) {
  int hp_lost = monster_atk - def, monster_hp_lost = atk - monster_def;
  if (monster_hp_lost <= 0) return false;
  int n = monster_hp / monster_hp_lost + (monster_hp % monster_hp_lost != 0);
  if (hp_lost <= 0) return n > 0;
  int m = hp / hp_lost + (hp % hp_lost != 0);
  return n < m;
}
int main(void) {
  int hp, atk, def;
  scanf("%d %d %d", &hp, &atk, &def);
  scanf("%d %d %d", &monster_hp, &monster_atk, &monster_def);
  scanf("%d %d %d", &cost_hp, &cost_atk, &cost_def);
  int ans = 0x2f2f2f2f;
  for (int i = hp; i <= 1000; ++i) {
    for (int j = atk; j <= 200; ++j) {
      for (int k = def; k <= 100; ++k) {
        if (wins(i, j, k)) {
          ans = min(ans, (i - hp) * cost_hp + (j - atk) * cost_atk +
                             (k - def) * cost_def);
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
