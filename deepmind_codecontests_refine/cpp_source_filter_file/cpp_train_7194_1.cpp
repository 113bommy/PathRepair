#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int A[n + 1];
  for (int i = 1; i <= n; i++) cin >> A[i];
  long long ans = 0;
  if (n == 2) {
    if (A[2] == 2)
      cout << 1;
    else if (A[1] == 999)
      cout << 1;
    else
      cout << 0;
    return;
  }
  long long c = 0;
  for (int i = 2; i < n; i++) {
    if (A[i] == A[i - 1] + 1 && A[i] == A[i + 1] - 1) {
      c++;
      ans = max(ans, c);
    } else
      c = 0;
  }
  if (n > 1) {
    if (A[2] == 2) {
      long long c = 2;
      for (int i = 3; i < n; i++)
        if (A[i] == A[i - 1] + 1 && A[i] == A[i + 1] - 1)
          c++;
        else
          break;
      ans = max(ans, c);
    }
    if (A[n - 1] == 999) {
      long long c = 2;
      for (int i = n - 2; i > 1; i--) {
        if (A[i] == A[i - 1] + 1 && A[i] == A[i + 1] - 1)
          c++;
        else
          break;
      }
      ans = max(ans, c);
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
