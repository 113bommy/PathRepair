#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
inline bool mina(A &first, B second) {
  return (first > second) ? (first = second, 1) : 0;
}
template <class A, class B>
inline bool maxa(A &first, B second) {
  return (first < second) ? (first = second, 1) : 0;
}
const int MAXN = 1005;
int N, K;
int dp[5][MAXN];
int in[5][MAXN];
int ind[5][MAXN];
int main() {
  scanf("%d %d", &N, &K);
  for (int i = 0; (i) < (K); ++(i)) {
    for (int j = 0; (j) < (N); ++(j)) {
      scanf("%d", &in[i][j]);
      dp[i][j] = 1;
      ind[i][in[i][j]] = j;
    }
  }
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < i; j++) {
      int temp = dp[0][j] + 1;
      int a = in[0][j];
      int b = in[0][i];
      for (int k = 1; k < K; k++) {
        int from = ind[k][a];
        int to = ind[k][b];
        if (from < to) {
          mina(temp, dp[k][from] + 1);
        } else {
          temp = 1;
        }
      }
      for (int k = 0; (k) < (K); ++(k)) {
        maxa(dp[k][ind[k][a]], temp);
      }
    }
  }
  int ans = 1;
  for (int i = 0; (i) < (N); ++(i)) {
    maxa(ans, dp[0][i]);
  }
  cout << ans << endl;
  return 0;
}
