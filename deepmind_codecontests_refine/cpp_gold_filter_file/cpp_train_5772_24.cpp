#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const long double EPS = 1e-9;
const int N = 20005;
const int M = 15;
int n, m, k;
int a[M][N], b[M];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  memset(a, 255, sizeof a);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      if (x == 1) a[j][i] = 0;
    }
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y, --x, --y;
    ++a[y][x], ++b[y];
  }
  for (int i = 0; i < n; ++i) {
    int x = 0;
    for (int j = 0; j < m; ++j)
      if (a[j][i] != -1) x += b[j] - a[j][i];
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
