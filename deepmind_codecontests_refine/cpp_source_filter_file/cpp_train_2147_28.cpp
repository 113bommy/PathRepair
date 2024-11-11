#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  long long k[3], t[3];
  int n;
  for (int i = 0; i < 3; i++) cin >> k[i];
  for (int i = 0; i < 3; i++) cin >> t[i];
  cin >> n;
  vector<vector<long long> > d(4, vector<long long>(n, 0));
  int x, cmax = 0;
  for (int j = 0; j < n; j++) {
    cin >> x;
    for (int i = 0; i < 3; i++) {
      d[i][j] = x;
      if (i) d[i][j] = max(d[i][j], d[i - 1][j] + t[i - 1]);
      if (j >= k[i]) d[i][j] = max(d[i + 1][j - k[i]], d[i][j]);
    }
    d[3][j] = d[2][j] + t[2];
    if (d[3][j] - x > cmax) cmax = d[3][j] - x;
  }
  cout << cmax;
  return 0;
}
