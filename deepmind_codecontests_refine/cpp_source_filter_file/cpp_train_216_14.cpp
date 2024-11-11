#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const int INF = ((1 << 31) - 1);
const long long LLINF = (((1LL << 63) - 1LL));
const double eps = 1e-9;
const double PI = 3.14159265358979323846;
struct Item {
  string name;
  string class_;
  int atk, def, res;
  int size;
  void read() { cin >> name >> class_ >> atk >> def >> res >> size; }
  int get(int i) {
    if (i == 0) return atk;
    if (i == 1) return def;
    if (i == 2) return res;
    return -1;
  }
};
struct Man {
  string name, type, home;
  int bonus;
  void read() { cin >> name >> type >> bonus >> home; }
  bool operator<(Man A) const { return bonus < A.bonus; }
};
pair<int, vector<string> > getBest(vector<Item>& items, vector<Man>& men,
                                   int id) {
  int best_score = 0;
  vector<string> best_men;
  int ii = 0;
  for (int i = 0; i < items.size(); ++i) {
    vector<string> cur_men;
    int cur_score = items[i].get(id);
    for (int j = 0; j < men.size() && j < items[i].size; ++j) {
      cur_score += men[j].bonus;
      cur_men.push_back(men[j].name);
    }
    if (best_score <= cur_score) {
      best_score = cur_score;
      best_men = cur_men;
      ii = i;
    }
  }
  return pair<int, vector<string> >(ii, best_men);
}
int packTo(Item& item, vector<string>& men, vector<Man>& gladiators,
           vector<Man>& sentries, vector<Man>& physicians, int& i, int& j,
           int& k) {
  while (i < gladiators.size() && men.size() < item.size) {
    men.push_back(gladiators[i].name);
    ++i;
  }
  while (j < sentries.size() && men.size() < item.size) {
    men.push_back(sentries[j].name);
    ++j;
  }
  while (k < physicians.size() && men.size() < item.size) {
    men.push_back(physicians[k].name);
    ++k;
  }
  return -1;
}
void printV(vector<string>& s) {
  cout << " ";
  cout << s.size() << " ";
  for (int i = 0; i < s.size(); ++i) printf("%s ", s[i].c_str());
  cout << "\n";
}
void printV(vector<Man>& s) {
  cout << " ";
  cout << s.size() << " ";
  for (int i = 0; i < s.size(); ++i) printf("%s ", s[i].name.c_str());
  cout << "\n";
}
int main() {
  int n;
  cin >> n;
  vector<Item> weapons;
  vector<Item> armors;
  vector<Item> orb;
  int v = 0;
  map<string, pair<int, int> > dict_items;
  for (int i = 0; i < n; ++i) {
    Item A;
    A.read();
    if (A.class_[0] == 'w') {
      weapons.push_back(A);
      dict_items[A.name] = make_pair(0, weapons.size() - 1);
    } else if (A.class_[0] == 'a') {
      armors.push_back(A);
      dict_items[A.name] = make_pair(1, armors.size() - 1);
    } else if (A.class_[0] == 'o') {
      orb.push_back(A);
      dict_items[A.name] = make_pair(2, orb.size() - 1);
    } else
      assert(false);
    v += A.size;
  }
  vector<Man> gladiators;
  vector<Man> sentries;
  vector<Man> physicians;
  int m;
  cin >> m;
  vector<vector<Man> > weaponsMen(weapons.size());
  vector<vector<Man> > armorsMen(armors.size());
  vector<vector<Man> > orbsMen(orb.size());
  for (int i = 0; i < m; ++i) {
    Man B;
    B.read();
    int j = dict_items[B.home].second;
    int t = dict_items[B.home].first;
    if (t == 0)
      weaponsMen[j].push_back(B);
    else if (t == 1)
      armorsMen[j].push_back(B);
    else if (t == 2)
      orbsMen[j].push_back(B);
    if (B.type[0] == 'g')
      gladiators.push_back(B);
    else if (B.type[0] == 's')
      sentries.push_back(B);
    else if (B.type[0] == 'p')
      physicians.push_back(B);
    else
      assert(false);
  }
  if (m == v) {
    int best_weapon = -1, best_armor = -1, best_orb = -1;
    int best_weapon_index, best_armor_index, best_orb_index;
    for (int i = 0; i < weapons.size(); ++i) {
      for (int j = 0; j < weaponsMen[i].size(); ++j) {
        if (weaponsMen[i][j].type[0] == 'g')
          weapons[i].atk += weaponsMen[i][j].bonus;
      }
      if (best_weapon <= weapons[i].atk) {
        best_weapon = weapons[i].atk;
        best_weapon_index = i;
      }
    }
    for (int i = 0; i < armors.size(); ++i) {
      for (int j = 0; j < armorsMen[i].size(); ++j) {
        if (armorsMen[i][j].type[0] == 's')
          armors[i].def += armorsMen[i][j].bonus;
      }
      if (best_armor <= armors[i].def) {
        best_armor <= armors[i].def;
        best_armor_index = i;
      }
    }
    for (int i = 0; i < orb.size(); ++i) {
      for (int j = 0; j < orbsMen[i].size(); ++j) {
        if (orbsMen[i][j].type[0] == 'p') orb[i].res += orbsMen[i][j].bonus;
      }
      if (best_orb <= orb[i].res) {
        best_orb <= orb[i].res;
        best_orb_index = i;
      }
    }
    cout << weapons[best_weapon_index].name << " ";
    printV(weaponsMen[best_weapon_index]);
    cout << armors[best_armor_index].name << " ";
    printV(armorsMen[best_armor_index]);
    cout << orb[best_orb_index].name << " ";
    printV(orbsMen[best_orb_index]);
  } else {
    sort((gladiators).begin(), (gladiators).end());
    reverse((gladiators).begin(), (gladiators).end());
    sort((sentries).begin(), (sentries).end());
    reverse((sentries).begin(), (sentries).end());
    sort((physicians).begin(), (physicians).end());
    reverse((physicians).begin(), (physicians).end());
    pair<int, vector<string> > a = getBest(weapons, gladiators, 0);
    pair<int, vector<string> > b = getBest(armors, sentries, 1);
    pair<int, vector<string> > c = getBest(orb, physicians, 2);
    int i = a.second.size();
    int j = b.second.size();
    int k = c.second.size();
    packTo(weapons[a.first], a.second, gladiators, sentries, physicians, i, j,
           k);
    packTo(armors[b.first], b.second, gladiators, sentries, physicians, i, j,
           k);
    packTo(orb[c.first], c.second, gladiators, sentries, physicians, i, j, k);
    cout << weapons[a.first].name;
    printV(a.second);
    cout << armors[b.first].name;
    printV(b.second);
    cout << orb[c.first].name;
    printV(c.second);
  }
  return 0;
}
