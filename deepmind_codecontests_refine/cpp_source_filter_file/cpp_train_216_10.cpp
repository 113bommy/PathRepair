#include <bits/stdc++.h>
using namespace std;
struct item_t {
  int category;
  int skills[3];
  int size;
};
struct res_t {
  int type, bonus;
  string home;
};
map<string, item_t> item_map;
map<string, res_t> res_map;
void solve() {
  map<string, int> class_map, skill_map, type_map;
  class_map["weapon"] = 0;
  skill_map["atk"] = 0;
  type_map["gladiator"] = 0;
  class_map["armor"] = 1;
  skill_map["def"] = 1;
  type_map["sentry"] = 1;
  class_map["orb"] = 2;
  skill_map["res"] = 2;
  type_map["physician"] = 2;
  int n;
  cin >> n;
  item_map.clear();
  res_map.clear();
  map<string, int> cnt;
  for (int i = 0; i < n; ++i) {
    string name, category;
    int skills[3], size;
    cin >> name >> category >> skills[0] >> skills[1] >> skills[2] >> size;
    item_t item;
    item.category = class_map[category];
    for (int k = 0; k < 3; ++k) item.skills[k] = skills[k];
    item.size = size;
    item_map[name] = item;
    cnt[name] = 0;
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    string name, type, home;
    int bonus;
    cin >> name >> type >> bonus >> home;
    res_t res;
    res.type = type_map[type];
    res.bonus = bonus;
    res.home = home;
    res_map[name] = res;
  }
  bool istight = true;
  for (map<string, res_t>::const_iterator cit = res_map.begin();
       cit != res_map.end(); ++cit) {
    string home = cit->second.home;
    cnt[home]++;
  }
  for (map<string, int>::const_iterator cit = cnt.begin(); cit != cnt.end();
       ++cit) {
    if (item_map[cit->first].size > cit->second) {
      istight = false;
      break;
    }
  }
  if (istight) {
    string id[3];
    int score[3] = {0};
    for (map<string, item_t>::const_iterator cit = item_map.begin();
         cit != item_map.end(); ++cit) {
      string home = cit->first;
      int category = cit->second.category;
      int curr = cit->second.skills[category];
      for (map<string, res_t>::const_iterator it2 = res_map.begin();
           it2 != res_map.end(); ++it2) {
        if (it2->second.home == home) {
          int type = it2->second.type;
          int bonus = it2->second.bonus;
          if (category == type) curr += bonus;
        }
      }
      if (curr > score[category]) {
        id[category] = home;
        score[category] = curr;
      }
    }
    for (int i = 0; i < 3; ++i) {
      string home = id[i];
      cout << home << ' ' << item_map[home].size;
      for (map<string, res_t>::const_iterator it = res_map.begin();
           it != res_map.end(); ++it) {
        if (it->second.home == home) cout << ' ' << it->first;
      }
      cout << endl;
    }
  } else {
    vector<pair<int, string> > vec[3];
    for (map<string, res_t>::const_iterator it = res_map.begin();
         it != res_map.end(); ++it) {
      string name = it->first;
      int type = it->second.type;
      int bonus = it->second.bonus;
      vec[type].push_back(pair<int, string>(bonus, name));
    }
    for (int i = 0; i < 3; ++i) sort(vec[i].begin(), vec[i].end());
    map<string, bool> used;
    for (map<string, res_t>::const_iterator it = res_map.begin();
         it != res_map.end(); ++it) {
      used[it->first] = false;
    }
    string id[3];
    int score[3] = {0};
    for (map<string, item_t>::const_iterator it = item_map.begin();
         it != item_map.end(); ++it) {
      string home = it->first;
      int category = it->second.category;
      int size = it->second.size;
      int curr = it->second.skills[category];
      for (int k = vec[category].size() - 1, s = size; k >= 0 && s > 0;
           --k, --s) {
        curr += vec[category][k].first;
      }
      if (curr > score[category]) {
        id[category] = home;
        score[category] = curr;
      }
    }
    vector<string> ans[3];
    for (int i = 0; i < 3; ++i) {
      for (int k = vec[i].size() - 1, s = item_map[id[i]].size; k >= 0 && s > 0;
           --k, --s) {
        string name = vec[i][k].second;
        ans[i].push_back(name);
        used[name] = true;
      }
    }
    for (int i = 0; i < 3; ++i) {
      for (int k = int(ans[i].size()); k < item_map[id[i]].size; ++k)
        for (map<string, bool>::iterator it = used.begin(); it != used.end();
             ++it) {
          if (!it->second) {
            ans[i].push_back(it->first);
            it->second = true;
            break;
          }
        }
    }
    for (int i = 0; i < 3; ++i) {
      cout << id[i] << ' ' << ans[i].size();
      for (size_t k = 0; k < ans[i].size(); ++k) cout << ' ' << ans[i][k];
      cout << endl;
    }
  }
}
int main() { solve(); }
