#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int x[n][3];
  int y[m][3];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> x[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> y[i][j];
    }
  }
  int maior = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((y[j][0] < x[i][0] && y[j][0] + y[j][2] > x[i][0]) &&
          (x[i][1] < y[j][1] && x[i][1] + x[i][2] > y[j][1])) {
        int dist = INT_MAX;
        int x1 = x[i][0];
        int y1 = y[j][1];
        dist = min(dist, abs(x1 - y[j][0]));
        dist = min(dist, abs(x1 - (y[j][0] + y[j][2])));
        dist = min(dist, abs(y1 - x[i][1]));
        dist = min(dist, abs(y1 - (x[i][1] + x[i][2])));
        maior = max(maior, dist);
      }
    }
  }
  cout << maior << endl;
  return 0;
}
