#include <bits/stdc++.h>
using namespace std;
class NUM {
 public:
  int you, me;
};
vector<string> s1, s2;
map<string, NUM> map1, map2;
int main() {
  int tree, vec;
  int T;
  int ans;
  string temp, ch;
  NUM info;
  temp.erase();
  s1.push_back(temp);
  s2.push_back(temp);
  cin >> T;
  while (T--) {
    cin >> tree >> vec >> ch;
    if (tree == 1) {
      temp = ch + s1[vec - 1];
      s1.push_back(temp);
      if ((map1.find(temp)) == map1.end()) {
        info.me = 1;
        if ((map2.find(temp)) == map2.end()) {
          info.you = 0;
          map1[temp] = info;
        } else {
          info.you = map2[temp].me;
          map1[temp] = info;
          ans += info.you;
          info.you = 1;
          info.me = map2[temp].me;
          map2[temp] = info;
        }
      } else {
        info.me = map1[temp].me + 1;
        if ((map2.find(temp)) == map2.end()) {
          info.you = 0;
          map1[temp] = info;
        } else {
          info.you = map2[temp].me;
          map1[temp] = info;
          ans += info.you;
          info.you = info.me;
          info.me = map2[temp].me;
          map2[temp] = info;
        }
      }
    } else {
      ans++;
      temp = s2[vec - 1] + ch;
      s2.push_back(temp);
      while (temp.size()) {
        if ((map2.find(temp)) == map2.end()) {
          info.me = 1;
          if ((map1.find(temp)) == map1.end()) {
            info.you = 0;
            map2[temp] = info;
          } else {
            info.you = map1[temp].me;
            map2[temp] = info;
            ans += info.you;
            info.you = 1;
            info.me = map1[temp].me;
            map1[temp] = info;
          }
        } else {
          info.me = map2[temp].me + 1;
          if ((map1.find(temp)) == map1.end()) {
            info.you = 0;
            map2[temp] = info;
          } else {
            info.you = map1[temp].me;
            map2[temp] = info;
            ans += info.you;
            info.you = info.me;
            info.me = map1[temp].me;
            map1[temp] = info;
          }
        }
        temp.erase(temp.begin());
      }
    }
    cout << ans << endl;
  }
  return 0;
}
