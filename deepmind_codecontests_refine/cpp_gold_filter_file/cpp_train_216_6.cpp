#include <bits/stdc++.h>
#pragma comment(linker, "/stack:32000000")
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int ST = 10000005;
const int ST1 = 20000100;
const long long MOD = 1000000007;
struct Resident {
  string name;
  string type;
  int bonus;
  string home;
  int homeIndex;
};
struct Thing {
  string name;
  string type;
  int value;
  int size;
  vector<Resident> citizen;
};
int n, k, freeSlots;
Thing thing, bestW, bestA, bestO;
vector<Thing> t;
vector<Resident> r;
vector<int> wap, def, orb, other;
int col[15];
bool sortW(int a, int b) {
  if (r[a].type != "weapon") {
    return false;
  }
  if (r[b].type != "weapon") {
    return true;
  }
  return (r[a].bonus > r[b].bonus);
}
bool sortA(int a, int b) {
  if (r[a].type != "armor") {
    return false;
  }
  if (r[b].type != "armor") {
    return true;
  }
  return (r[a].bonus > r[b].bonus);
}
bool sortO(int a, int b) {
  if (r[a].type != "orb") {
    return false;
  }
  if (r[b].type != "orb") {
    return true;
  }
  return (r[a].bonus > r[b].bonus);
}
int GetThingIndex(string name) {
  for (int i = 0; true; ++i) {
    if (t[i].name == name) {
      return i;
    }
  }
}
void ReadThings() {
  cin >> n;
  Thing thing;
  string name;
  string type;
  int atk;
  int def;
  int res;
  int sz;
  for (int i = 0; i < n; ++i) {
    cin >> name >> type >> atk >> def >> res >> sz;
    thing.name = name;
    thing.type = type;
    thing.size = sz;
    thing.citizen.clear();
    if (type == "weapon") {
      thing.value = atk;
    }
    if (type == "armor") {
      thing.value = def;
    }
    if (type == "orb") {
      thing.value = res;
    }
    t.push_back(thing);
    freeSlots += thing.size;
  }
}
void ReadResidents() {
  cin >> k;
  freeSlots -= k;
  Resident rz;
  string name;
  string type;
  string home;
  int bonus;
  for (int i = 0; i < k; ++i) {
    wap.push_back(i);
    cin >> name >> type >> bonus >> home;
    if (type == "gladiator") {
      type = "weapon";
    }
    if (type == "sentry") {
      type = "armor";
    }
    if (type == "physician") {
      type = "orb";
    }
    rz.type = type;
    rz.name = name;
    rz.bonus = bonus;
    rz.home = home;
    rz.homeIndex = GetThingIndex(home);
    r.push_back(rz);
    t[rz.homeIndex].citizen.push_back(rz);
  }
}
void WriteResults() {
  cout << bestW.name << " " << bestW.citizen.size() << " ";
  for (int i = 0; i < bestW.citizen.size(); ++i) {
    if (i > 0) {
      cout << " ";
    }
    cout << bestW.citizen[i].name;
  }
  cout << endl;
  cout << bestA.name << " " << bestA.citizen.size() << " ";
  for (int i = 0; i < bestA.citizen.size(); ++i) {
    if (i > 0) {
      cout << " ";
    }
    cout << bestA.citizen[i].name;
  }
  cout << endl;
  cout << bestO.name << " " << bestO.citizen.size() << " ";
  for (int i = 0; i < bestO.citizen.size(); ++i) {
    if (i > 0) {
      cout << " ";
    }
    cout << bestO.citizen[i].name;
  }
  cout << endl;
}
int main() {
  ReadThings();
  ReadResidents();
  if (freeSlots > 0) {
    bestW.value = -1;
    bestA.value = -1;
    bestO.value = -1;
    sort(wap.begin(), wap.end(), sortW);
    for (int i = 0; i <= 10; ++i) {
      col[i] = 0;
    }
    for (int i = 1; i <= 10; ++i) {
      col[i] = col[i - 1];
      if ((i - 1 < wap.size()) && (r[wap[i - 1]].type == "weapon")) {
        col[i] += r[wap[i - 1]].bonus;
      }
    }
    for (int i = 0; i < t.size(); ++i) {
      t[i].citizen.clear();
      if ((t[i].type == "weapon") &&
          (t[i].value + col[t[i].size] > bestW.value + col[bestW.size])) {
        bestW = t[i];
      }
    }
    int ind = 0;
    while ((ind < wap.size()) && (r[wap[ind]].type == "weapon") &&
           (ind < bestW.size)) {
      bestW.citizen.push_back(r[wap[ind]]);
      ++ind;
    }
    for (int i = ind; i < wap.size(); ++i) {
      def.push_back(wap[i]);
    }
    sort(def.begin(), def.end(), sortA);
    for (int i = 0; i <= 10; ++i) {
      col[i] = 0;
    }
    for (int i = 1; i <= 10; ++i) {
      col[i] = col[i - 1];
      if ((i - 1 < def.size()) && (r[def[i - 1]].type == "armor")) {
        col[i] += r[def[i - 1]].bonus;
      }
    }
    for (int i = 0; i < t.size(); ++i) {
      t[i].citizen.clear();
      if ((t[i].type == "armor") &&
          (t[i].value + col[t[i].size] > bestA.value + col[bestA.size])) {
        bestA = t[i];
      }
    }
    ind = 0;
    while ((ind < def.size()) && (r[def[ind]].type == "armor") &&
           (ind < bestA.size)) {
      bestA.citizen.push_back(r[def[ind]]);
      ++ind;
    }
    for (int i = ind; i < def.size(); ++i) {
      orb.push_back(def[i]);
    }
    sort(orb.begin(), orb.end(), sortO);
    for (int i = 0; i <= 10; ++i) {
      col[i] = 0;
    }
    for (int i = 1; i <= 10; ++i) {
      col[i] = col[i - 1];
      if ((i - 1 < orb.size()) && (r[orb[i - 1]].type == "orb")) {
        col[i] += r[orb[i - 1]].bonus;
      }
    }
    for (int i = 0; i < t.size(); ++i) {
      t[i].citizen.clear();
      if ((t[i].type == "orb") &&
          (t[i].value + col[t[i].size] > bestO.value + col[bestO.size])) {
        bestO = t[i];
      }
    }
    ind = 0;
    while ((ind < orb.size()) && (r[orb[ind]].type == "orb") &&
           (ind < bestO.size)) {
      bestO.citizen.push_back(r[orb[ind]]);
      ++ind;
    }
    for (int i = ind; i < orb.size(); ++i) {
      other.push_back(orb[i]);
    }
    ind = 0;
    while ((ind < other.size()) && (bestW.citizen.size() != bestW.size)) {
      bestW.citizen.push_back(r[other[ind]]);
      ++ind;
    }
    while ((ind < other.size()) && (bestA.citizen.size() != bestA.size)) {
      bestA.citizen.push_back(r[other[ind]]);
      ++ind;
    }
    while ((ind < other.size()) && (bestO.citizen.size() != bestO.size)) {
      bestO.citizen.push_back(r[other[ind]]);
      ++ind;
    }
  } else {
    bestW.value = -1;
    bestA.value = -1;
    bestO.value = -1;
    for (int i = 0; i < t.size(); ++i) {
      int val = t[i].value;
      for (int j = 0; j < t[i].citizen.size(); ++j) {
        if (t[i].type == t[i].citizen[j].type) {
          val += t[i].citizen[j].bonus;
        }
      }
      if ((t[i].type == "weapon") && (bestW.value < val)) {
        bestW = t[i];
        bestW.value = val;
      }
      if ((t[i].type == "armor") && (bestA.value < val)) {
        bestA = t[i];
        bestA.value = val;
      }
      if ((t[i].type == "orb") && (bestO.value < val)) {
        bestO = t[i];
        bestO.value = val;
      }
    }
  }
  WriteResults();
  return 0;
}
