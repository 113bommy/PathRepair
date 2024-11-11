#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> wall, game;
  int n, cnt = 0, i, j, m, x;
  cin >> n;
  cin >> m;
  for (i = 0; i < n; i++) {
    cin >> x;
    game.push_back(x);
  }
  for (i = 0; i < m; i++) {
    cin >> x;
    wall.push_back(x);
  }
  int mm = 0;
  for (i = 0; i < n; i++) {
    if (game[i] <= wall[i]) {
      cnt++;
      mm++;
    }
    if (mm >= m) break;
  }
  cout << cnt << endl;
  return 0;
}
