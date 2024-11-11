#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<bool, int> > > v;
int check(int n) {
  int temp, minM = 10000000;
  for (int i = 0; i <= n - 3; i++)
    for (int j = 0; j <= n - 3; j++) {
      temp = 0;
      if (v[i][j].first && v[i][j + 1].first && v[i][j + 2].first &&
          v[i + 1][j].first && v[i + 1][j + 1].first && v[i + 1][j + 2].first &&
          v[i + 2][j].first && v[i + 2][j + 1].first && v[i + 2][j + 2].first) {
        for (int k = 0; k < 3; k++)
          for (int l = 0; l < 3; l++) temp = max(temp, v[i + k][j + l].second);
        minM = min(minM, temp);
      }
    }
  if (minM == 10000) minM = -1;
  return minM;
}
int main() {
  int n, m, move, x, y;
  cin >> n >> m;
  v.resize(n, vector<pair<bool, int> >(n, pair<bool, int>(false, -1)));
  for (int i = 1; i <= m; i++)
    cin >> x >> y, v[x - 1][y - 1].first = true, v[x - 1][y - 1].second = i;
  move = check(n);
  cout << move;
  return 0;
}
