#include <bits/stdc++.h>
using namespace std;
const int maxs = 26 + 1, maxn = 2e3 + 1, mod = 1e9 + 7, inf = 1e9;
int n, m, a[maxn][maxn], X, Y, maxi;
pair<int, int> x[maxs], y[maxs];
vector<pair<int, int> > snake[maxs];
vector<int> ran;
bool flag;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  for (int ttt = 1; ttt <= T; ttt++) {
    cin >> n >> m;
    flag = 0;
    maxi = -1;
    for (int i = 0; i < maxs; i++) {
      x[i].first = inf;
      x[i].second = 0;
      y[i].first = inf;
      y[i].second = 0;
    }
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      for (int j = 1; j <= m; j++) {
        if (s[j - 1] == '.') {
          a[i][j] = -1;
        } else {
          int t = s[j - 1] - 'a';
          a[i][j] = t;
          x[t].first = min(x[t].first, i);
          x[t].second = max(x[t].second, i);
          y[t].first = min(y[t].first, j);
          y[t].second = max(y[t].second, j);
          if (t > maxi) {
            maxi = t;
            X = i;
            Y = i;
          }
        }
      }
    }
    for (int i = maxs - 1; i >= 0; i--) {
      if (x[i].first == inf) {
        continue;
      }
      if (x[i].second - x[i].first == 0) {
        for (int j = y[i].first; j <= y[i].second; j++) {
          if (a[x[i].first][j] < i) {
            flag = 1;
          }
        }
      } else if (y[i].second - y[i].first == 0) {
        for (int j = x[i].first; j <= x[i].second; j++) {
          if (a[j][y[i].first] < i) {
            flag = 1;
          }
        }
      } else {
        flag = 1;
      }
    }
    if (flag == 0) {
      cout << "YES" << endl;
      cout << maxi + 1 << endl;
      for (int i = 0; i <= maxi; i++) {
        if (x[i].first == inf) {
          cout << X << " " << Y << " " << X << " " << Y << endl;
        } else {
          cout << x[i].first << " " << y[i].first << " " << x[i].second << " "
               << y[i].second << endl;
        }
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
