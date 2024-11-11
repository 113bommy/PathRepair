#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> mp;
int deg[200000];
int main() {
  int n, m, i, x, y, cn, cn2;
  srand(time(NULL));
  scanf("%d %d", &n, &m);
  vector<int> v;
  for (i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    x--;
    y--;
    mp[make_pair(x, y)] = 1;
    mp[make_pair(y, x)] = 1;
  }
  for (i = 0; i < n; i++) v.push_back(i);
  int tries = 1000;
  while (tries--) {
    random_shuffle(v.begin(), v.end());
    for (i = 0; i < m; i++) {
      if (mp.count(make_pair(v[i], v[(i + 1) % n])) != 0) {
        break;
      }
    }
    if (i + 1 == m) break;
  }
  if (tries == -1)
    cout << -1 << endl;
  else {
    for (i = 0; i < m; i++) {
      cout << v[i] + 1 << " " << v[(i + 1) % n] + 1 << endl;
    }
  }
  return 0;
}
