#include <bits/stdc++.h>
using namespace std;
struct spaceship {
  long defense;
  long gold;
  bool operator<(const spaceship& next) const { return defense < next.defense; }
};
int main() {
  long attack[100001];
  spaceship ships[100001];
  spaceship maxGold[100001];
  int s, b;
  cin >> s >> b;
  for (int i = 0; i < s; i++) {
    cin >> attack[i];
  }
  for (int i = 0; i < b; i++) {
    long d, g;
    cin >> d >> g;
    spaceship ship;
    ship.defense = d;
    ship.gold = g;
    ships[i] = ship;
  }
  sort(ships, ships + b);
  int goldCount = 0;
  for (int i = 0; i < b; i++) {
    goldCount += ships[i].gold;
    spaceship maxGold_i;
    maxGold_i.defense = ships[i].defense;
    maxGold_i.gold = goldCount;
    maxGold[i] = maxGold_i;
  }
  for (int i = 0; i < s; i++) {
    spaceship query;
    query.defense = attack[i];
    query.gold = 0;
    spaceship s = *(upper_bound(maxGold, maxGold + b, query) - 1);
    cout << s.gold << '\n';
  }
  return 0;
}
