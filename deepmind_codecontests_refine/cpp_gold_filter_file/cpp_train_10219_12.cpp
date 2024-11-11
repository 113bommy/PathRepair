#include <bits/stdc++.h>
using namespace std;
const int ACT = 1;
bool resmat[100001][3];
int main() {
  int n, m, res = 0;
  set<int> poss;
  vector<pair<int, int> > allyrep;
  cin >> n >> m;
  allyrep.resize(n + 1, make_pair(0, 0));
  for (int x = 0; x < m; x++) {
    int acc;
    cin >> acc;
    poss.insert(acc);
    if (acc - 1 > 0 && poss.count(acc - 1)) {
      allyrep[acc - 1].second++;
    }
    if (acc + 1 <= n && poss.count(acc + 1)) {
      allyrep[acc + 1].first++;
    }
  }
  for (int x = 1; x <= n; x++) {
    if (!poss.count(x)) {
      resmat[x][ACT] = true;
      if (x - 1 > 0) {
        resmat[x][ACT - 1] = 1;
        resmat[x - 1][ACT + 1] = 1;
      }
      if (x + 1 <= n) {
        resmat[x][ACT + 1] = 1;
        resmat[x + 1][ACT - 1] = 1;
      }
    } else {
      if (!allyrep[x].first && x - 1 > 0) {
        resmat[x][ACT - 1] = 1;
      }
      if (!allyrep[x].second && x + 1 <= n) {
        resmat[x][ACT + 1] = 1;
      }
    }
  }
  for (int x = 1; x <= n; x++) {
    if (resmat[x][0] && x - 1 > 0) {
      res++;
    }
    if (resmat[x][1]) {
      res++;
    }
    if (resmat[x][2] && x + 1 <= n) {
      res++;
    }
  }
  cout << res;
}
