#include <bits/stdc++.h>
using namespace std;
const int N = 222;
int n, m, a[N][N], b[N], ans[N];
vector<int> FlipCol[2][N];
void Calc0(int flipRow0, int cnt0) {
  FlipCol[flipRow0][cnt0].clear();
  for (int i = 0; i < n; ++i) b[i] = a[0][i];
  if (flipRow0) {
    for (int i = 0; i < n; ++i) b[i] ^= 1;
  }
  for (int i = 0; i < n; ++i) {
    if (b[i] != (i >= cnt0)) FlipCol[flipRow0][cnt0].push_back(i);
  }
}
int Calc(int row, int flipRow0, int cnt0) {
  int cnt0thisRow, cnt0Row0;
  if (cnt0 > n * row) {
    if (cnt0 <= n * row + row)
      cnt0thisRow = (cnt0 - 1) % n + 1;
    else
      cnt0thisRow = n;
    cnt0Row0 = n;
  } else {
    cnt0thisRow = 0;
    cnt0Row0 = min(cnt0, n);
  }
  for (int i = 0; i < n; ++i) b[i] = a[row][i];
  for (int col : FlipCol[flipRow0][cnt0Row0]) b[col] ^= 1;
  int cntCorrect = 0;
  for (int i = 0; i < n; ++i) {
    cntCorrect += (b[i] == (i >= cnt0thisRow));
  }
  if (cntCorrect == n) return 0;
  if (cntCorrect == 0) return 1;
  return -1;
}
int main() {
  cin >> m >> n;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j) cin >> a[i][j];
  for (int flipRow0 = 0; flipRow0 < 2; ++flipRow0) {
    for (int cnt0 = 0; cnt0 <= n; ++cnt0) {
      Calc0(flipRow0, cnt0);
    }
  }
  for (int flipRow0 = 0; flipRow0 < 2; ++flipRow0) {
    for (int cnt0 = 0; cnt0 <= m * n; ++cnt0) {
      int cntNeg = 0;
      for (int i = 1; i < m; ++i) {
        ans[i] = Calc(i, flipRow0, cnt0);
        if (ans[i] == -1) {
          cntNeg++;
          break;
        }
      }
      if (cntNeg == 0) {
        cout << "YES\n";
        int cnt0Row0 = min(cnt0, n);
        cout << flipRow0;
        for (int i = 1; i < m; ++i) cout << ans[i];
        cout << endl;
        memset(ans, 0, sizeof(ans));
        for (int col : FlipCol[flipRow0][cnt0Row0]) ans[col] = 1;
        for (int i = 0; i < n; ++i) cout << ans[i];
        return 0;
      }
    }
  }
  cout << "NO";
}
