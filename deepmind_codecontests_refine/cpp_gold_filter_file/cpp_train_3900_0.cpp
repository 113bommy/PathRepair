#include <bits/stdc++.h>
using namespace std;
long long int n, a[2007][2007], m[4007], sec[4007], res[2007][2007];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long int i = 0; i < n; ++i) {
    for (long long int j = 0; j < n; ++j) cin >> a[i][j];
  }
  pair<long long int, long long int> wmax = {0, 0}, bmax = {0, 1};
  for (long long int i = 0; i < n; ++i) {
    for (long long int j = 0; j < n; ++j) {
      m[j - i + 2000] += a[i][j];
      sec[(n - j - 1) - i + 2000] += a[i][j];
    }
  }
  for (long long int i = 0; i < n; ++i) {
    for (long long int j = 0; j < n; ++j) {
      res[i][j] = m[j - i + 2000] + sec[(n - j - 1) - i + 2000] - a[i][j];
    }
  }
  for (long long int i = 0; i < n; ++i) {
    for (long long int j = 0; j < n; ++j) {
      if ((i + j) % 2 == 0) {
        if (res[i][j] > res[wmax.first][wmax.second]) {
          wmax.first = i;
          wmax.second = j;
        }
      } else {
        if (res[i][j] > res[bmax.first][bmax.second]) {
          bmax.first = i;
          bmax.second = j;
        }
      }
    }
  }
  cout << res[bmax.first][bmax.second] + res[wmax.first][wmax.second] << '\n';
  cout << bmax.first + 1 << ' ' << bmax.second + 1 << ' ' << wmax.first + 1
       << ' ' << wmax.second + 1 << '\n';
  return 0;
}
