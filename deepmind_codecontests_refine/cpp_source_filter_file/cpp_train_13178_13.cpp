#include <bits/stdc++.h>
using namespace std;
const int X = 5000009, P = 10000007, M = 129, Q = 100000001;
char s[X];
int dp[X];
int main() {
  scanf("%s", s);
  long long result = 1;
  dp[0] = 1;
  int L, R;
  L = R = s[0];
  int L2, R2;
  L2 = R2 = s[0];
  int m = M, m2 = M;
  for (int i = 1; s[i]; i++) {
    L = (L * M + s[i]) % P;
    R = (s[i] * m + R) % P;
    L2 = (L2 * M + s[i]) % Q;
    R2 = (s[i] * m2 + R2) % Q;
    m = (m * M) % P;
    m2 = (m2 * M) % Q;
    if (L == R && L2 == R2) {
      dp[i] = dp[(i + 1) / 2 - 1] + 1;
    } else {
      dp[i] = 0;
    }
    result += dp[i];
  }
  cout << result << endl;
  return 0;
}
