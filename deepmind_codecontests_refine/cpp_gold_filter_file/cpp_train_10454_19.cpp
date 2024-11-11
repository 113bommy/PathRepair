#include <bits/stdc++.h>
using namespace std;
const int T = 1e3 + 5;
long long i, j, L1, R1, L2, R2, k, x, n, m;
long long dp[T][3][3];
string o;
char ch[3] = {'A', 'C', 'B'};
long long dp2[T][3], sul[T];
long long get(long long len, long long l, long long r) { return dp[len][l][r]; }
void preprocess() {
  long long l, I, J, K;
  dp[2][0][1] = 1;
  for (l = 3; l <= 102; l++)
    for (I = 0; I < 3; I++)
      for (J = 0; J < 3; J++) {
        for (K = 0; K < 3; K++)
          dp[l][I][J] = max(dp[l][I][J], dp[l - 1][I][K] + (K == 0 && J == 1));
      }
}
long long countt() {
  dp2[1][0] = L1;
  dp2[1][1] = R1;
  sul[1] = i;
  dp2[2][0] = L2;
  dp2[2][1] = R2;
  sul[2] = j;
  long long i;
  for (i = 3; i <= k; i++) {
    dp2[i][0] = dp2[i - 2][0];
    dp2[i][1] = dp2[i - 1][1];
    sul[i] =
        sul[i - 2] + sul[i - 1] + (dp2[i - 2][1] == 0 && dp2[i - 1][0] == 1);
  }
  return sul[k];
}
string getString(long long len, long long I, long long J, long long need) {
  string s = o;
  if (len == 1) {
    s += ch[I];
    return s;
  }
  long long j;
  if (need == 0) {
    s += ch[I];
    for (j = 0; j < len - 2; j++) s += "X";
    s += ch[J];
    return s;
  }
  if (I == 0) {
    s += "AC";
    for (j = 0; j < need - 1; j++) {
      s += "AC";
    }
    for (j = 0; j < len - 2 * need - 1; j++) {
      s += "X";
    }
    if (2 * need < len) s += ch[J];
    return s;
  } else {
    s += ch[I];
    for (j = 0; j < need; j++) s += "AC";
    for (j = 0; j < len - 2 * need - 2; j++) s += "X";
    if (len > 2 * need + 1) s += ch[J];
    return s;
  }
}
int main() {
  preprocess();
  cin >> k >> x >> n >> m;
  for (L1 = 0; L1 < 3; L1++)
    for (R1 = 0; R1 < 3; R1++)
      for (L2 = 0; L2 < 3; L2++)
        for (R2 = 0; R2 < 3; R2++) {
          if (n == 1 && L1 != R1) continue;
          if (m == 1 && L2 != R2) continue;
          long long N1 = get(n, L1, R1);
          long long N2 = get(m, L2, R2);
          long long st1 = ((n == 2 && L1 == 0 && R1 == 1) ? 1 : 0);
          long long st2 = ((m == 2 && L2 == 0 && R2 == 1) ? 1 : 0);
          for (i = st1; i <= N1; i++)
            for (j = st2; j <= N2; j++) {
              if (countt() == x) {
                cout << getString(n, L1, R1, i) << endl;
                cout << getString(m, L2, R2, j) << endl;
                return 0;
              }
            }
        }
  cout << "Happy new year!" << endl;
  return 0;
}
