#include <bits/stdc++.h>
using namespace std;
int A[19][100001], l, r, N, B[19][100001], S[19][100001], q;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[0][i];
  }
  for (int i = 1; i < 19; i++) {
    for (int j = 0; j < N; j++) {
      if (j + (1 << (i - 1)) < N)
        A[i][j] = A[i - 1][j] + A[i - 1][j + (1 << (i - 1))];
      if (A[i][j] > 9) {
        B[i][j] = 1;
        A[i][j] %= 10;
      }
    }
  }
  for (int i = 1; i < 19; i++) {
    for (int k = 0; k < min((1 << i), N); k++) {
      S[i][k] = B[i][k];
      for (int j = k + (1 << i); j < N; j += (1 << i)) {
        S[i][j] = S[i][j - (1 << i)] + B[i][j];
      }
    }
  }
  cin >> q;
  for (int a, b; q > 0; q--) {
    cin >> a >> b;
    a--;
    b--;
    int ans = 0;
    for (int i = 1; i < 19; i++) {
      if (b - (1 << i) + 1 < min(a, 0)) break;
      if (a - (1 << i) >= 0)
        ans += (S[i][b - (1 << i) + 1] - S[i][a - (1 << i)]);
      else
        ans += S[i][b - (1 << i) + 1];
    }
    cout << ans << "\n";
  }
}
