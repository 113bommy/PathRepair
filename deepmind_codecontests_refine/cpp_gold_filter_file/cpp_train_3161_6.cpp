#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
const int INF = (int)1e9 + 7;
int main() {
  int n, m, x, y;
  string s[MAXN];
  cin >> n >> m >> x >> y;
  for (int i = 0; i < n; i++) cin >> s[i];
  int T[MAXN][2], D[MAXN + 1][2];
  memset(T, 0, sizeof T);
  for (int i = 0; i < m; i++) (s[0][i] == '#') ? T[i][0]++ : T[i][1]++;
  for (int i = 1; i < n; i++)
    for (int j = 0; j < m; j++) (s[i][j] == '#') ? T[j][0]++ : T[j][1]++;
  for (int i = 1; i < m; i++) {
    T[i][0] += T[i - 1][0];
    T[i][1] += T[i - 1][1];
  }
  memset(D, INF, sizeof D);
  D[0][0] = D[0][1] = 0;
  for (int i = 1; i <= m; i++) {
    for (int l = x; l <= y; l++) {
      if (i - l < 0) continue;
      D[i][0] = min(
          D[i - l][1] + T[i - 1][0] - (i - l - 1 >= 0 ? T[i - l - 1][0] : 0),
          D[i][0]);
      D[i][1] = min(
          D[i - l][0] + T[i - 1][1] - (i - l - 1 >= 0 ? T[i - l - 1][1] : 0),
          D[i][1]);
    }
  }
  cout << min(D[m][0], D[m][1]) << endl;
}
