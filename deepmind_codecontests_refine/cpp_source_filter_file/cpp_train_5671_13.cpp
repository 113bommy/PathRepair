#include <bits/stdc++.h>
using namespace std;
vector<int> v[2000100];
int xu[2000100], yu[2000100], n, m, t, dist, sol, muie, pozy[2000100], x, y, dx,
    dy, kkt[2000100];
int main() {
  cin >> n >> m >> dx >> dy;
  xu[++t] = dx;
  yu[t] = dy;
  while (xu[t] && yu[t]) {
    ++t;
    xu[t] = (xu[t - 1] + dx) % n;
    yu[t] = (yu[t - 1] + dy) % n;
  }
  for (int i = 1; i <= t; ++i) {
    pozy[yu[i]] = i;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> x >> y;
    v[x].push_back(y);
  }
  for (int i = 1; i <= t; ++i) {
    for (vector<int>::iterator it = v[xu[i]].begin(); it != v[xu[i]].end();
         it++) {
      int np = pozy[*it];
      if (np >= i)
        dist = np - i;
      else
        dist = n - i + np;
      kkt[dist]++;
      if (kkt[dist] > sol) {
        sol = kkt[dist];
        muie = dist;
      }
    }
  }
  cout << xu[1] << " " << yu[1 + muie];
  return 0;
}
