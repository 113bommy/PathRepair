#include <bits/stdc++.h>
using namespace std;
int n = 0, m = 0;
vector<pair<pair<int, int>, vector<int> > > vsol;
vector<pair<string, int> > jokers;
vector<string> vd;
vector<char> Ranks = {'A', '2', '3', '4', '5', '6', '7',
                      '8', '9', 'T', 'J', 'Q', 'K'};
bool vis[100] = {0};
string fa[100];
bool overlap(vector<int> v1, vector<int> v2) {
  int freq[150] = {0};
  for (int i = 0; i < (int)v1.size(); i++)
    if ((++freq[v1[i]] > 1) || (++freq[v2[i]] > 1)) return 1;
  return 0;
}
bool solve2() {
  set<char> Rset1, Rset2;
  for (int i = 0; i < (int)vsol.size(); i++)
    for (int j = 0; j < (int)vsol.size(); j++) {
      if (overlap(vsol[i].second, vsol[j].second)) continue;
      bool d1 = 1, d2 = 1;
      for (int i = 0; i < (int)Ranks.size(); i++)
        Rset1.insert(Ranks[i]), Rset2.insert(Ranks[i]);
      for (int k = 0; k < (int)vsol[i].second.size(); k++)
        d1 &= Rset1.erase(fa[vsol[i].second[k]][0]);
      for (int k = 0; k < (int)vsol[j].second.size(); k++)
        d2 &= Rset2.erase(fa[vsol[j].second[k]][0]);
      Rset1.clear();
      Rset2.clear();
      if (!d1 || !d2) continue;
      cout << "Solution exists.\n";
      if (!jokers.size())
        cout << "There are no jokers.\n";
      else if (jokers.size() == 1)
        cout << "Replace " << jokers[0].first << " with "
             << fa[jokers[0].second] << ".\n";
      else
        cout << "Replace J1 with " << fa[jokers[0].second] << " and J2 with "
             << fa[jokers[1].second] << ".\n";
      cout << "Put the first square to"
           << " (" << vsol[i].first.first << ", " << vsol[i].first.second
           << ").\n";
      cout << "Put the second square to"
           << " (" << vsol[j].first.first << ", " << vsol[j].first.second
           << ").";
      return 1;
    }
  return 0;
}
bool solve(int i = 0) {
  if (i == (int)jokers.size()) {
    bool ans = solve2();
    return ans;
  }
  for (int j = 0; j < (int)vd.size(); j++) {
    if (vis[j]) continue;
    vis[j] = 1;
    string str = vd[j];
    fa[jokers[i].second] = str;
    if (solve(i + 1)) return 1;
    vis[j] = 0;
  }
  return 0;
}
int main() {
  set<string> Dset;
  for (int i = 0; i < (int)Ranks.size(); i++) {
    string s1 = "C", s2 = "D", s3 = "S", s4 = "H";
    Dset.insert(Ranks[i] + s1);
    Dset.insert(Ranks[i] + s2);
    Dset.insert(Ranks[i] + s3);
    Dset.insert(Ranks[i] + s4);
  }
  string arr[50][50];
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      Dset.erase(arr[i][j]);
      fa[(i * m) + (j + 1)] = arr[i][j];
      if (arr[i][j] == "J1" || arr[i][j] == "J2")
        jokers.push_back(make_pair(arr[i][j], (i * m) + (j + 1)));
    }
  sort(jokers.begin(), jokers.end());
  for (auto it : Dset) vd.push_back(it);
  for (int i = 0; n - i >= 3; i++)
    for (int j = 0; m - j >= 3; j++) {
      vector<int> vnum;
      for (int k = i; k < i + 3; k++)
        for (int z = j; z < j + 3; z++) vnum.push_back((k * m) + (z + 1));
      vsol.push_back(make_pair(make_pair(i + 1, j + 1), vnum));
    }
  if (!solve()) cout << "No solution.";
  return 0;
}
