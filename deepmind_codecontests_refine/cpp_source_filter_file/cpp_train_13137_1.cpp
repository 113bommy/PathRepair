#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int> > b(1e6 + 10);
void bfs(int dist) {
  queue<pair<int, int> > q;
  vector<int> d;
  int x[] = {1, 1, 1, 0, 0, -1, -1, -1};
  int y[] = {1, -1, 0, 1, -1, -1, 0, 1};
  int k = 8;
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= m + 1; j++)
      if (b[i][j] == 1) {
        q.push(make_pair(i, j));
        d.push_back(0);
      }
  int o = -1;
  while (q.size() > 0) {
    o++;
    if (d[o] == dist) break;
    for (int i = 0; i < 8; i++) {
      int i1 = q.front().first + x[i], j1 = q.front().second + y[i];
      if (!(i1 > n + 1 || i1 < 0 || j1 > m + 1 || j1 < 0))
        if (b[i1][j1] == 0) {
          q.push(make_pair(i1, j1));
          d.push_back(d[o] + 1);
          b[i1][j1] = 1;
        }
    }
    q.pop();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  vector<string> s(n);
  vector<vector<int> > a(1e6 + 10);
  int pref1[n + 2][m + 2], pref2[n + 2][m + 2], pref3[n + 2][m + 2],
      pref4[n + 2][m + 2];
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= m + 1; j++) {
      b[i].push_back(0);
      a[i].push_back(0);
      pref1[i][j] = 0;
      pref2[i][j] = 0;
      pref3[i][j] = 0;
      pref4[i][j] = 0;
    }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++)
      if (s[i][j] == '.')
        a[i + 1][j + 1] = 0;
      else
        a[i + 1][j + 1] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 0) {
        pref1[i][j] = 1;
        pref2[i][j] = 1;
      }
      pref1[i][j] += pref1[i][j - 1];
      pref2[i][j] += pref2[i - 1][j];
    }
  for (int i = n; i >= 0; i--)
    for (int j = m; j >= 0; j--) {
      if (a[i][j] == 0) {
        pref3[i][j] = 1;
        pref4[i][j] = 1;
      }
      pref3[i][j] += pref3[i][j + 1];
      pref4[i][j] += pref4[i + 1][j];
    }
  int dp1[n + 2][m + 2], dp2[n + 2][m + 2], dp3[n + 2][m + 2],
      dp4[n + 2][m + 2];
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= m + 1; j++) {
      dp1[i][j] = 0;
      dp2[i][j] = 0;
      dp3[i][j] = 0;
      dp4[i][j] = 0;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j] == 1)
        dp1[i][j] = min(min(dp1[i - 1][j] + 1, dp1[i][j - 1] + 1),
                        dp1[i - 1][j - 1] + 1);
  for (int i = n; i > 0; i--)
    for (int j = m; j > 0; j--)
      if (a[i][j] == 1)
        dp2[i][j] = min(min(dp2[i + 1][j] + 1, dp2[i][j + 1] + 1),
                        dp2[i + 1][j + 1] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = m; j > 0; j--)
      if (a[i][j] == 1)
        dp3[i][j] = min(min(dp3[i - 1][j] + 1, dp3[i][j + 1] + 1),
                        dp3[i - 1][j + 1] + 1);
  for (int i = n; i > 0; i--)
    for (int j = 1; j <= m; j++)
      if (a[i][j] == 1)
        dp4[i][j] = min(min(dp4[i + 1][j] + 1, dp4[i][j - 1] + 1),
                        dp4[i + 1][j - 1] + 1);
  int l = 0, r = min(n, m) + 2, mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (l == r - 1) mid++;
    bool o = true;
    for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= m + 1; j++)
        if (min(dp1[i][j], min(dp2[i][j], min(dp3[i][j], dp4[i][j]))) > mid)
          b[i][j] = 1;
        else
          b[i][j] = 0;
    }
    bfs(mid);
    if (b == a)
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (min(dp1[i][j], min(dp2[i][j], min(dp3[i][j], dp4[i][j]))) > l)
        cout << 'X';
      else
        cout << '.';
    cout << "/n";
  }
}
