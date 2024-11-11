#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long l[2005][2005], r[2005][2005];
int main() {
  string S;
  cin >> S;
  int N = S.length();
  l[0][0] = 1;
  for (int i = 0; i < N; i++) {
    if (S[i] != ')') {
      for (int j = 0; j <= N; j++) {
        if (j > 0) l[i + 1][j] = (l[i][j - 1] + l[i + 1][j]) % MOD;
        if (S[i] == '?') l[i + 1][j] = (l[i][j] + l[i + 1][j]) % MOD;
      }
    } else {
      for (int j = 0; j <= N; j++) l[i + 1][j] = l[i][j];
    }
  }
  r[N][0] = 1;
  for (int i = N; i > 0; i--) {
    if (S[i - 1] != '(') {
      for (int j = 0; j <= N; j++) {
        if (j > 0) r[i - 1][j] = (r[i][j - 1] + r[i - 1][j]) % MOD;
        if (S[i - 1] == '?') r[i - 1][j] = (r[i][j] + r[i - 1][j]) % MOD;
      }
    } else {
      for (int j = 0; j <= N; j++) r[i - 1][j] = r[i][j];
    }
  }
  long long ans = 0;
  for (int i = 1; i < N; i++) {
    for (int j = 1; j <= N; j++)
      ans = (j * (l[i][j] * r[i][j]) % MOD + ans) % MOD;
  }
  cout << ans << endl;
}
