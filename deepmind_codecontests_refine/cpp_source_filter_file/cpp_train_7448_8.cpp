#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  char pres;
  cin >> n >> m >> pres;
  char office[n][m];
  vector<pair<int, int> > p;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> office[i][j];
      if (pres == office[i][j]) p.push_back(make_pair(i, j));
    }
  }
  set<char> adjChairs;
  adjChairs.insert('.');
  adjChairs.insert(pres);
  int direc[4] = {1, -1, 0, 0};
  long long ans = 0;
  for (int i = 0; i < p.size(); i++) {
    for (int j = 0; j < 4; j++) {
      if (p[i].first + direc[j] < n && p[i].first + direc[j] >= 0 &&
          p[i].second + direc[4 - j - 1] < n &&
          p[i].second + direc[4 - j - 1] >= 0 &&
          !adjChairs.count(
              office[p[i].first + direc[j]][p[i].second + direc[4 - j - 1]])) {
        ans++;
        adjChairs.insert(
            office[p[i].first + direc[j]][p[i].second + direc[4 - j - 1]]);
      }
    }
  }
  cout << ans;
  return 0;
}
