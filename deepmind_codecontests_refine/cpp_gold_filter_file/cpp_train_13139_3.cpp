#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
}
const int N = 2e5 + 2;
int n, q;
int x, y, flag;
void solve() {
  cin >> n >> q;
  vector<vector<bool>> matrix(2, vector<bool>(n + 2, 0));
  while (q--) {
    cin >> x >> y;
    int X = x - 1;
    if (x == 2) x = 0;
    if (!matrix[X][y]) {
      flag += (matrix[x][y - 1] + matrix[x][y] + matrix[x][y + 1]);
      matrix[X][y] = 1;
    } else {
      flag -= (matrix[x][y - 1] + matrix[x][y] + matrix[x][y + 1]);
      matrix[X][y] = 0;
    }
    if (flag)
      cout << "no" << endl;
    else
      cout << "yes" << endl;
  }
}
int main() {
  fast();
  solve();
}
