#include <bits/stdc++.h>
using namespace std;
int inf = pow(10, 9);
long double eps = pow(10, -18);
ifstream in;
ofstream out;
int main() {
  int minx = inf, miny = inf, maxx = -inf, maxy = -inf;
  int n, m;
  cin >> n >> m;
  char arr[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 'B') {
        minx = min(minx, i);
        maxx = max(maxx, i);
        maxy = max(maxy, j);
        miny = min(miny, j);
      }
    }
  if (minx == inf)
    cout << 1;
  else {
    int ferq1 = maxx - minx;
    int ferq2 = maxy - miny;
    int ferq = ferq1 - ferq2;
    int minsay = inf;
    if (ferq1 > ferq2) {
      maxy += ferq;
      for (int i = 0; i < ferq + 1; i++) {
        if (maxy < m && miny > -1) {
          int say = 0;
          for (int i = minx; i <= maxx; i++)
            for (int j = miny; j <= maxy; j++)
              if (arr[i][j] == 'W') ++say;
          minsay = min(say, minsay);
        }
        --maxy, --miny;
      }
    } else {
      ferq = -ferq;
      maxx += ferq;
      for (int i = 0; i < ferq + 1; i++) {
        if (maxx < m && minx > -1) {
          int say = 0;
          for (int i = minx; i <= maxx; i++)
            for (int j = miny; j <= maxy; j++)
              if (arr[i][j] == 'W') ++say;
          minsay = min(say, minsay);
        }
        --maxx, --minx;
      }
    }
    if (minsay == inf)
      cout << -1;
    else
      cout << minsay;
  }
}
