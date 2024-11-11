#include <bits/stdc++.h>
using namespace std;
struct sw {
  int id, pow, hp;
  bool was;
  bool operator<(const sw &sec) const {
    if (pow != sec.pow) {
      return pow > sec.pow;
    } else if (hp != sec.hp) {
      return hp > sec.hp;
    } else {
      return id < sec.id;
    }
  }
} arr[1002];
set<sw> S;
int ans[1002][2], q = 0;
int main() {
  int n, hp, reg, dmg = 0;
  cin >> n >> hp >> reg;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].hp >> arr[i].pow;
    arr[i].id = i + 1;
    arr[i].was = false;
  }
  int chp = hp;
  for (int i = 0; i <= 2005; i++) {
    chp -= dmg;
    chp += reg;
    chp = min(hp, chp);
    if (chp <= 0) {
      cout << "YES\n";
      cout << i << " " << q << endl;
      for (int j = 0; j < q; j++) {
        cout << ans[j][1] << " " << ans[j][0] << endl;
      }
      return 0;
    }
    for (int j = 0; j < n; j++) {
      if ((chp * 100.0) / hp <= arr[j].hp + 1e-8 && !arr[j].was) {
        arr[j].was = true;
        S.insert(arr[j]);
      }
    }
    if (!S.empty()) {
      set<sw>::iterator beg = S.begin();
      dmg += beg->pow;
      ans[q][0] = beg->id;
      ans[q][1] = i;
      S.erase(beg);
      q++;
    }
  }
  cout << "NO\n";
  return 0;
}
