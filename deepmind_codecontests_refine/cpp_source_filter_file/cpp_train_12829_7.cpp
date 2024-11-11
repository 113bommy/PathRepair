#include <bits/stdc++.h>
using namespace std;
const int N = 200;
const int M = 2e3;
int A[M + 9], cnt[M + 9][N + 9], cntL[N + 9], cntR[N + 9], R[N + 9];
int main() {
  ios_base::sync_with_stdio(0);
  int a, b, n, T, cas = 0;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> A[i];
      for (int j = 1; j <= N; ++j) cnt[i][j] = cnt[i - 1][j];
      cnt[i][A[i]]++;
    }
    int res = 0;
    for (int i = 1; i <= N; ++i) {
      res = max(res, cnt[n][i]);
      cntL[i] = cntR[i] = 0;
      R[i] = n;
    }
    for (int i = 1; i <= n; ++i) {
      cntL[A[i]]++;
      while (i < R[A[i]] && cntR[A[i]] < cntL[A[i]]) {
        cntR[A[i]] += A[R[A[i]]] == A[i];
        R[A[i]]--;
      }
      if (cntL[A[i]] == cntR[A[i]]) {
        int mx = 0;
        for (int j = 1; j <= 26; ++j) {
          mx = max(mx, cnt[R[A[i]]][j] - cnt[i][j]);
          res = max(res, cntL[A[i]] * 2 + mx);
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}
