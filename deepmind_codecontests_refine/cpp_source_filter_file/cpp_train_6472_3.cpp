#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
int n, m, a, b;
long long ans, g, x, y, z, h[N][N], h1[N][N];
deque<long long> q;
void pre() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) h[i][j] = g, g = (g * x % z + y) % z;
}
int main() {
  cin >> n >> m >> a >> b >> g >> x >> y >> z;
  pre();
  for (int i = 1; i <= n; i++) {
    q.clear();
    for (int j = 1; j <= m; j++) {
      while (!q.empty() && q.front() <= j - b) q.pop_front();
      while (!q.empty() && h[i][j] <= h[i][q.back()]) q.pop_back();
      q.push_back(j);
      h1[i][j] = h[i][q.front()];
    }
  }
  for (int j = b; j <= m; j++) {
    q.clear();
    for (int i = 1; i <= n; i++) {
      while (!q.empty() && q.front() <= i - a) q.pop_front();
      while (!q.empty() && h1[i][j] <= h[q.back()][j]) q.pop_back();
      q.push_back(i);
      if (i >= a) ans += h1[q.front()][j];
    }
  }
  cout << ans << endl;
  return 0;
}
