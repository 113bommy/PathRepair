#include <bits/stdc++.h>
using namespace std;
istream &in = cin;
int n, m, k;
char line[1000];
set<string> fnp;
map<string, string> vnt;
int dfs(vector<string> &pp, string nm, int c) {
  if (c == pp.size()) return fnp.find(nm) != fnp.end();
  return dfs(pp, nm + pp[c], c + 1) + dfs(pp, nm + "T", c + 1);
}
int main() {
  in >> n;
  in.getline(line, 1000);
  for (int i = 0; i < n; ++i) {
    string fn, tmp;
    memset(line, 0, sizeof(line));
    in.getline(line, 1000);
    for (int j = 0; line[j] != 0; ++j)
      if (line[j] == '(' || line[j] == ')' || line[j] == ',') line[j] = ' ';
    stringstream ss(line);
    ss >> tmp;
    ss >> fn;
    while (ss >> tmp) {
      if (tmp[0] == 'i') fn += "I";
      if (tmp[0] == 's') fn += "S";
      if (tmp[0] == 'd') fn += "D";
      if (tmp[0] == 'T') fn += "T";
    }
    fnp.insert(fn);
  }
  in >> m;
  in.getline(line, 1000);
  for (int i = 0; i < m; ++i) {
    memset(line, 0, sizeof(line));
    in.getline(line, 1000);
    for (int j = 0; line[j] != 0; ++j)
      if (line[j] == '(' || line[j] == ')' || line[j] == ',') line[j] = ' ';
    stringstream ss(line);
    string tmp1, tmp2;
    ss >> tmp1 >> tmp2;
    if (tmp1[0] == 'i') vnt[tmp2] = "I";
    if (tmp1[0] == 's') vnt[tmp2] = "S";
    if (tmp1[0] == 'd') vnt[tmp2] = "D";
    if (tmp1[0] == 'T') vnt[tmp2] = "T";
  }
  in >> k;
  in.getline(line, 1000);
  for (int i = 0; i < k; ++i) {
    int ret = 0;
    string pn, tmp;
    vector<string> pp, pt;
    memset(line, 0, sizeof(line));
    in.getline(line, 1000);
    for (int j = 0; line[j] != 0; ++j)
      if (line[j] == '(' || line[j] == ')' || line[j] == ',') line[j] = ' ';
    stringstream ss(line);
    ss >> pn;
    while (ss >> tmp) pp.push_back(tmp);
    for (int j = 0; j < pp.size(); ++j) pt.push_back(vnt[pp[j]]);
    ret = dfs(pt, pn, 0);
    cout << ret << endl;
  }
  return 0;
}
