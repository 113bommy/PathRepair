#include <bits/stdc++.h>
using namespace std;
int v[100000];
bitset<500> poss;
int nim[100000];
priority_queue<int> pos[500];
vector<pair<int, int> > events[100000];
int main() {
  int i, j;
  int n, m, x = 0;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &m);
    for (i = 0; i < m; i++) scanf("%d", &v[i]);
    poss[0] = 1, nim[m - 1] = 0, pos[0].push(m - 1);
    for (i = m - 2; i >= 0; i--) {
      for (j = 0; j < events[i].size(); j++) {
        if (events[i][j].second < nim[events[i][j].first]) {
          nim[events[i][j].first] = events[i][j].second;
          pos[nim[events[i][j].first]].push(events[i][j].first);
        }
      }
      int xx = 0;
      while (1) {
        while (!pos[xx].empty() && (nim[pos[xx].top()] != xx)) pos[xx].pop();
        if (!pos[xx].empty())
          break;
        else
          xx++;
      }
      poss[xx] = 1, nim[i] = xx, pos[xx].push(i);
      for (j = 0; j < xx; j++) {
        int k = pos[j].top();
        int p = upper_bound(v, v + i, 2 * v[i] - v[k]) - v - 1;
        if (p >= 0) events[p].push_back(make_pair(i, j));
      }
    }
    int xx = 0;
    while (poss[xx]) xx++;
    x ^= xx, poss.reset();
    for (i = 0; i < 500; i++) {
      while (!pos[i].empty()) pos[i].pop();
    }
    for (i = 0; i < m; i++) events[i].clear();
  }
  printf((x > 0) ? "YES\n" : "NO\n");
  return 0;
}
