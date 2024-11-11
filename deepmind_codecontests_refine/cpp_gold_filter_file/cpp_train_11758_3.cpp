#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> scjl[33];
vector<int> now[55];

int solve();

int main() {
  int i, j, f, x;
  while(1) {
    cin >> n;
    if(n == 0) break;
    for(i = 0; i < n; ++i) {
      cin >> f;
      for(j = 0; j < f; ++j) {
        cin >> x;
        scjl[x].push_back(i);
      }
    }
    for(i = 0; i < n; ++i) now[i].push_back(i);
    cout << solve() << endl;
    for(i = 0; i <= 30; ++i)
      scjl[i].erase(scjl[i].begin(), scjl[i].end());
    for(i = 0; i < n; ++i)
      now[i].erase(now[i].begin(), now[i].end());
  }
  return 0;
}

int solve() {
  int i, j;
  for(i = 1; i <= 30; ++i) {
    vector<int> nextv;
    for(j = 0; j < scjl[i].size(); ++j)
      nextv.insert(nextv.begin(), now[scjl[i][j]].begin(),
                   now[scjl[i][j]].end());
    sort(nextv.begin(), nextv.end());
    nextv.erase(unique(nextv.begin(), nextv.end()),
                nextv.end());
    if(nextv.size() == n) return i;
    for(j = 0; j < scjl[i].size(); ++j)
      now[scjl[i][j]] = nextv;
  }
  return -1;
}
