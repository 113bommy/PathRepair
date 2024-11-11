#include <bits/stdc++.h>
using namespace std;
int a[8][6] = {{0, 1, 2, 3, 4, 5}, {0, 1, 3, 4, 5, 2}, {0, 1, 4, 5, 2, 3},
               {0, 1, 5, 2, 3, 4}, {1, 0, 5, 4, 3, 2}, {1, 0, 4, 3, 2, 5},
               {1, 0, 3, 2, 5, 4}, {1, 0, 2, 5, 4, 3}};
vector<vector<int> > vv;
string normal(const string& p) {
  string res = p;
  for (int i = 0; i < 24; ++i) {
    string pp;
    for (int j = 0; j < 6; ++j) {
      pp.push_back(p[vv[i][j]]);
    }
    if (pp < res) res = pp;
  }
  return res;
}
int main() {
  int r1[] = {0, 1, 2, 3, 4, 5, 6};
  for (int i = 0; i < 8; ++i) {
    vv.resize(vv.size() + 1);
    vector<int>& v = vv.back();
    for (int j = 0; j < 6; ++j) {
      v.push_back(r1[a[i][j]]);
    }
  }
  int r2[] = {3, 5, 1, 4, 0, 2};
  for (int i = 0; i < 8; ++i) {
    vv.resize(vv.size() + 1);
    vector<int>& v = vv.back();
    for (int j = 0; j < 6; ++j) {
      v.push_back(r2[a[i][j]]);
    }
  }
  int r3[] = {2, 4, 1, 3, 0, 5};
  for (int i = 0; i < 8; ++i) {
    vv.resize(vv.size() + 1);
    vector<int>& v = vv.back();
    for (int j = 0; j < 6; ++j) {
      v.push_back(r3[a[i][j]]);
    }
  }
  string s;
  cin >> s;
  set<string> ss;
  do {
    string perm;
    for (int i = 0; i < 6; ++i) {
      perm.push_back(s[r1[i]]);
    }
    ss.insert(normal(perm));
  } while (next_permutation(r1, r1 + 6));
  cout << ss.size();
  return 0;
};
