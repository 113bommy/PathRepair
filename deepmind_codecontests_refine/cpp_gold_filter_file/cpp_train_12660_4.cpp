#include <bits/stdc++.h>
using namespace std;
char arr[251][251];
long long sums[251][251], n, m;
void bfs(int i, int j, int w) {
  vector<vector<int>> d(57, vector<int>(57, -1));
  queue<pair<int, int>> q;
  int ws[28];
  ws[0] = w;
  for (int i = 1; i < 28; ++i) {
    ws[i] = ws[i - 1] / 2;
  }
  d[28][28] = 0;
  q.push({i, j});
  sums[i][j] += ws[0];
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    if (d[28 + i - cur.first][28 + j - cur.second] < 25) {
      if (cur.first - 1 >= 0 && cur.first - 1 < n &&
          arr[cur.first - 1][cur.second] != '*' &&
          d[28 + i - cur.first + 1][28 + j - cur.second] == -1) {
        d[28 + i - cur.first + 1][28 + j - cur.second] =
            d[28 + i - cur.first][28 + j - cur.second] + 1;
        q.push({cur.first - 1, cur.second});
        sums[cur.first - 1][cur.second] +=
            ws[d[28 + i - cur.first + 1][28 + j - cur.second]];
      }
      if (cur.first + 1 >= 0 && cur.first + 1 < n &&
          arr[cur.first + 1][cur.second] != '*' &&
          d[28 + i - cur.first - 1][28 + j - cur.second] == -1) {
        d[28 + i - cur.first - 1][28 + j - cur.second] =
            d[28 + i - cur.first][28 + j - cur.second] + 1;
        q.push({cur.first + 1, cur.second});
        sums[cur.first + 1][cur.second] +=
            ws[d[28 + i - cur.first - 1][28 + j - cur.second]];
      }
      if (cur.second - 1 >= 0 && cur.second - 1 < m &&
          arr[cur.first][cur.second - 1] != '*' &&
          d[28 + i - cur.first][28 + j - cur.second + 1] == -1) {
        d[28 + i - cur.first][28 + j - cur.second + 1] =
            d[28 + i - cur.first][28 + j - cur.second] + 1;
        q.push({cur.first, cur.second - 1});
        sums[cur.first][cur.second - 1] +=
            ws[d[28 + i - cur.first][28 + j - cur.second + 1]];
      }
      if (cur.second + 1 >= 0 && cur.second + 1 < m &&
          arr[cur.first][cur.second + 1] != '*' &&
          d[28 + i - cur.first][28 + j - cur.second - 1] == -1) {
        d[28 + i - cur.first][28 + j - cur.second - 1] =
            d[28 + i - cur.first][28 + j - cur.second] + 1;
        q.push({cur.first, cur.second + 1});
        sums[cur.first][cur.second + 1] +=
            ws[d[28 + i - cur.first][28 + j - cur.second - 1]];
      }
    }
  }
}
int main() {
  int q, p;
  cin >> n >> m >> q >> p;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] >= 'A' && arr[i][j] <= 'Z')
        bfs(i, j, q * (arr[i][j] - 'A' + 1));
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (sums[i][j] > p) ans++;
    }
  }
  cout << ans;
}
