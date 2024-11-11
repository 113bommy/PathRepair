#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
vector<vector<int> > nest;
pair<int, int> recur(int num) {
  pair<int, int> res;
  res.first = res.second = 0;
  for (int i = 0; i < ((int)((int)nest[num].size())); i++) {
    pair<int, int> p = recur(nest[num][i]);
    res.first += p.first;
    res.second += p.second;
  }
  if (res.first == 0 && res.second == 0)
    res.second++;
  else
    res.first++;
  return res;
}
int main() {
  char c[105];
  while (gets(c)) {
    string str = c, s = "", before = "";
    for (int i = 0; i < ((int)((int)str.size())); i++)
      if (str[i] == '\\') str[i] = ' ';
    stringstream ss;
    ss << str;
    while (ss >> str) {
      s += ((s == "") ? "" : "\\") + str;
      if (mp.find(s) == mp.end()) {
        mp[s] = ((int)nest.size());
        nest.push_back(vector<int>());
        if (before != "") nest[mp[before]].push_back(mp[s]);
      }
      before = s;
    }
  }
  int res0 = 0, res1 = 0;
  for (int i = 0; i < ((int)5); i++) {
    string str = string(1, 'C' + i);
    str += ":";
    if (mp.find(str) != mp.end()) {
      for (int j = 0; j < ((int)((int)nest[mp[str]].size())); j++) {
        pair<int, int> p = recur(nest[mp[str]][j]);
        res0 = max(res0, p.first - 1);
        res1 = max(res1, p.second);
      }
    }
  }
  cout << res0 << " " << res1 << endl;
}
