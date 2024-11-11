#include <bits/stdc++.h>
using namespace std;
ifstream fin("INPUT.txt");
ofstream fout("OUTPUT.txt");
const int N = 502;
const int M = 20;
const long long INF = 1e18 + 1;
int mod = 1000000007;
int n, m, k, d, l;
int dp[N][26][26] = {0};
char a[N][N] = {0};
int main() {
  ios::sync_with_stdio(false);
  cout.precision(10);
  cin >> n >> m;
  for (int i = 0; i < n; (i++))
    for (int j = 0; j < m; (j++)) cin >> a[i][j];
  for (int size = 0; size < n; size++)
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < 26; j++) {
        if (i == j) {
          dp[size][i][j] = mod;
          continue;
        }
        if (a[size][0] != 'a' + i) dp[size][i][j]++;
        if (m > 1 && a[size][1] != 'a' + j) dp[size][i][j]++;
        for (int k = 2; k < m; k++)
          if ((k & 1) == 0 && a[size][k] != 'a' + i)
            dp[size][i][j]++;
          else if ((k & 1) == 1 && a[size][k] != 'a' + j)
            dp[size][i][j]++;
      }
  for (int i = 1; i < n; i++) {
    for (int ifirst = 0; ifirst < 26; ifirst++)
      for (int jfirst = 0; jfirst < 26; jfirst++) {
        int Min = mod;
        for (int isec = 0; isec < 26; isec++)
          for (int jsec = 0; jsec < 26; jsec++)
            if (ifirst == isec || jfirst == jsec)
              continue;
            else if (Min > dp[i][ifirst][jfirst] + dp[i - 1][isec][jsec])
              Min = dp[i][ifirst][jfirst] + dp[i - 1][isec][jsec];
        dp[i][ifirst][jfirst] = Min;
      }
  }
  char ans[N][N] = {0};
  int noti = -1, notj = -1;
  for (int s = n - 1; s >= 0; s--) {
    int Min = mod;
    pair<int, int> index;
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < 26; j++)
        if (i == noti || j == notj)
          continue;
        else if (Min > dp[s][i][j]) {
          Min = dp[s][i][j];
          index = make_pair(i, j);
        }
    ans[s][0] = 'a' + index.first;
    if (m > 1) ans[s][1] = 'a' + index.second;
    for (int i = 2; i < m; i++)
      ans[s][i] = (i & 1) == 0 ? 'a' + index.first : 'a' + index.second;
    noti = index.first;
    notj = index.second;
  }
  int Min = mod;
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < 26; j++)
      if (dp[n - 1][i][j] < Min) Min = dp[n - 1][i][j];
  cout << Min << endl;
  for (int i = 0; i < n; i++) cout << ans[i] << endl;
  return 0;
}
