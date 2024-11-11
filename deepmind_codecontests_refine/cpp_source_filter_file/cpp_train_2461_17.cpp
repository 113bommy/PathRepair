#include <bits/stdc++.h>
using namespace std;
int n;
long long f[710][11][710][2], r;
char s[710];
int main() {
  cin >> s;
  n = strlen(s);
  for (int i = 0; i < 10; i++) f[0][i][0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 10; j++)
      for (int k = 0; k < 10; k++)
        for (int m = 0; m < 2; m++)
          for (int t = 0; t <= (m ? 9 : s[i] - '0'); t++)
            f[i + 1][j][k + (t >= j)][m | t < (s[i] - '0')] =
                (f[i + 1][j][k + (t >= j)][m | t < (s[i] - '0')] +
                 f[i][j][k][m]) %
                1000000007ll;
  for (int k = 1; k <= 9; k++) {
    long long cp = 1;
    for (int i = 1; i <= n; i++) {
      r = (r + cp * (f[n][k][i][0] + f[n][k][i][1]) % 1000000007ll) %
          1000000007ll;
      cp = (cp * 10 + 1) % 1000000007ll;
    }
  }
  cout << r;
}
