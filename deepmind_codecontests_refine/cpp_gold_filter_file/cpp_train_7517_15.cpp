#include <bits/stdc++.h>
using namespace std;
int a[9][9];
bool mark[9][9];
bool statusgoastep() {
  bool thereany = false;
  for (int i = 7; i >= 0; --i)
    for (int j = 0; j < 8; ++j) {
      if (a[i][j] == 1) {
        a[i][j] = 0;
        if (i < 7) {
          a[i + 1][j] = 1;
          thereany = true;
        }
      }
    }
  return thereany;
}
queue<pair<int, int> > que;
int aim[2];
int start[2];
int go[9][2] = {0, 0, 1, 0, -1, 0, 0, 1, 0, -1, 1, 1, -1, 1, 1, -1, -1, -1};
int nq = 1;
bool bfs() {
  pair<int, int> tpr;
  while (nq) {
    int tnp = 0;
    for (int i = 0; i < nq; ++i) {
      tpr = que.front();
      que.pop();
      if (tpr.first == aim[0] && tpr.second == aim[1]) return true;
      for (int gsp = 0; gsp < 9; ++gsp) {
        if (tpr.first + go[gsp][0] < 0 || tpr.first + go[gsp][0] > 7) continue;
        if (tpr.second + go[gsp][1] < 0 || tpr.second + go[gsp][1] > 7)
          continue;
        if (a[tpr.first + go[gsp][0]][tpr.second + go[gsp][1]] == 1) continue;
        if (tpr.first + go[gsp][0] > 0 &&
            a[tpr.first + go[gsp][0] - 1][tpr.second + go[gsp][1]] == 1)
          continue;
        tnp++;
        que.push(make_pair(tpr.first + go[gsp][0], tpr.second + go[gsp][1]));
      }
    }
    if (tnp == 0)
      return false;
    else
      nq = tnp;
    if (!statusgoastep()) return true;
  }
}
int main() {
  char tc;
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j) {
      cin >> tc;
      if (tc == 'A') {
        aim[0] = i;
        aim[1] = j;
      } else if (tc == 'M') {
        start[0] = i;
        start[1] = j;
        nq = 1;
        que.push(make_pair(start[0], start[1]));
      } else if (tc == 'S')
        a[i][j] = 1;
    }
  if (bfs()) {
    cout << "WIN" << endl;
  } else
    cout << "LOSE" << endl;
  return 0;
}
