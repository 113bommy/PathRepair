#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
long long DP[N][2];
int S[N];
int X[N];
int main() {
  long long s, x, wsp;
  int i, j, k;
  cin >> s >> x;
  wsp = 0;
  if (s == x) wsp -= 2;
  i = 0;
  while (s > 0) {
    S[i++] = s % 2;
    s /= 2;
  }
  j = 0;
  while (x > 0) {
    X[j++] = x % 2;
    x /= 2;
  }
  if (S[0] == 0 && X[0] == 0) DP[0][0] = DP[0][1] = 1;
  if (S[0] == 0 && X[0] == 1)
    ;
  if (S[0] == 1 && X[0] == 0)
    ;
  if (S[0] == 1 && X[0] == 1) DP[0][0] = 2;
  i = max(j, k);
  for (k = 1; k <= i; k++) {
    if (S[k] == 0 && X[k] == 0) {
      DP[k][0] = DP[k - 1][0];
      DP[k][1] = DP[k - 1][0];
    }
    if (S[k] == 0 && X[k] == 1) {
      DP[k][1] = 2 * DP[k - 1][1];
    }
    if (S[k] == 1 && X[k] == 0) {
      DP[k][0] = DP[k - 1][1];
      DP[k][1] = DP[k - 1][1];
    }
    if (S[k] == 1 && X[k] == 1) {
      DP[k][0] = 2 * DP[k - 1][0];
    }
  }
  cout << DP[i - 1][0] + wsp << "\n";
  return 0;
}
