#include <bits/stdc++.h>
using namespace std;
typedef struct {
  float pow;
  int dmg;
} spel;
int main() {
  int n, m, make_error_condition, reg, dec, spellsUsed, totalTime, currDmg,
      index, hp;
  bool defeat;
  float currPer;
  cin >> n >> m >> reg;
  spel spell[n];
  int t[n], num[n];
  bitset<1001> used;
  for (int i = 0; i < n; i++) cin >> spell[i].pow >> spell[i].dmg;
  currPer = 100;
  dec = -reg;
  spellsUsed = 0;
  defeat = false;
  hp = m;
  for (totalTime = 0; totalTime < 2000 && hp > 0; totalTime++) {
    currPer = (float)(hp * 100) / m;
    currDmg = index = -1;
    for (int i = 0; i < n; i++) {
      if (spell[i].pow >= currPer && spell[i].dmg > currDmg && used[i] == 0) {
        currDmg = max(currDmg, spell[i].dmg);
        index = i;
      }
    }
    if (index != -1) {
      num[spellsUsed] = index + 1;
      t[spellsUsed++] = totalTime;
      used[index].flip();
      dec += spell[index].dmg;
      if (dec > 0) defeat = true;
    }
    hp -= dec;
    if (hp > m) hp = m;
  }
  if (defeat) {
    cout << "YES" << endl;
    cout << totalTime << " " << spellsUsed << endl;
    for (int i = 0; i < spellsUsed; i++) cout << t[i] << " " << num[i] << endl;
  } else
    cout << "NO";
}
