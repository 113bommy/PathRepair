#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
vector<pair<int, pair<int, int> > > v;
string g[307];
int n, m, K;
bool F(int i, int j, int k) {
  if (i + k >= n || i - k < 0 || j + k >= m || j - k < 0) return 0;
  if (g[i][j] == '*' && g[i][j + k] == '*' && g[i][j - k] == '*' &&
      g[i + k][j] == '*' && g[i - k][j] == '*')
    return 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> K;
  for (int i = 0; i < n; i++) cin >> g[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int k = 1; k <= max(n, m); k++)
        if (F(i, j, k)) v.push_back({k, {i, j}});
  sort(v.begin(), v.end());
  if (K > v.size()) {
    cout << "-1\n";
    return 0;
  }
  K--;
  int x = v[K].second.first;
  int y = v[K].second.second;
  int d = v[K].first;
  x++, y++;
  cout << x << " " << y << endl;
  cout << x - d << " " << y << endl;
  cout << x + d << " " << y << endl;
  cout << x << " " << y - d << endl;
  cout << x << " " << y + d << endl;
  return 0;
}
