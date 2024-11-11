#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  bool x[2][501][501] = {};
  x[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    int c;
    cin >> c;
    int curr = (i + 1) % 2;
    int prev = i % 2;
    for (int j = 0; j <= 500; j++) {
      for (int f = 0; f <= 500; f++) {
        x[curr][j][f] |= x[prev][j][f];
        x[curr][j][f] |= j - c >= 0 && x[prev][j - c][f];
        x[curr][j][f] |= j - c >= 0 && f - c >= 0 && x[prev][j - c][f - c];
      }
    }
  }
  stringstream ss;
  int cnt = 0;
  for (int i = 0; i <= 500; ++i) {
    if (x[n % 2][k][i]) {
      cnt++;
      ss << i << ' ';
    }
  }
  cout << cnt << endl << ss.str();
  return 0;
}
