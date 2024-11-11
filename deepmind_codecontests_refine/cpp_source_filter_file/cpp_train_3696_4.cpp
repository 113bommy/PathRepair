#include <bits/stdc++.h>
using namespace std;
int e, cap, n, q;
vector<int> pos[3];
const int MAXN = 200005;
int suff[MAXN][3];
int get(int a, int b) {
  int x = lower_bound(pos[a].begin(), pos[a].end(), b) - pos[a].begin();
  return suff[x][a] + max(0, pos[a][x] - b - cap);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> e >> cap >> n >> q;
  for (int g = 0; g < n; g++) {
    int t, x;
    cin >> t >> x;
    if (x == e) continue;
    t--;
    for (int z = t; z >= 0; z--) {
      pos[z].push_back(x);
    }
  }
  for (int z = 0; z < 3; z++) pos[z].push_back(e);
  for (int z = 0; z < 3; z++) sort(pos[z].begin(), pos[z].end());
  for (int z = 0; z < 3; z++) {
    for (int g = pos[z].size() - 2; g >= 0; g--) {
      suff[g][z] = suff[g + 1][z] + max(0, pos[z][g + 1] - pos[z][g] - cap);
    }
  }
  for (int g = 0; g < q; g++) {
    int t;
    cin >> t;
    int f = get(0, t), s = get(1, t), z = get(2, t);
    if (f != 0)
      cout << -1 << ' ' << -1 << '\n';
    else {
      cout << s << ' ' << z - s << '\n';
    }
  }
  return 0;
}
