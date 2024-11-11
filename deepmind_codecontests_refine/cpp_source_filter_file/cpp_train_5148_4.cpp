#include <bits/stdc++.h>
const double pi = acos(-1.0);
const double eps = 1e-9;
using namespace std;
const int N = 2e5 + 10;
const int sq = 400;
string s;
int q, cntBlocks;
vector<pair<int, int>> blocks[N];
vector<pair<int, int>> where[N];
unordered_map<string, int> Id;
map<pair<int, int>, int> mp;
int getId(string s) {
  if (Id.count(s) == 0) {
    Id[s] = ++cntBlocks;
  }
  return Id[s];
}
void update(int i, int j, int res) {
  if (mp.count({i, j}) == 0) {
    mp[{i, j}] = res;
  }
  mp[{i, j}] = min(mp[{i, j}], res);
  swap(i, j);
  if (mp.count({i, j}) == 0) {
    mp[{i, j}] = res;
  }
  mp[{i, j}] = min(mp[{i, j}], res);
}
void solve() {
  cin >> s >> q;
  set<int> moreSq;
  vector<int> idsMoreSq;
  for (int i = 0; i < s.size(); i++) {
    string otr;
    for (int r = i; r < min(i + 4, (int)s.size()); r++) {
      otr.push_back(s[r]);
      int idBlock = getId(otr);
      blocks[idBlock].push_back({i, otr.size()});
      where[i].push_back({idBlock, otr.size()});
    }
    for (auto idBlocks : where[i]) {
      if (blocks[idBlocks.first].size() >= sq) {
        if (moreSq.find(idBlocks.first) == moreSq.end()) {
          moreSq.insert(idBlocks.first);
          idsMoreSq.push_back(idBlocks.first);
        }
        for (int id1 : idsMoreSq) {
          int res = i - blocks[id1].back().first + idBlocks.second;
          res = max(res, blocks[id1].back().second);
          update(idBlocks.first, id1, res);
        }
      }
    }
  }
  while (q--) {
    string a, b;
    cin >> a >> b;
    if (Id.count(a) == 0 || Id.count(b) == 0) {
      cout << -1 << "\n";
      continue;
    }
    int na = getId(a);
    int nb = getId(b);
    if (mp.count({na, nb})) {
      cout << mp[{na, nb}] << "\n";
      continue;
    }
    if (blocks[na].size() > blocks[nb].size()) {
      swap(na, nb);
    }
    int res = 1e9;
    for (auto id : blocks[na]) {
      int pos = lower_bound((blocks[nb]).begin(), (blocks[nb]).end(),
                            make_pair(id.first, -1)) -
                blocks[nb].begin();
      for (int del = -1; del <= 1; del++) {
        if (pos + del >= 0 && pos + del < blocks[nb].size()) {
          if (id.first >= blocks[nb][pos + del].first) {
            res =
                min(res, max(id.first - blocks[nb][pos + del].first + id.second,
                             blocks[nb][pos + del].second));
          } else {
            res = min(res, max(blocks[nb][pos + del].first +
                                   blocks[nb][pos + del].second - id.first,
                               id.second));
          }
        }
      }
    }
    cout << res << "\n";
  }
}
int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(3);
  int step = 1;
  for (int i = 0; i < step; i++) {
    solve();
  }
}
