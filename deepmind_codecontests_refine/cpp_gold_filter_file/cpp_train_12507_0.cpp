#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int A[n], B[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i] >> B[i];
  }
  int k;
  cin >> k;
  for (int i = 0; i < n; i++) {
    if (k >= A[i] && k <= B[i]) {
      cout << n - i;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cout << fixed << setprecision(11);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
