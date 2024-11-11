#include <bits/stdc++.h>
using namespace std;
const int M = 2, N = 8;
int t, a[M], b[M], c[M], A[M], B[M], C[M], d[N], D[N], ans[N];
void input() {
  memset(ans, 0, sizeof ans);
  cin >> a[0] >> b[0] >> c[0];
  cin >> a[1] >> b[1] >> c[1];
  for (int i = 7; i; i--) cin >> d[i];
}
void solve() {
  for (int i = 0; i <= d[5]; i++)
    for (int j = 0; j <= d[6]; j++) {
      A[0] = a[0] - i - j;
      A[1] = a[1] - (d[5] - i) - (d[6] - j);
      B[0] = b[0] - j;
      B[1] = b[1] - (d[6] - j);
      C[0] = c[0] - i;
      C[1] = c[1] - (d[5] - i);
      if (min({A[0], A[1], B[0], B[1], C[0], C[1]}) < 0) continue;
      copy(d, d + N, D);
      D[5] -= i;
      D[6] -= j;
      memset(ans, 0, sizeof ans);
      ans[5] = i;
      ans[6] = j;
      if (A[0] < min(B[0], C[0])) {
        int x = min(D[3], min(B[0], C[0]) - A[0]);
        B[0] -= x;
        C[0] -= x;
        ans[3] += x;
        D[3] -= x;
      }
      if (A[1] < min(B[1], C[1])) {
        int x = min(D[3], min(B[1], C[1]) - A[1]);
        B[1] -= x;
        C[1] -= x;
        D[3] -= x;
      }
      int x = min({A[0], B[0], C[0]}), y = min({A[1], B[1], C[1]});
      if (x + y < D[3] + D[7]) continue;
      int z = min(D[7], x);
      ans[7] += z;
      x -= z;
      A[0] -= z;
      B[0] -= z;
      C[0] -= z;
      D[7] -= z;
      z = D[7];
      A[1] -= z;
      B[1] -= z;
      C[1] -= z;
      y -= z;
      z = min(D[3], x);
      ans[3] += z;
      B[0] -= z;
      C[0] -= z;
      D[3] -= z;
      z = D[3];
      B[1] -= z;
      C[1] -= z;
      cout << ans[7] << ' ' << j << ' ' << i << ' ' << min(D[1], A[0]) << ' '
           << ans[3] << ' ' << min(D[2], B[0]) << ' ' << min(D[1], C[0])
           << '\n';
      return;
    }
  cout << "-1\n";
}
int Get(int x) {
  int cnt = 0;
  for (int i = 1; i <= 7; i++)
    if (i & x) cnt += d[i];
  return cnt;
}
void QUERY() {
  input();
  if (Get(1) > c[0] + c[1] || Get(2) > b[0] + b[1] || Get(4) > a[0] + a[1]) {
    cout << "-1\n";
    return;
  }
  solve();
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> t;
  while (t--) QUERY();
}
