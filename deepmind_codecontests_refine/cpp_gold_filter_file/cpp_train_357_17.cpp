#include <bits/stdc++.h>
using namespace std;
int yang[3], monster[3], price[3];
bool simulate(int hp, int atk, int def) {
  int dmg_given = max(0, atk - monster[2]);
  int dmg_taken = max(0, monster[1] - def);
  int hp_monst = monster[0];
  while (hp_monst > 0) {
    hp -= dmg_taken;
    hp_monst -= dmg_given;
  }
  if (hp > 0) return true;
  return false;
}
int main() {
  for (int i = 0; i < 3; i++) cin >> yang[i];
  for (int i = 0; i < 3; i++) cin >> monster[i];
  for (int i = 0; i < 3; i++) cin >> price[i];
  int atk_buffer = max(-1, monster[2] - yang[1]);
  int def_limit = max(0, monster[1] - yang[2]);
  int res = 1000000000;
  for (int atk = atk_buffer + 1; atk <= monster[2] + 100; atk++) {
    for (int def = 0; def <= def_limit; def++) {
      int cost = atk * price[1] + def * price[2];
      if (cost >= res) continue;
      int low = yang[0];
      int high = 1000000000;
      while (abs(high - low) > 1) {
        int avg = (high + low) / 2;
        if (simulate(avg, yang[1] + atk, yang[2] + def))
          high = avg;
        else
          low = avg;
      }
      int hp_req;
      if (simulate(low, yang[1] + atk, yang[2] + def))
        hp_req = low;
      else
        hp_req = high;
      cost += (hp_req - yang[0]) * price[0];
      res = min(res, cost);
    }
  }
  cout << res << endl;
  return 0;
}
