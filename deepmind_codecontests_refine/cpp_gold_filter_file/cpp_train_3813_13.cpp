#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int com[105][105];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      com[j][i] = com[j - 1][i] + a[j][i];
    }
  }
  int delet = 0, score = 0;
  for (int i = 1; i <= m; i++) {
    int colomscore = 0, how = 0, deletcolom = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j][i] == 1) {
        int gotoo = min(j + k - 1, n);
        how = com[gotoo][i] - com[j][i] + a[j][i];
        if (colomscore < how)
          colomscore = how, deletcolom = com[j][i] - a[j][i];
      }
    }
    delet += deletcolom;
    score += colomscore;
  }
  cout << score << " " << delet;
}
