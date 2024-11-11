#include <bits/stdc++.h>
using namespace std;
const int mod = 1e+9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<vector<long long> > chs =
      vector<vector<long long> >(n, vector<long long>(n, 0));
  vector<long long> diagp = vector<long long>(2 * n + 1, 0);
  vector<long long> diagm = vector<long long>(2 * n + 1, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> chs[i][j];
      diagp[i + j] += chs[i][j];
      diagm[i - j + (n - 1)] += chs[i][j];
    }
  }
  long long max0 = 0, max1 = 0;
  int x1 = 0, y1 = 0, x2 = 0, y2 = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j) % 2 == 0) {
        if (max0 < diagp[i + j] + diagm[i - j + n - 1] - chs[i][j]) {
          max0 = diagp[i + j] + diagm[i - j + n - 1] - chs[i][j];
          x1 = i;
          y1 = j;
        }
      } else {
        if (max1 < diagp[i + j] + diagm[i - j + n - 1] - chs[i][j]) {
          max1 = diagp[i + j] + diagm[i - j + n - 1] - chs[i][j];
          x2 = i;
          y2 = j;
        }
      }
    }
  }
  cout << max1 + max0 << "\n";
  cout << (x1 + 1) << " " << (y1 + 1) << " " << (x2 + 1) << " " << (y2 + 1)
       << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) solve();
  return 0;
}
