#include <bits/stdc++.h>
using namespace std;
const double Pi = acos(-1.0);
const int INF = 1 << 29;
const int MAXK = 1005;
const long long MOD = 1000000007;
int K;
long long A[MAXK];
long long Pascal[MAXK][MAXK];
int main(int argc, char** argv) {
  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < MAXK; i++) {
    Pascal[i][0] = 1;
    Pascal[i][i] = 1;
  }
  for (int i = 2; i < MAXK; i++) {
    for (int j = 1; j < i; j++) {
      Pascal[i][j] = (Pascal[i - 1][j - 1] + Pascal[i - 1][j]) % MOD;
    }
  }
  long long x = 1;
  long long n = A[0];
  for (int i = 1; i < K; i++) {
    x = x * Pascal[n + A[i] - 1][n] % MOD;
    n = n + A[i];
  }
  cout << x << endl;
  return 0;
}
