#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m, p, qq;
  cin >> n >> m >> qq >> p;
  vector<string> ar(n);
  for (int i = 0; i < n; ++i) {
    cin >> ar[i];
  }
  vector<vector<long long int> > noise(n, vector<long long int>(m, 0));
  vector<int> q(3 * n * m);
  vector<vector<bool> > used(n, vector<bool>(m, false));
  int beg, end;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (ar[i][j] < 'A' || ar[i][j] > 'Z') continue;
      q[0] = i;
      q[1] = j;
      q[2] = (ar[i][j] - 'A' + 1) * qq;
      used.assign(n, vector<bool>(m, false));
      used[i][j] = true;
      beg = 0;
      end = 3;
      while (beg < end) {
        int x = q[beg++];
        int y = q[beg++];
        int w = q[beg++];
        noise[x][y] += w;
        w >>= 1;
        if (!w) continue;
        if (x && ar[x - 1][y] != '*' && !used[x - 1][y]) {
          used[x - 1][y] = true;
          q[end++] = x - 1;
          q[end++] = y;
          q[end++] = w;
        }
        if (x < n - 1 && ar[x + 1][y] != '*' && !used[x + 1][y]) {
          used[x + 1][y] = true;
          q[end++] = x + 1;
          q[end++] = y;
          q[end++] = w;
        }
        if (y && ar[x][y - 1] != '*' && !used[x][y - 1]) {
          used[x][y - 1] = true;
          q[end++] = x;
          q[end++] = y - 1;
          q[end++] = w;
        }
        if (y < m - 1 && ar[x][y + 1] != '*' && !used[x][y + 1]) {
          used[x][y + 1] = true;
          q[end++] = x;
          q[end++] = y + 1;
          q[end++] = w;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (noise[i][j] > p) ans++;
    }
  }
  cout << ans << endl;
}
