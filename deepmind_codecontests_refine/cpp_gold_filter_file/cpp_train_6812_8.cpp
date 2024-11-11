#include <bits/stdc++.h>
using namespace std;
const long long int MAXN = 30;
const long long int LOGN = 17;
const long long int ROOTN = 320;
const long long int MOD = 1e9 + 7;
const long long int INF = 1e17 + 8;
const long long int NN = 103;
bool dp[NN][NN][10 * NN], v[NN][NN][10 * NN];
long long int N, M, K, A[NN][NN];
inline void init() {
  long long int i, j, k;
  for (i = 1; i <= NN - 1; i++)
    for (j = 1; j <= NN - 1; j++)
      for (k = 0; k < 1001; k++) dp[i][j][k] = v[i][j][k] = false;
}
bool DP(long long int i, long long int j, long long int k) {
  if (i < 1 or i > N or j < 1 or j > M or k < 0 or k > 1000) return false;
  if (v[i][j][k]) return dp[i][j][k];
  if (i == 1) return (k == A[i][j]);
  v[i][j][k] = true;
  dp[i][j][k] = DP(i - 1, j - 1, k - A[i][j]) or DP(i - 1, j + 1, k - A[i][j]);
  return dp[i][j][k];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
  cin >> N >> M >> K;
  long long int i, j, k, ans = -1, c;
  char g;
  for (i = 1; i <= N; i++)
    for (j = 1; j <= M; j++) {
      cin >> g;
      A[i][j] = (long long int)(g - '0');
    }
  for (k = 0; k < 1001; k += K + 1) {
    for (j = 1; j <= M; j++) {
      if (DP(N, j, k)) {
        c = j;
        ans = k;
      }
    }
  }
  if (ans == -1) {
    cout << -1;
    exit(0);
  }
  cout << ans << endl << c << endl;
  i = N;
  j = c;
  do {
    if (DP(i - 1, j + 1, ans - A[i][j])) {
      ans -= A[i][j];
      i--;
      j++;
      cout << 'R';
    } else if (DP(i - 1, j - 1, ans - A[i][j])) {
      ans -= A[i][j];
      i--;
      j--;
      cout << 'L';
    } else {
      cout << "DANGER\n";
      exit(0);
    }
  } while (i > 1);
  return 0;
}
