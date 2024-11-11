#include <bits/stdc++.h>
using namespace std;
long long int MOD = 998244353;
long long int mod = 1e9 + 7;
long long int INF = 1e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int m;
  cin >> m;
  long long int deg[6] = {0};
  for (int i = 0; i < m; i++) {
    long long int x, y;
    cin >> x >> y;
    deg[x]++;
    deg[y]++;
  }
  for (int i = 1; i < 6; i++) {
    if (deg[i] > 2 || deg[i] < 2) {
      cout << "WIN";
      return 0;
    }
  }
  cout << "FAIL";
  return 0;
}
