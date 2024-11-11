#include <bits/stdc++.h>
using namespace std;
bool compareDESC(int a, int b) { return a > b; }
void solve() {
  int n, k, sum = 0;
  cin >> n >> k;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(a, a + n);
  sort(b, b + n, compareDESC);
  for (int i = 1; i <= n; i++) {
    if (k-- > 0) {
      sum += max(a[i - 1], b[i - 1]);
    } else {
      sum += a[i - 1];
    }
  }
  cout << sum << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
