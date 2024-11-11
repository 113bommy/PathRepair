#include <bits/stdc++.h>
using namespace std;
struct prod {
  int b, s, c;
};
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<prod> > planets(n, *new vector<prod>(m));
  string w;
  for (int i = 0; i < n; i++) {
    cin >> w;
    for (int j = 0; j < m; j++)
      cin >> planets[i][j].b >> planets[i][j].s >> planets[i][j].c;
  }
  int p = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i != j) {
        vector<pair<int, int> > lucro(m);
        for (int z = 0; z < m; z++) {
          lucro[z] = make_pair(planets[j][z].s - planets[i][z].b, z);
        }
        sort(lucro.begin(), lucro.end());
        reverse(lucro.begin(), lucro.end());
        int remain = k, L = 0;
        for (int z = 0; z < lucro.size() && lucro[z].first > 0 && remain > 0;
             z++) {
          if (remain >= planets[i][lucro[z].second].c) {
            remain -= planets[i][lucro[z].second].c;
            L += planets[i][lucro[z].second].c * lucro[z].first;
          } else {
            L += remain * lucro[z].first;
            remain = 0;
          }
        }
        p = max(p, L);
      }
    }
  }
  cout << p << endl;
  return 0;
}
