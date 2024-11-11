#include <bits/stdc++.h>
using namespace std;
long long memo[505][505][2], b[505];
long long DP(int ini, int fin, int tipe) {
  if (ini >= fin) return 1;
  long long &ret = memo[ini][fin][tipe];
  if (ret != -1) return ret;
  long long ans = DP(ini + 1, fin, 0), aux;
  if (tipe == 0) {
    for (int i = ini; i < fin; i++) {
      if (b[ini] > b[i + 1]) continue;
      aux = DP(ini, i, 1);
      aux = (aux * DP(i + 1, fin, 0)) % 1000000007;
      ans += aux;
      if (ans >= 1000000007) ans -= 1000000007;
    }
  }
  return ret = ans;
}
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> b[i];
    memset(memo, -1, sizeof memo);
    long long ans = DP(1, n - 1, 0);
    cout << ans << endl;
  }
}
