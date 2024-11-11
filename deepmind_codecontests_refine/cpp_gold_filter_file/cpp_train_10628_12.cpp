#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > roads;
set<int> myMapping;
map<int, int> Reverse;
int MOD = 1e9 + 7;
vector<int> startPoint[300005];
int Tree[800005];
int modifyTree(int pos, int l, int r, int UL, int UR, int val) {
  if (l > UR || r < UL) return 0;
  if (l >= UL && r <= UR) return Tree[pos] += val, Tree[pos] %= MOD;
  int mid = (l + r) >> 1;
  modifyTree(pos * 2, l, mid, UL, UR, val);
  modifyTree(pos * 2 + 1, mid + 1, r, UL, UR, val);
  Tree[pos] = (Tree[pos * 2] % MOD + Tree[pos * 2 + 1] % MOD) % MOD;
  Tree[pos] %= MOD;
  return 0;
}
int getTree(int pos, int l, int r, int UL, int UR) {
  if (l > UR || r < UL) return 0;
  if (l >= UL && r <= UR) return Tree[pos];
  int mid = (l + r) >> 1;
  return (getTree(pos * 2, l, mid, UL, UR) % MOD +
          getTree(pos * 2 + 1, mid + 1, r, UL, UR) % MOD) %
         MOD;
}
int main() {
  cin >> n >> m;
  myMapping.insert(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    roads.push_back({u, v});
    myMapping.insert(u);
    myMapping.insert(v);
  }
  myMapping.insert(0);
  int cur = 0;
  for (set<int>::iterator it = myMapping.begin(); it != myMapping.end(); it++)
    Reverse[*it] = cur, cur++;
  n = Reverse[n];
  for (int i = 0; i < roads.size(); i++)
    roads[i].first = Reverse[roads[i].first],
    roads[i].second = Reverse[roads[i].second],
    startPoint[roads[i].second].push_back(roads[i].first);
  modifyTree(1, 0, n, 0, 0, 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < startPoint[i].size(); j++) {
      int ans = getTree(1, 0, n, startPoint[i][j], i - 1) % MOD;
      modifyTree(1, 0, n, i, i, ans);
    }
  }
  cout << getTree(1, 0, n, n, n);
  return 0;
}
