#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x[1010], ans = 0, u[6];
  string str[1010];
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> str[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < m; i++) {
    memset(u, 0, sizeof(u));
    for (int j = 0; j < n; j++) {
      u[str[j][i] - 'A']++;
    }
    int maxn = 0;
    for (int j = 0; j < 4; j++) {
      if (u[j] > maxn) maxn = u[j];
    }
    ans += maxn * x[i];
  }
  cout << ans << endl;
  return 0;
}
