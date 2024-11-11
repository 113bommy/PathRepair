#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1002][1002];
int m1[1002][1002];
int m2[1002][1002];
int f1[1002][1002];
int f2[1002][1002];
void print(int mm[1002][1002], int n, int m) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << mm[i][j] << " ";
    }
    cout << endl;
  }
}
int main(int argc, const char* argv[]) {
  cin >> n >> m;
  for (int i = 0; i <= n; ++i) {
    memset(a[i], 0, sizeof(int) * (m + 2));
    memset(m1[i], 0, sizeof(int) * (m + 2));
    memset(m2[i], 0, sizeof(int) * (m + 2));
    memset(f1[i], 0, sizeof(int) * (m + 2));
    memset(f2[i], 0, sizeof(int) * (m + 2));
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      m1[i][j] = a[i][j] + max(m1[i - 1][j], m1[i][j - 1]);
      m2[n - i + 1][m - j + 1] =
          a[n - i + 1][m - j + 1] +
          max(m2[n - i + 2][m - j + 1], m2[n - i + 1][m - j + 2]);
      f1[n - i + 1][j] =
          a[n - i + 1][j] + max(f1[n - i + 2][j], f1[n - i + 1][j - 1]);
      f2[i][m - j + 1] =
          a[i][m - j + 1] + max(f2[i - 1][m - j + 1], f2[i][m - j + 2]);
    }
  }
  int max_score = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int score1 = m1[i - 1][j] + m2[i + 1][j] + f1[i][j - 1] + f2[i][j + 1];
      int score2 = m1[i][j - 1] + m2[i][j + 1] + f1[i + 1][j] + f2[i - 1][j];
      int score = max(score1, score2);
      if (score > max_score) max_score = score;
    }
  }
  cout << max_score << endl;
  return 0;
}
