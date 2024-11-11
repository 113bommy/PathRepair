#include <bits/stdc++.h>
using namespace std;
string itos(int x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
int b[110][110], n, m, k, res = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> b[i][j];
  if (n <= k) {
    for (int i = 0; i < (1 << n); i++) {
      int now = 0;
      for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int k = 0; k < n; k++) sum += (b[k][j] == (i >> k) & 1);
        now += min(sum, n - sum);
      }
      res = min(res, now);
    }
  } else {
    for (int i = 0; i < n; i++) {
      int now = 0;
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        int sum = 0;
        for (int k = 0; k < m; k++) sum += (b[j][k] == b[i][k]);
        now += min(sum, m - sum);
      }
      res = min(res, now);
    }
  }
  cout << (res > k ? -1 : res) << endl;
  return 0;
}
