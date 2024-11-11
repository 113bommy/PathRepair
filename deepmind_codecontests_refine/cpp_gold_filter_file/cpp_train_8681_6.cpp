#include <bits/stdc++.h>
using namespace std;
bool rows[100050];
bool cols[100050];
string grid[100050];
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > sol;
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == '.' && !cols[j]) {
        sol.push_back({i, j});
        cols[j] = 1;
      }
    }
  }
  if (sol.size() < n) {
    sol.clear();
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n; i++) {
        if (grid[i][j] == '.' && !rows[i]) {
          sol.push_back({i, j});
          rows[i] = 1;
        }
      }
    }
    if (sol.size() < n) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++)
    cout << sol[i].first + 1 << " " << sol[i].second + 1 << endl;
  return 0;
}
