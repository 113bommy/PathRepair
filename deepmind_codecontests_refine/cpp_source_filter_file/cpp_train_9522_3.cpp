#include <bits/stdc++.h>
using namespace std;
vector<int> a[3001];
bool b[3001][3001];
int main() {
  std ::ios ::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  memset(b, 0, sizeof(b));
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    b[x][y] = true;
  }
  long long ans = 0;
  for (int d1 = 1; d1 <= n; d1++)
    for (int d3 = 1; d3 <= n; d3++) {
      if (d1 == d3) continue;
      int d = 0;
      for (int k = 0; k < a[d1].size(); k++) {
        int d2 = a[d1][k];
        if (d2 == d1 || d2 == d3) continue;
        if (b[d1][d2]) d++;
      }
      ans += d * (d - 1) / 2;
    }
  cout << ans;
  return 0;
}
