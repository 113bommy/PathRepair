#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a;
  cin >> a;
  int parA[a];
  int degA[a];
  memset(degA, 0, sizeof degA);
  for (int i = 0; i < a - 1; i++) {
    int d;
    cin >> d;
    d--;
    degA[d]++;
    parA[i + 1] = d;
  }
  int leaIA[n];
  for (int i = 0; i < n; i++) {
    cin >> leaIA[i];
    leaIA[i]--;
  }
  int b;
  cin >> b;
  int parB[b];
  int degB[b];
  memset(degB, 0, sizeof degB);
  for (int i = 0; i < b - 1; i++) {
    int d;
    cin >> d;
    d--;
    degB[d]++;
    parB[i + 1] = d;
  }
  int leaIB[n];
  for (int i = 0; i < n; i++) {
    cin >> leaIB[i];
    leaIB[i]--;
  }
  int cntTop[n][n];
  memset(cntTop, 0, sizeof cntTop);
  for (int i = 0; i < n; i++) {
    int degs[a];
    memcpy(degs, degA, sizeof degA);
    for (int j = i; j < n; j++) {
      int c = leaIA[j];
      while (degs[c] == 0 && c != 0) {
        cntTop[i][j]++;
        c = parA[c];
        degs[c]--;
      }
      if (j > 0) cntTop[i][j] += cntTop[i][j - 1];
    }
  }
  int cntBot[n][n];
  memset(cntBot, 0, sizeof cntBot);
  for (int i = 0; i < n; i++) {
    int degs[b];
    memcpy(degs, degB, sizeof degs);
    for (int j = i; j < n; j++) {
      int c = leaIB[j];
      while (degs[c] == 0 && c != 0) {
        cntBot[i][j]++;
        c = parB[c];
        degs[c]--;
      }
      if (j > 0) cntBot[i][j] += cntBot[i][j - 1];
    }
  }
  int dp[n + 1];
  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i] = max(dp[i], dp[j - 1] + cntTop[j - 1][i - 1]);
      dp[i] = max(dp[i], dp[j - 1] + cntBot[j - 1][i - 1]);
    }
  }
  cout << dp[n] << endl;
}
