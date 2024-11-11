#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
const int mod = 1000000007;
const int inf = 1e9 + 10;
const long long INF = 1e18;
int n, m, k;
int C[maxn][2 * maxn];
void init() {
  memset(C, 0, sizeof(C));
  for (int i = 0; i <= 1000; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
}
int MAIN() {
  cin >> n >> m >> k;
  init();
  cout << (1LL * C[n - 1][2 * k] * C[m - 1][2 * k]) % mod << endl;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cout << fixed << setprecision(16);
  int ret = MAIN();
  return ret;
}
