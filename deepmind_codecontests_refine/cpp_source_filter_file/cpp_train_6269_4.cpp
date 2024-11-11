#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> degree(n + 1, 0);
  set<pair<int, int> > edges;
  for (int k = 0; k < m; ++k) {
    int left = 0, right = 0;
    cin >> left >> right;
    edges.insert(pair<int, int>(left, right));
    ++degree[left];
    ++degree[right];
  }
  int ans(0);
  while (edges.size() > 0) {
    std::vector<int> todecrease;
    for (int k = 0; k < m; ++k) {
      if (degree[k] == 1) {
        todecrease.push_back(k);
        set<pair<int, int> >::iterator setIter;
        for (setIter = edges.begin(); setIter != edges.end(); setIter++) {
          if (setIter->first == k) {
            todecrease.push_back(setIter->second);
            edges.erase(setIter);
            break;
          } else if (setIter->second == k) {
            todecrease.push_back(setIter->first);
            edges.erase(setIter);
            break;
          }
        }
      }
    }
    if (todecrease.size() == 0) {
      break;
    } else {
      for (int k = 0; k < todecrease.size(); k++) {
        --degree[todecrease[k]];
      }
      ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
