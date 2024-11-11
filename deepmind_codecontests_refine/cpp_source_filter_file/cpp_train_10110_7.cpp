#include <bits/stdc++.h>
using namespace std;
map<string, int> skills;
int n, m;
double k;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    string name;
    int level;
    cin >> name >> level;
    level = (int)(k * level);
    if (level >= 100) skills[name] = level;
  }
  for (int i = 0; i < m; i++) {
    string name;
    cin >> name;
    if (skills.find(name) == skills.end()) skills[name] = 0;
  }
  cout << skills.size() << endl;
  for (map<string, int>::const_iterator it = skills.begin(); it != skills.end();
       it++)
    cout << it->first << " " << it->second << endl;
  return 0;
}
