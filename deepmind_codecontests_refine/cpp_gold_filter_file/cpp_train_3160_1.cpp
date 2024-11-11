#include <bits/stdc++.h>
using namespace std;
multimap<string, vector<string> > proc;
map<string, string> var;
int main() {
  int n, m, k;
  scanf("%d", &n);
  while (getchar() != '\n')
    ;
  while (n--) {
    string line;
    getline(cin, line);
    for (int i = 0; i < line.size(); ++i)
      if (!isalnum(line[i])) line[i] = ' ';
    line += " )";
    stringstream ss(line);
    string s;
    ss >> s;
    string name;
    ss >> name;
    vector<string> v;
    while (ss >> s, s != ")") v.push_back(s);
    proc.insert(make_pair(name, v));
  }
  scanf("%d", &m);
  while (m--) {
    string name, x;
    cin >> name >> x;
    var[x] = name;
  }
  scanf("%d", &n);
  while (getchar() != '\n')
    ;
  while (n--) {
    string line;
    getline(cin, line);
    for (int i = 0; i < line.size(); ++i)
      if (!isalnum(line[i])) line[i] = ' ';
    line += " )";
    stringstream ss(line);
    string s;
    string name;
    ss >> name;
    vector<string> v;
    while (ss >> s, s != ")") v.push_back(var[s]);
    multimap<string, vector<string> >::iterator x, y, it;
    x = proc.lower_bound(name);
    y = proc.upper_bound(name);
    int res = 0;
    for (it = x; it != y; ++it) {
      vector<string> tmp = it->second;
      if (tmp.size() != v.size()) continue;
      bool ok = 1;
      for (int i = 0; i < tmp.size(); ++i)
        if (tmp[i] != v[i] && tmp[i] != "T") {
          ok = 0;
          break;
        }
      res += ok;
    }
    printf("%d\n", res);
  }
  return 0;
}
