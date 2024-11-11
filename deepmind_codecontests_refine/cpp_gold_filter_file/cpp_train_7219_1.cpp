#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > cpu(3);
vector<vector<int> > g(201);
int vs[201];
bool mission[201];
int start[3];
int ans = 1000000000;
int main() {
  int n, startms;
  cin >> n;
  start[0] = -1;
  start[1] = -1;
  start[2] = -1;
  for (int i = 0; i < n; ++i) {
    int comp;
    cin >> comp;
    cpu[comp - 1].push_back(i);
    vs[i] = comp - 1;
  }
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    if (tmp == 0) {
      start[vs[i]] = i;
    }
    for (int j = 0; j < tmp; ++j) {
      int v;
      cin >> v;
      g[i].push_back(v - 1);
    }
  }
  for (int u = 0; u < 3; ++u) {
    if (start[u] == -1) continue;
    for (int j = 0; j < n; ++j) mission[j] = false;
    int pc = u;
    mission[start[u]] = true;
    int ost = n - 1;
    int hour = 1;
    while (ost != 0) {
      for (int i = 0; i < cpu[pc].size(); ++i) {
        int ms = cpu[pc][i];
        if (mission[ms] == true) {
          continue;
        }
        bool fl = true;
        for (int j = 0; j < g[ms].size(); ++j) {
          if (mission[g[ms][j]] == false) {
            fl = false;
            break;
          }
        }
        if (fl == true) {
          mission[ms] = true;
          ost--;
          hour++;
          i = -1;
        }
      }
      if (ost != 0) {
        hour++;
        if (pc == 0) {
          pc = 1;
          continue;
        }
        if (pc == 1) {
          pc = 2;
          continue;
        }
        if (pc == 2) {
          pc = 0;
          continue;
        }
      }
    }
    ans = min(hour, ans);
  }
  cout << ans;
  return 0;
}
