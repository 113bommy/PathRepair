#include <bits/stdc++.h>
const long long big = 998244353;
using namespace std;
long long power(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 1)
    return (power(a, n - 1) * a) % big;
  else {
    long long b = power(a, n / 2);
    return (b * b) % big;
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> table(n, vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> table[i][j];
    }
  }
  int countx = 0, county = 0;
  for (int i = 0; i < n; ++i) {
    bool mark = false;
    for (int j = 0; j < m; ++j) {
      if (table[i][j] == '#') mark = true;
    }
    if (!mark) ++countx;
  }
  for (int j = 0; j < m; ++j) {
    bool mark = false;
    for (int i = 0; i < n; ++i) {
      if (table[i][j] == '#') mark = true;
    }
    if (!mark) ++county;
  }
  if ((countx == 0 && county > 0) || (countx > 0 && county == 0)) {
    cout << -1;
    return;
  }
  for (int i = 0; i < n; ++i) {
    bool flag = false;
    for (int j = 0; j < m; ++j) {
      if (flag && table[i][j] == '#') {
        cout << -1;
        return;
      }
      if (j < m - 1 && table[i][j] == '#' && table[i][j + 1] == '.')
        flag = true;
    }
  }
  for (int j = 0; j < m; ++j) {
    bool flag = false;
    for (int i = 0; i < n; ++i) {
      if (flag && table[i][j] == '#') {
        cout << -1;
        return;
      }
      if (i < n - 1 && table[i][j] == '#' && table[i + 1][j] == '.')
        flag = true;
    }
  }
  vector<vector<int>> g(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (table[i][j] == '#') {
        int num = i * m + j;
        if (i > 0 && table[i - 1][j] == '#') g[num].push_back(num - m);
        if (i < n - 1 && table[i + 1][j] == '#') g[num].push_back(num + m);
        if (j > 0 && table[i][j - 1] == '#') g[num].push_back(num - 1);
        if (j < n - 1 && table[i][j + 1] == '#') g[num].push_back(num + 1);
      }
    }
  }
  int ans = 0;
  vector<bool> used(n * m, false);
  queue<int> q;
  for (int i = 0; i < n * m; ++i) {
    if (table[i / m][i % m] == '#' && !used[i]) {
      ++ans;
      q.push(i);
      used[i] = true;
      while (!q.empty()) {
        int cur = q.front();
        for (int v : g[cur]) {
          if (!used[v]) {
            used[v] = true;
            q.push(v);
          }
        }
        q.pop();
      }
    }
  }
  cout << ans;
}
int main() {
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
}
