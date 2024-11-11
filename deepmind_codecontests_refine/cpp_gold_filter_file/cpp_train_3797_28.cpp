#include <bits/stdc++.h>
using namespace std;
int DP[2][50][50];
int len[2];
int convert[50][3];
int rec[50][50];
int recur(int a, int b) {
  if (a == len[0] && b == len[1]) return 0;
  if (a == len[0] || b == len[1]) return 100;
  if (rec[a][b] != -1) return rec[a][b];
  int res = 100;
  for (int i = a; i < len[0]; i++)
    for (int j = b; j < len[1]; j++) {
      if (DP[0][a][i] & DP[1][b][j]) {
        res = min(recur(i + 1, j + 1) + 1, res);
      }
    }
  rec[a][b] = res;
  return res;
}
int main() {
  memset(DP, 0, sizeof(DP));
  memset(rec, -1, sizeof(rec));
  for (int i = 0; i < 2; i++) {
    string str;
    cin >> str;
    len[i] = str.length();
    for (int j = 0; j < str.length(); j++) DP[i][j][j] = (1 << (str[j] - 'a'));
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    convert[i][0] = (1 << (str[0] - 'a'));
    convert[i][1] = (1 << (str[3] - 'a'));
    convert[i][2] = (1 << (str[4] - 'a'));
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < len[i]; j++)
      for (int k = 0; k + j < len[i]; k++)
        for (int l = 0; l < j; l++)
          for (int m = 0; m < n; m++) {
            if ((DP[i][k][k + l] & convert[m][1]) &&
                (DP[i][l + k + 1][j + k] & convert[m][2])) {
              DP[i][k][j + k] |= convert[m][0];
            }
          }
  int res = recur(0, 0);
  if (res >= 100)
    cout << "-1";
  else
    cout << res;
}
