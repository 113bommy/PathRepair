#include <bits/stdc++.h>
using namespace std;
long long k1, k2, k3, f, arr[10][300000], pr[10][300000], suf[300000], ans,
    fBest = 1e18, n;
int main() {
  cin >> k1 >> k2 >> k3;
  n = k1 + k2 + k3;
  for (int i = 1; i <= k1; i++) {
    cin >> f;
    arr[1][f] = 1;
  }
  for (int i = 1; i <= k2; i++) {
    cin >> f;
    arr[2][f] = 1;
  }
  for (int i = 1; i <= k3; i++) {
    cin >> f;
    arr[3][f] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int i1 = 1; i1 <= 3; i1++) {
      pr[i1][i] += pr[i1][i - 1];
      pr[i1][i] += arr[i1][i];
    }
  }
  suf[n] = pr[3][n] - pr[2][n];
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = min(suf[i + 1], pr[3][i] - pr[2][i]);
  }
  for (int fPos = 0; fPos <= n; fPos++) {
    ans = pr[1][n] + pr[2][n];
    if (fPos != 0) {
      ans = ans + pr[2][fPos - 1] - pr[1][fPos - 1];
    }
    ans = ans + suf[max(fPos - 1, 0)];
    fBest = min(fBest, ans);
  }
  cout << fBest;
}
