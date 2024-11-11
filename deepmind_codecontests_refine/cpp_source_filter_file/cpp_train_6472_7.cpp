#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b, g0, x, y, z;
  cin >> n >> m >> a >> b >> g0 >> x >> y >> z;
  vector<int> g(n * m);
  g[0] = g0;
  for (int i = 1; i < g.size(); ++i) g[i] = (g[i - 1] * x + y) % z;
  vector<vector<int>> h(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) h[i][j] = g[(i - 1) * m + j - 1];
  vector<vector<int>> h1(n - a + 2, vector<int>(m + 1));
  for (int j = 1; j <= m; ++j) {
    deque<int> q;
    for (int i = 1; i < a; ++i) {
      for (; !q.empty() && h[q.back()][j] > h[i][j]; q.pop_back())
        ;
      q.push_back(i);
    }
    for (int i = a; i <= n; ++i) {
      for (; !q.empty() && h[q.back()][j] > h[i][j]; q.pop_back())
        ;
      q.push_back(i);
      if (q.front() <= i - a) q.pop_front();
      h1[i - a + 1][j] = h[q.front()][j];
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n - a + 1; ++i) {
    deque<int> q;
    for (int j = 1; j < b; ++j) {
      for (; !q.empty() && h1[i][q.back()] > h1[i][j]; q.pop_back())
        ;
      q.push_back(j);
    }
    for (int j = b; j <= m; ++j) {
      for (; !q.empty() && h1[i][q.back()] > h1[i][j]; q.pop_back())
        ;
      q.push_back(j);
      if (q.front() <= j - b) q.pop_front();
      ans += h1[i][q.front()];
    }
  }
  cout << ans;
  return 0;
}
