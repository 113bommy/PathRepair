#include <bits/stdc++.h>
using namespace std;
int n;
int aim[105], like[105];
int g[105][105];
map<int, int> id;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(g, -1, sizeof(g));
  for (int i = 1; i <= 100; i++) g[i][i] = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> aim[i];
    id[aim[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> like[i];
    if (i - like[i] >= 1) g[i][i - like[i]] = g[i - like[i]][i] = 1;
    if (i + like[i] <= n) g[i][i + like[i]] = g[i + like[i]][i] = 1;
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if (g[i][k] != -1 && g[k][j] != -1) g[i][j] = 1;
      }
  for (int i = 1; i <= n; i++)
    if (g[i][id[i]] == -1) {
      cout << "NO" << endl;
      return 0;
    }
  cout << "YES" << endl;
  return 0;
}
