#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const int N = 2001;
int n, a[N][N], dia[2][2 * N], mx[2];
pair<int, int> po[2];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (n); ++j) {
      cin >> a[i][j];
      dia[0][i + j - 1] += a[i][j];
      dia[1][j - i + n] += a[i][j];
    }
  mx[0] = mx[1] = -1;
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (n); ++j) {
      if (mx[((i + j) % 2)] < dia[0][i + j - 1] + dia[1][j - i + n] - a[i][j]) {
        mx[((i + j) % 2)] = dia[0][i + j - 1] + dia[1][j - i + n] - a[i][j];
        po[((i + j) % 2)] = {i, j};
      }
    }
  cout << mx[0] + mx[1] << '\n'
       << po[0].first << ' ' << po[0].second << ' ' << po[1].first << ' '
       << po[1].second;
  return 0;
}
