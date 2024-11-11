#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10;
const int MOD = 1000000007;
long long f[N][4][4];
string str;
int n, answer;
const string legal[] = {"00", "01", "1*", "*1", "*2", "**"};
const int num[6][2] = {{0, 0}, {0, 1}, {1, 3}, {3, 1}, {3, 2}, {3, 3}};
bool init() {
  memset(f, 0, sizeof(f));
  if (n >= 2) {
    string s = str.substr(0, 2);
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < 2; ++j) {
        if (s[j] == '?') continue;
        if (s[j] != legal[i][j]) goto NEXT;
      }
      f[1][num[i][0]][num[i][1]] = 1;
    NEXT:;
    }
  } else {
    answer = 0;
    if (str[0] == '?') answer = 2;
    if (str[0] == '0') answer = 1;
    if (str[0] == '*') answer = 1;
    return 0;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> str;
  n = str.size();
  if (!init()) goto PRINT;
  for (int i = 2; i < n; ++i) {
    if (str[i] == '0') {
      f[i][0][0] = (f[i - 1][0][0] + f[i - 1][1][0] + 0 + 0) % MOD;
      f[i][1][0] = f[i - 1][3][1];
      f[i][2][0] = 0;
      f[i][3][0] = 0;
    } else if (str[i] == '1') {
      f[i][0][1] = (f[i - 1][0][0] + f[i - 1][1][0] + 0 + 0) % MOD;
      f[i][1][1] = f[i - 1][3][1];
      f[i][2][1] = 0;
      f[i][3][1] = (0 + f[i - 1][1][3] + f[i - 1][2][3] + f[i - 1][3][3]) % MOD;
    } else if (str[i] == '2') {
      f[i][0][2] = 0;
      f[i][1][2] = 0;
      f[i][2][2] = 0;
      f[i][3][2] = (0 + f[i - 1][1][3] + f[i - 1][2][3] + f[i - 1][3][3]) % MOD;
    } else if (str[i] == '*') {
      f[i][0][3] = 0;
      f[i][1][3] = (f[i - 1][0][1] + f[i - 1][1][1] + 0 + 0) % MOD;
      f[i][2][3] = f[i - 1][3][2];
      f[i][3][3] = (0 + f[i - 1][1][3] + f[i - 1][2][3] + f[i - 1][3][3]) % MOD;
    } else {
      f[i][0][0] = (f[i - 1][0][0] + f[i - 1][1][0] + 0 + 0) % MOD;
      f[i][1][0] = f[i - 1][3][1];
      f[i][2][0] = 0;
      f[i][3][0] = 0;
      f[i][0][1] = (f[i - 1][0][0] + f[i - 1][1][0] + 0 + 0) % MOD;
      f[i][1][1] = f[i - 1][3][1];
      f[i][2][1] = 0;
      f[i][3][1] = (0 + f[i - 1][1][3] + f[i - 1][2][3] + f[i - 1][3][3]) % MOD;
      f[i][0][2] = 0;
      f[i][1][2] = 0;
      f[i][2][2] = 0;
      f[i][3][2] = (0 + f[i - 1][1][3] + f[i - 1][2][3] + f[i - 1][3][3]) % MOD;
      f[i][0][3] = 0;
      f[i][1][3] = (f[i - 1][0][1] + f[i - 1][1][1] + 0 + 0) % MOD;
      f[i][2][3] = f[i - 1][3][2];
      f[i][3][3] = (0 + f[i - 1][1][3] + f[i - 1][2][3] + f[i - 1][3][3]) % MOD;
    }
  }
  answer = (f[n - 1][0][0] + f[n - 1][1][0] + f[n - 1][1][3] + f[n - 1][2][3] +
            f[n - 1][3][1] + f[n - 1][3][3]) %
           MOD;
PRINT:
  cout << answer << endl;
}
