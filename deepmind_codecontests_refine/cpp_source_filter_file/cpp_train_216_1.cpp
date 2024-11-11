#include <bits/stdc++.h>
using namespace std;
const string weapon = "weapon", armor = "armor", orb = "orb";
struct resident {
  string type, name;
  int bonus;
};
struct item {
  string type, name;
  vector<resident> what;
  int val, size;
};
int n, k, sumVolume = 0;
vector<item> a;
item bestArmor, bestWeapon, bestOrb;
vector<resident> b;
set<string> used;
vector<resident> weaponRes, armorRes, orbRes;
bool betterBy_weapon(const resident &a, const resident &b) {
  if (a.type == weapon && b.type != weapon) return true;
  if (a.type == weapon && b.type == weapon) return a.bonus > b.bonus;
  if (a.type != weapon && b.type == weapon) return false;
  if (a.type != weapon && b.type != weapon) return false;
}
bool betterBy_armor(const resident &a, const resident &b) {
  if (a.type == armor && b.type != armor) return true;
  if (a.type == armor && b.type == armor) return a.bonus > b.bonus;
  if (a.type != armor && b.type == armor) return false;
  if (a.type != armor && b.type != armor) return false;
}
bool betterBy_orb(const resident &a, const resident &b) {
  if (a.type == orb && b.type != orb) return true;
  if (a.type == orb && b.type == orb) return a.bonus > b.bonus;
  if (a.type != orb && b.type == orb) return false;
  if (a.type != orb && b.type != orb) return false;
}
void print(item &t) {
  cout << t.name << ' ' << t.what.size() << ' ';
  for (int i = 0; i < t.what.size(); i++) cout << t.what[i].name << ' ';
  cout << endl;
}
item findBest(const string &type) {
  item res;
  int ma = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].type == type) {
      int val = a[i].val;
      for (int j = 0; j < min(k, a[i].size) && b[j].type == type; j++)
        val += b[j].bonus;
      if (val > ma) {
        ma = val;
        res = a[i];
      }
    }
  }
  for (int j = 0; j < min(k, res.size) && b[j].type == type; j++) {
    used.insert(b[j].name);
    res.what.push_back(b[j]);
  }
  return res;
}
void filll(item &t) {
  for (int i = 0; i < k; i++) {
    if (t.what.size() == t.size) return;
    if (used.find(b[i].name) == used.end()) {
      used.insert(b[i].name);
      t.what.push_back(b[i]);
    }
  }
}
item findBest2(const string &type) {
  item res;
  int ma = -1;
  for (int i = 0; i < n; i++) {
    if (a[i].type == type) {
      int val = a[i].val;
      for (int j = 0; j < a[i].what.size(); j++)
        if (a[i].what[j].type == type) val += a[i].what[j].bonus;
      if (val > ma) {
        res = a[i];
        ma = val;
      }
    }
  }
  return res;
}
int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].name >> a[i].type;
    int atk, def, res;
    cin >> atk >> def >> res >> a[i].size;
    sumVolume += a[i].size;
    if (a[i].type == weapon)
      a[i].val = atk;
    else if (a[i].type == armor)
      a[i].val = def;
    else
      a[i].val = res;
  }
  cin >> k;
  b.resize(k);
  for (int i = 0; i < k; i++) {
    string home;
    cin >> b[i].name >> b[i].type >> b[i].bonus >> home;
    if (b[i].type[0] == 'g')
      b[i].type = weapon;
    else if (b[i].type[0] == 's')
      b[i].type = armor;
    else
      b[i].type = orb;
    for (int j = 0; j < n; j++)
      if (a[j].name == home) {
        a[j].what.push_back(b[i]);
        break;
      }
  }
  if (k == sumVolume) {
    item bestWeapon = findBest2(weapon);
    item bestArmor = findBest2(armor);
    item bestOrb = findBest2(orb);
    print(bestWeapon);
    print(bestArmor);
    print(bestOrb);
    return 0;
  }
  for (int i = 0; i < n; i++) a[i].what.clear();
  sort(b.begin(), b.end(), betterBy_weapon);
  item bestWeapon = findBest(weapon);
  sort(b.begin(), b.end(), betterBy_armor);
  item bestArmor = findBest(armor);
  sort(b.begin(), b.end(), betterBy_orb);
  bestOrb = findBest(orb);
  filll(bestWeapon);
  filll(bestArmor);
  filll(bestOrb);
  print(bestWeapon);
  print(bestArmor);
  print(bestOrb);
}
