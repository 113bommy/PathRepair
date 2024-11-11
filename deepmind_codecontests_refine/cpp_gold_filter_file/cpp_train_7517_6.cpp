#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
const int mxn = 8;
int dx[9] = {-1, -1, -1, 0, 1, 1, 1, 0, 0},
    dy[9] = {-1, 0, 1, 1, 1, 0, -1, -1, 0};
char g[mxn + 5][mxn + 5];
void solve() {
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) {
      cin >> g[i][j];
    }
  }
  pi p = {8, 1};
  queue<pi> q;
  q.push(p);
  int turn = 1;
  while (!q.empty()) {
    int sze = (int)(q).size();
    while (sze--) {
      p = q.front();
      q.pop();
      if (turn == 8 || (p.first == 1 && p.second == 8)) {
        cout << "WIN\n";
        return;
      }
      for (int i = 0; i < 9; ++i) {
        int in = p.first + dx[i], jn = p.second + dy[i];
        if (in >= 1 && jn >= 1 && in <= 8 && jn <= 8 &&
            g[max(0, in - turn)][jn] != 'S' &&
            g[max(0, in - turn + 1)][jn] != 'S') {
          q.push({in, jn});
        }
      }
    }
    ++turn;
  }
  cout << "LOSE\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) solve();
}
