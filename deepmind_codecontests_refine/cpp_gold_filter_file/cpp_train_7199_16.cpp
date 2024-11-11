#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, ans, k, cond, p, i, j;
  cin >> n;
  vector<int> A(n + 1), B(n + 1), Z(n + 1), S(n + 1);
  for (i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (i = 1; i <= n; i++) {
    cin >> B[i];
  }
  for (i = 0; i <= n; i++) {
    Z[i] = 0;
  }
  for (i = 1; i <= n; i++) {
    Z[B[i]] = i;
  }
  for (i = 0; i <= n; i++) {
    S[i] = 0;
  }
  for (i = 1; i <= n; i++) {
    S[A[i]] = 1;
  }
  ans = 0;
  for (i = 1; i <= n; i++) {
    k = Z[i] + (n + 1 - i);
    ans = max(ans, k);
  }
  for (i = 2; i <= n; i++) {
    if (Z[i] != Z[i - 1] + 1) break;
  }
  p = i - 1;
  if (Z[p] == n) {
    cond = 1;
    for (j = 1; j <= n && B[j] != 1; j++) {
      if (S[i] == 1) {
        S[B[j]] = 1;
        i++;
      } else {
        cond = 0;
        break;
      }
    }
    if (cond == 1) {
      k = Z[1] - 1;
      ans = min(ans, k);
    }
  }
  cout << ans << '\n';
}
