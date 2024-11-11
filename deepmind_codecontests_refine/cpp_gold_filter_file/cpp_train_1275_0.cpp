#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void solve() {
  int n, m;
  cin >> n >> m;
  char a[n + 1][m + 1];
  int no = 0;
  for (long long i = 1; i < 1 + n; i++) {
    for (long long j = 1; j < m + 1; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'G') no++;
    }
  }
  bool ans = true;
  if (a[n][m] == 'B') {
    cout << "NO" << endl;
    return;
  }
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < m + 1; j++) {
      if (a[i][j] == 'B') {
        if (i + 1 <= n && a[i + 1][j] == 'G') {
          cout << "NO" << endl;
          return;
        }
        if (i - 1 >= 1 && a[i - 1][j] == 'G') {
          cout << "NO" << endl;
          return;
        }
        if (j + 1 <= m && a[i][j + 1] == 'G') {
          cout << "NO" << endl;
          return;
        }
        if (j - 1 >= 1 && a[i][j - 1] == 'G') {
          cout << "NO" << endl;
          return;
        }
        if (i + 1 <= n && a[i + 1][j] == '.') {
          a[i + 1][j] = '#';
        }
        if (i - 1 >= 0 && a[i - 1][j] == '.') {
          a[i - 1][j] = '#';
        }
        if (j + 1 <= m && a[i][j + 1] == '.') {
          a[i][j + 1] = '#';
        }
        if (j - 1 >= 0 && a[i][j - 1] == '.') {
          a[i][j - 1] = '#';
        }
      }
    }
  }
  bool dp[n + 1][m + 1];
  for (long long i = 0; i < n + 1; i++) {
    for (long long j = 0; j < m + 1; j++) dp[i][j] = 0;
  }
  queue<pair<int, int> > q;
  q.push({n, m});
  int tmp = 0;
  while (!q.empty()) {
    pair<int, int> first = q.front();
    q.pop();
    int i = first.first, j = first.second;
    dp[i][j] = true;
    if (a[i][j] == '#') continue;
    if (a[i][j] == 'G') {
      tmp++;
    }
    if (i + 1 <= n && !dp[i + 1][j] && a[i + 1][j] != '#') {
      q.push({i + 1, j});
      dp[i + 1][j] = true;
    }
    if (i - 1 >= 1 && !dp[i - 1][j] && a[i - 1][j] != '#') {
      q.push({i - 1, j});
      dp[i - 1][j] = true;
    }
    if (j + 1 <= m && !dp[i][j + 1] && a[i][j + 1] != '#') {
      q.push({i, j + 1});
      dp[i][j + 1] = true;
    }
    if (j - 1 >= 1 && !dp[i][j - 1] && a[i][j - 1] != '#') {
      q.push({i, j - 1});
      dp[i][j - 1] = true;
    }
  }
  if (a[n][m] == '#') {
    if (no != 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
    return;
  }
  if (tmp == no)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "Time elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
