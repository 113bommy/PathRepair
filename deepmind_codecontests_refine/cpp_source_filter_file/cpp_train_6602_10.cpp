#include <bits/stdc++.h>
using namespace std;
set<int> goodX;
set<pair<int, int> > can;
const int MAXN = 1000 * 1000 + 10;
int id[MAXN];
pair<int, int> pnts[MAXN];
vector<int> blocks[MAXN];
void debug() {
  cerr << "	##ST" << endl;
  for (set<pair<int, int> >::iterator it = can.begin(); it != can.end(); it++)
    cerr << "		" << it->second << " " << it->first << endl;
  cerr << "	##END" << endl;
}
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  goodX.insert(1);
  goodX.insert(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> y >> x;
    if (x > 1) goodX.insert(x - 1);
    goodX.insert(x);
    pnts[i] = pair<int, int>(x, y);
  }
  int cntx = 0;
  for (set<int>::iterator it = goodX.begin(); it != goodX.end(); it++)
    id[cntx++] = *it;
  sort(pnts, pnts + m);
  int ind = 0;
  for (int i = 0; i < cntx; i++) blocks[i].push_back(0);
  for (int i = 0; i < m; i++) {
    while (pnts[i].first > id[ind]) ind++;
    blocks[ind].push_back(pnts[i].second);
  }
  for (int i = 0; i < cntx; i++) blocks[i].push_back(n + 1);
  can.insert(pair<int, int>(blocks[0][1], 1));
  for (int i = 1; i < cntx; i++) {
    if (can.size() == 0) {
      cerr << "exit1" << endl;
      cout << -1 << endl;
      return 0;
    }
    for (int j = 0; j < blocks[i].size(); j++) {
      if (can.lower_bound(pair<int, int>(blocks[i][j], -1)) == can.end())
        continue;
      pair<int, int> match = *can.lower_bound(pair<int, int>(blocks[i][j], -1));
      if (match.second <= blocks[i][j] && blocks[i][j] < match.first) {
        can.erase(match);
        if (blocks[i][j] - match.second > 0)
          can.insert(pair<int, int>(blocks[i][j], match.second));
        if (match.first - (blocks[i][j] + 1) > 0)
          can.insert(pair<int, int>(match.first, blocks[i][j] + 1));
      }
    }
    if (can.size() == 0) {
      cerr << "exit2" << endl;
      cout << -1 << endl;
      return 0;
    }
    for (int j = 1; j < blocks[i].size(); j++) {
      set<pair<int, int> >::iterator loit =
          can.lower_bound(pair<int, int>(blocks[i][j - 1] + 1, -1));
      set<pair<int, int> >::iterator hiit =
          can.lower_bound(pair<int, int>(blocks[i][j], -1));
      if (loit == can.end()) break;
      pair<int, int> fi = *loit;
      pair<int, int> newOne = pair<int, int>(blocks[i][j], fi.second);
      can.erase(loit, hiit);
      if (newOne.first > newOne.second) can.insert(newOne);
    }
  }
  if (can.size() == 0) {
    cerr << "exit3" << endl;
    cout << -1 << endl;
    return 0;
  }
  if (can.rbegin()->first == n + 1)
    cout << (n + n - 2) << endl;
  else
    cout << -1 << endl;
  return 0;
}
