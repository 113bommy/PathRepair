#include <bits/stdc++.h>
using namespace std;
int n, k;
int datos[5005];
int joy[15];
int dp[505][5005] = {0};
map<int, int> cant;
map<int, int> fav;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n * k; i++) {
    cin >> datos[i];
    cant[datos[i]]++;
  }
  for (int i = 0; i < n; i++) {
    int aux;
    cin >> aux;
    fav[aux]++;
  }
  joy[0] = 0;
  for (int i = 1; i <= k; i++) {
    cin >> joy[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n * k; j++) {
      for (int x = 0; x <= k; x++) {
        dp[i + 1][j + x] = max(dp[i + 1][j + x], dp[i][j] + joy[x]);
      }
    }
  }
  int ans = 0;
  for (auto it = cant.begin(); it != cant.end(); it++) {
    if (fav.count(it->first)) ans += dp[fav[it->first]][it->second];
  }
  cout << ans << "\n";
  return 0;
}
