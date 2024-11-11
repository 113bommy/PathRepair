#include <bits/stdc++.h>
using namespace std;
struct scroll {
  int id;
  int power;
  int damage;
  bool operator<(const scroll &a) const {
    if (damage == a.damage) {
      return id > a.id;
    }
    return damage < a.damage;
  }
} scrolls[1005];
struct ans {
  int time;
  int id;
};
int cmp(const scroll &a, const scroll &b) { return a.power > b.power; }
int main() {
  int n, health, reg;
  cin >> n >> health >> reg;
  for (int i = 0; i < n; i++) {
    scrolls[i].id = i;
    cin >> scrolls[i].power >> scrolls[i].damage;
  }
  sort(scrolls, scrolls + n, cmp);
  priority_queue<scroll> pend;
  queue<ans> a;
  int damage = 0;
  int i = 0;
  int tick = 0;
  int hp = health;
  while (health > 0) {
    while (scrolls[i].power >= ceil(health * 100.0 / hp) && i < n) {
      pend.push(scrolls[i]);
      i++;
    }
    if (pend.size()) {
      damage += pend.top().damage;
      ans tmp;
      tmp.id = pend.top().id;
      tmp.time = tick;
      a.push(tmp);
      pend.pop();
    }
    if (damage <= reg && pend.size() == 0) {
      cout << "NO";
      return 0;
    }
    health -= max(0, damage - reg);
    tick++;
  }
  cout << "YES" << endl;
  cout << tick << " " << a.size() << endl;
  while (a.size()) {
    cout << a.front().time << " " << a.front().id + 1 << endl;
    a.pop();
  }
  return 0;
}
