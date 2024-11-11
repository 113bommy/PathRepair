#include <bits/stdc++.h>
using namespace std;
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, t, p, q, a, b, c;
  while (cin >> n >> m >> q) {
    int R[109][109];
    memset(R, 0, sizeof(R));
    stack<pair<int, int> > record;
    for (int i = 0; i < q; i++) {
      cin >> t;
      if (t == 1) {
        cin >> a;
        record.push({1, a});
        int tmp = R[a][1];
        for (int j = 1; j + 1 < m; j++) R[a][j] = R[a][j + 1];
        R[a][m] = tmp;
      } else if (t == 2) {
        cin >> a;
        record.push({2, a});
        int tmp = R[1][a];
        for (int j = 1; j + 1 < n; j++) R[j][a] = R[j + 1][a];
        R[n][a] = tmp;
      } else {
        cin >> a >> b >> c;
        R[a][b] = c;
      }
    }
    while (!record.empty()) {
      t = record.top().first, a = record.top().second;
      record.pop();
      if (t == 1) {
        int tmp = R[a][m];
        for (int i = m; i > 1; i--) {
          R[a][i] = R[a][i - 1];
        }
        R[a][1] = tmp;
      } else {
        int tmp = R[n][a];
        for (int i = n; i > 1; i--) {
          R[i][a] = R[i - 1][a];
        }
        R[1][a] = tmp;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << R[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
