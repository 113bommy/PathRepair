#include <bits/stdc++.h>
using namespace std;
int ix[4] = {0, 1, 0, -1};
int iy[4] = {1, 0, -1, 0};
int main() {
  int n, r;
  cin >> n >> r;
  string s;
  cin >> s;
  int m = s.size();
  vector<vector<int> > M(n + 2, vector<int>(m + 2, 0));
  for (int j = 1; j <= m; ++j) M[1][j] = s[j - 1] - '0';
  for (int i = 2; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      char c;
      cin >> c;
      M[i][j] = c - '0';
    }
  vector<vector<vector<vector<int> > > > D(
      n + 2, vector<vector<vector<int> > >(
                 m + 2, vector<vector<int> >(4, vector<int>(2, 0))));
  bool primer = true;
  int i = 1;
  int j = 1;
  int d = 0;
  int c = 0;
  for (int t = 1; t <= r; ++t) {
    if (D[i][j][d][c] and primer) {
      primer = false;
      int cic = t - D[i][j][d][c];
      t += (r - t) / cic;
    }
    D[i][j][d][c] = t;
    int b = M[i][j];
    while (M[i][j] == b) {
      i += ix[d];
      j += iy[d];
    }
    i -= ix[d];
    j -= iy[d];
    int d2 = (d + 2 * c + 3) % 4;
    while (M[i][j] == b) {
      i += ix[d2];
      j += iy[d2];
    }
    i -= ix[d2];
    j -= iy[d2];
    int i2 = i + ix[d];
    int j2 = j + iy[d];
    if (M[i2][j2]) {
      i = i2;
      j = j2;
    } else {
      if (c == 0)
        c = 1;
      else {
        c = 0;
        d = (d + 1) % 4;
      }
    }
  }
  cout << M[i][j] << endl;
}
