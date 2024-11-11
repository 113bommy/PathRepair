#include <bits/stdc++.h>
using namespace std;
void solve() {
  int64_t n;
  cin >> n;
  int64_t A[n];
  for (int64_t i = 0; i < n; i++) cin >> A[i];
  sort(A, A + n);
  if (n == 1)
    cout << A[0];
  else {
    int64_t x = A[1] - A[0];
    cout << A[x];
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int64_t test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
