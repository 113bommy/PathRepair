#include <bits/stdc++.h>
using namespace std;
bool en[100001];
vector<int> path[100001];
map<int, int> ans;
int farNodes[2], maxDist[2];
int finalAns = 0;
void findFarthestNode(int par, int curr, int index, int depth) {
  if (en[curr] && depth > maxDist[index])
    maxDist[index] = depth, farNodes[index] = curr;
  auto itr = path[curr].begin();
  while (itr != path[curr].end()) {
    if (*itr != par) {
      findFarthestNode(curr, *itr, index, depth + 1);
    }
    itr++;
  }
  return;
}
void doDFSTillDepth(int par, int curr, int depth, int maxDepth) {
  if (depth > maxDepth) return;
  if (ans.count(curr) > 0)
    finalAns += 1;
  else
    ans[curr] = 1;
  auto itr = path[curr].begin();
  while (itr != path[curr].end()) {
    if (*itr != par) {
      doDFSTillDepth(curr, *itr, depth + 1, maxDepth);
    }
    itr++;
  }
}
int main() {
  int n, m, d;
  cin >> n >> m >> d;
  int x, y;
  for (int i = 0; i < m; i++) cin >> x, en[x] = true;
  for (int i = 0; i < n - 1; i++)
    cin >> x >> y, path[x].push_back(y), path[y].push_back(x);
  findFarthestNode(1, 1, 0, 0);
  findFarthestNode(farNodes[0], farNodes[0], 1, 0);
  doDFSTillDepth(farNodes[0], farNodes[0], 0, d);
  doDFSTillDepth(farNodes[1], farNodes[1], 0, d);
  cout << finalAns;
  return 0;
}
