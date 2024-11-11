#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  bool minus = false;
  set<int> ans;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    scanf("%c", &grid[i][0]);
    for (int j = 0; j < m; j++) {
      scanf("%c", &grid[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    bool dawrf_found = false, star_found = false;
    int tout = 0;
    for (int j = 0; j < m; j++) {
      dawrf_found |= grid[i][j] == 'G';
      if (grid[i][j] == 'S') {
        star_found = dawrf_found;
        break;
      }
      if (dawrf_found) {
        tout++;
      }
    }
    ans.insert(tout);
    if (star_found == false) {
      minus = true;
    }
  }
  cout << (minus ? -1 : (int)ans.size()) << endl;
  return 0;
}
