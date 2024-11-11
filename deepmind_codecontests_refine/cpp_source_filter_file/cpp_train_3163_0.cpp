#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > aEdges;
vector<int> aVal;
vector<int> aUsed;
struct Op {
  int dec, inc;
};
Op dfs(int i) {
  Op o, next;
  o.dec = 0;
  o.inc = 0;
  aUsed[i] = 1;
  for (int j = 0; j < aEdges[i].size(); j++) {
    if (aUsed[aEdges[i][j]]) continue;
    next = dfs(aEdges[i][j]);
    o.dec = max(o.dec, next.dec);
    o.inc = max(o.inc, next.inc);
  }
  aVal[i] += o.inc - o.dec;
  if (aVal[i] >= 0)
    o.dec += aVal[i];
  else
    o.inc += -aVal[i];
  return o;
}
int main() {
  int N;
  int i, j;
  int a, b;
  vector<int> v;
  cin >> N;
  for (i = 0; i < N; i++) {
    aEdges.push_back(v);
    aUsed.push_back(0);
  }
  for (i = 0; i < (N - 1); i++) {
    cin >> a >> b;
    a--, b--;
    aEdges[a].push_back(b);
    aEdges[b].push_back(a);
  }
  for (i = 0; i < N; i++) {
    cin >> j;
    aVal.push_back(j);
  }
  Op ans = dfs(0);
  cout << ans.inc + ans.dec << endl;
}
