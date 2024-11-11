#include <bits/stdc++.h>
using namespace std;
vector<string> sv[2];
vector<string> oh[2];
vector<string> er[2];
set<string> ss[2];
vector<pair<string, int> > v;
vector<string> res;
string f(int a) {
  if (a == 0) return "0";
  string s = "";
  while (a > 0) {
    s += '0' + a % 10;
    a /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
int main() {
  int n;
  cin >> n;
  v.reserve(n + 3);
  sv[0].reserve(n + 3);
  sv[1].reserve(n + 3);
  oh[0].reserve(n + 3);
  oh[1].reserve(n + 3);
  er[0].reserve(n + 3);
  er[1].reserve(n + 3);
  res.reserve(n + 3);
  string s;
  int t;
  int prim = 0;
  int test = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s >> t;
    v.push_back(make_pair(s, t));
    if (t == 1)
      ++prim;
    else
      ++test;
  }
  string prims = f(prim);
  string tests = f(test);
  for (int i = 1; i <= prim; ++i) ss[0].insert(f(i));
  for (int i = prim + 1; i <= n; ++i) ss[1].insert(f(i));
  for (int i = 0; i < n; ++i) {
    s = v[i].first;
    t = v[i].second;
    if (ss[0].find(s) != ss[0].end()) {
      if (t == 0) oh[0].push_back(s);
      ss[0].erase(s);
    } else if (ss[1].find(s) != ss[1].end()) {
      if (t == 1) oh[1].push_back(s);
      ss[1].erase(s);
    } else {
      if (t == 1)
        er[0].push_back(s);
      else
        er[1].push_back(s);
    }
  }
  for (set<string>::iterator it = ss[0].begin(); it != ss[0].end(); it++)
    sv[0].push_back(*it);
  for (set<string>::iterator it = ss[1].begin(); it != ss[1].end(); it++)
    sv[1].push_back(*it);
  s = "";
  if (sv[0].size() == 0 && sv[1].size() == 0) {
    if (oh[0].size() > 0) {
      sv[0].push_back(oh[0][oh[0].size() - 1]);
      er[1].push_back("aaaaaf");
      oh[0].pop_back();
      res.push_back("move " + sv[0][0] + " aaaaaf");
    } else if (oh[1].size() > 0) {
      sv[1].push_back(oh[1][oh[1].size() - 1]);
      er[0].push_back("aaaaaf");
      oh[1].pop_back();
      res.push_back(s + "move " + sv[1][0] + " aaaaaf");
    }
  }
  while (sv[0].size() != 0 || sv[1].size() != 0) {
    if (sv[0].size() != 0 && oh[1].size() != 0) {
      res.push_back("move " + oh[1][oh[1].size() - 1] + " " +
                    sv[0][sv[0].size() - 1]);
      sv[0].pop_back();
      sv[1].push_back(oh[1][oh[1].size() - 1]);
      oh[1].pop_back();
    } else if (sv[1].size() != 0 && oh[0].size() != 0) {
      res.push_back("move " + oh[0][oh[0].size() - 1] + " " +
                    sv[1][sv[1].size() - 1]);
      sv[1].pop_back();
      sv[0].push_back(oh[0][oh[0].size() - 1]);
      oh[0].pop_back();
    } else {
      while (sv[0].size() > 0) {
        res.push_back("move " + er[0][er[0].size() - 1] + " " +
                      sv[0][sv[0].size() - 1]);
        sv[0].pop_back();
        er[0].pop_back();
      }
      while (sv[1].size() > 0) {
        res.push_back("move " + er[1][er[1].size() - 1] + " " +
                      sv[1][sv[1].size() - 1]);
        sv[1].pop_back();
        er[1].pop_back();
      }
    }
  }
  cout << res.size();
  for (int i = 0; i < res.size(); ++i) cout << '\n' << res[i];
  return 0;
}
