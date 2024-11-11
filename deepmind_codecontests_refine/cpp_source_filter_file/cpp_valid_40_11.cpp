#include <bits/stdc++.h>
using namespace std;
void want() {
  long long n;
  cin >> n;
  long long i, j;
  long long A[2][n];
  long long sum1 = 0;
  long long sum2 = 0;
  for (j = 0; j < 2; j++) {
    for (i = 0; i < n; i++) {
      cin >> A[j][i];
    }
  }
  long long pre = 0, suf = 0;
  for (i = 0; i < n - 1; i++) {
    pre += A[1][i];
  }
  long long ans = pre;
  for (i = n - 1; i > 0; i--) {
    pre -= A[1][i];
    suf += A[0][i];
    ans = min(ans, max(pre, suf));
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    want();
  }
}
