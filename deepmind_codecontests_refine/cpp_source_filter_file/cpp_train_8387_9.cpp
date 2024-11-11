#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
vector<pair<pair<long long int, long long int>, vector<long long int> > > G;
vector<long long int> nodeIndex;
long long int value = 0;
long long int travel(int nodeId) {
  long long int childSum = 0;
  for (int i = 0; i < G[nodeId].second.size(); i++) {
    childSum += travel(G[nodeId].second[i]);
  }
  if (G[nodeId].first.second + childSum != value / 3)
    return G[nodeId].first.second + childSum;
  nodeIndex.push_back(nodeId + 1);
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  G.resize(n);
  for (int i = 0; i < n; i++) {
    long long int parent, val;
    cin >> parent >> val;
    G[i].first.first = parent - 1;
    G[i].first.second = val;
    if (parent != 0) G[parent - 1].second.push_back(i);
    value += val;
  }
  for (int i = 0; i < n; i++)
    if (G[i].first.first == -1) travel(i);
  if (value % 3 != 0 || nodeIndex.size() < 2)
    cout << "-1\n";
  else
    cout << nodeIndex[0] << " " << nodeIndex[1] << '\n';
  return 0;
}
