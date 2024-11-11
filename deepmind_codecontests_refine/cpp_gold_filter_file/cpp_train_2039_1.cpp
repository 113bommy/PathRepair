#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<pair<string, string>, int> > v;
  string tmp1, tmp2;
  for (int i = 0; i < n; i++) {
    cin >> tmp1 >> tmp2;
    v.push_back({{tmp1, tmp2}, i});
  }
  sort(v.begin(), v.end());
  int i = 0;
  int j = i + 1;
  map<string, int> sf;
  while (i < n) {
    j = i + 1;
    while (j < n && v[i].first.first[0] == v[j].first.first[0]) {
      j++;
    }
    set<string> s;
    int flag = 0;
    for (int k = i; k < j; k++) {
      string res = "";
      res += v[k].first.first[0];
      res += v[k].first.first[1];
      res += v[k].first.second[0];
      if (s.find(res) == s.end())
        s.insert(res);
      else {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      for (int k = i; k < j; k++) {
        string res = "";
        res += v[k].first.first[0];
        res += v[k].first.first[1];
        res += v[k].first.second[0];
        sf[res] = v[k].second;
      }
    } else {
      for (int k = i; k < j; k++) {
        string res = "";
        res += v[k].first.first[0];
        res += v[k].first.first[1];
        res += v[k].first.first[2];
        if (sf.find(res) == sf.end()) {
          sf[res] = v[k].second;
        } else {
          cout << "NO";
          return 0;
        }
      }
    }
    i = j;
  }
  string str[n];
  for (auto it = sf.begin(); it != sf.end(); it++) {
    str[it->second] = it->first;
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    cout << str[i] << endl;
  }
  return 0;
}
