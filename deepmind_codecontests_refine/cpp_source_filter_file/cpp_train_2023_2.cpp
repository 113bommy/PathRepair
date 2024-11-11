#include <bits/stdc++.h>
const int inf = (int)1e9;
const int mod = 1e9 + 7;
using namespace std;
int d[1000011][6];
char a[1000011];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 1; i <= n; i++) {
    a[i] = s[i - 1];
  }
  if (n == 1) {
    if (a[1] == '?') {
      cout << 2;
      return 0;
    } else if (a[1] == '0' || a[1] == '*') {
      cout << 1;
    } else
      cout << 0;
    return 0;
  }
  if (a[2] == '?') {
    d[1][1]++;
    d[1][5]++;
    d[1][3]++;
  } else if (a[2] == '*') {
    d[1][5]++;
    d[1][3]++;
  } else if (a[2] == '1') {
    d[1][1]++;
    d[1][5]++;
  } else if (a[2] == '0') {
    d[1][1]++;
  } else {
    d[1][5]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 5; j++) {
      if (a[i] != '?') {
        if (a[i] == '1' && j != 2 && j != 3) {
          continue;
        }
        if (a[i] == '2' && j != 4) {
          continue;
        }
        if (a[i] == '*' && j != 5) {
          continue;
        }
        if (a[i] == '0' && j != 1) {
          continue;
        }
      }
      if (j == 1 || j == 2) {
        d[i + 1][1] += d[i][j];
        d[i + 1][3] += d[i][j];
        d[i + 1][1] %= mod;
        d[i + 1][3] %= mod;
      } else if (j == 3) {
        d[i + 1][5] += d[i][j];
        d[i + 1][5] %= mod;
      } else if (j == 4) {
        d[i + 1][5] += d[i][j];
        d[i + 1][5] %= mod;
      } else {
        d[i + 1][4] += d[i][j];
        d[i + 1][2] += d[i][j];
        d[i + 1][5] += d[i][j];
        d[i + 1][4] %= mod;
        d[i + 1][2] %= mod;
        d[i + 1][5] %= mod;
      }
    }
  }
  long long sum = 0;
  if (a[n] == '?') {
    sum += d[n][1] + d[n][2] + d[n][5];
  } else if (a[n] == '0')
    sum += d[n][1];
  else if (a[n] == '1') {
    sum += d[n][2];
  } else if (a[n] == '*')
    sum += d[n][5];
  cout << endl << sum % mod;
  return 0;
}
