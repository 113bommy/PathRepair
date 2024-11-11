#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool isBrainNw(vector<vector<int>> &nwIn) {
    set<int> brains;
    brains.insert(nwIn.size() - 1);
    depthFS(nwIn, nwIn.size() - 1, brains);
    if (brains.size() == nwIn.size() - 1) return (1);
    return (0);
  }

 public:
  void depthFS(vector<vector<int>> &brainsNw, int root, set<int> &brains) {
    for (auto i : brainsNw[root]) {
      if (brains.find(i) == brains.end()) {
        brains.insert(i);
        depthFS(brainsNw, i, brains);
      }
    }
  }
};
int main() {
  Solution validBrainNetwork;
  int n = 0, m = 0, x = 0, y = 0;
  cin >> n >> m;
  if (m != n - 1) {
    cout << "no";
    return (0);
  }
  vector<vector<int>> nwIn(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    nwIn[x].push_back(y);
    nwIn[y].push_back(x);
  }
  if (validBrainNetwork.isBrainNw(nwIn))
    cout << "yes";
  else
    cout << "no";
  return (0);
}
