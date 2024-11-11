#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
const int MAXN = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int n, m;
int F[110], a[110];
pair<int, int> save[110];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> save[i].first >> save[i].second;
  for (int x = 1; x <= m; x++) {
    int sum = 0;
    for (int i = save[x].first; i <= save[x].second; i++) sum += a[i];
    for (int j = 0; j < x; j++) F[x] = max(F[x], F[j] + sum);
  }
  int res = -inf;
  for (int x = 1; x <= m; x++) res = max(res, F[x]);
  cout << res;
  return 0;
}
