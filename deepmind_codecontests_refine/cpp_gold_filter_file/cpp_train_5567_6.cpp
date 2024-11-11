#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<int> a(30001);
  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    a[j]++;
  }
  vector<vector<int>> f(30001, vector<int>(561, -1e8));
  f[d][280] = a[d];
  int s = a[d];
  for (int i = d + 1; i < 30001; i++) {
    for (int j = 1; j < 560; j++) {
      if (j - 280 + d > 0 && i - j + 280 - d > 0)
        f[i][j] = max(f[i - j + 280 - d][j + 1], f[i - j + 280 - d][j]) + a[i];
      if (j - 280 + d > 1 && i - j + 280 - d > 0)
        f[i][j] = max(f[i][j], f[i - j + 280 - d][j - 1] + a[i]);
      s = max(s, f[i][j]);
    }
  }
  cout << s << endl;
}
