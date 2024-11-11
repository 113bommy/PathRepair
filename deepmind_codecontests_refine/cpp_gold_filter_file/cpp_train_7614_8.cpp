#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;
const int MAXM = 100 + 5;
const int INF = 2e9;
int main() {
  ios::sync_with_stdio(false);
  int n, m, h;
  cin >> n >> m >> h;
  int maxh[MAXN][MAXM];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      maxh[i][j] = INF;
    }
  }
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    for (int j = 0; j < n; j++) {
      maxh[j][i] = min(a, maxh[j][i]);
    }
  }
  for (int j = 0; j < n; j++) {
    int b;
    cin >> b;
    for (int i = 0; i < m; i++) {
      maxh[j][i] = min(b, maxh[j][i]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j != 0) cout << ' ';
      bool e;
      cin >> e;
      if (e)
        cout << maxh[i][j];
      else
        cout << 0;
    }
    cout << endl;
  }
  return 0;
}
