#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> b(n), a(n);
  long long int sa, sb = 0, t_n = (long long int)n * (n + 1) / 2, x;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    sb += b[i];
  }
  if (sb % t_n != 0) {
    cout << "NO\n";
    return;
  }
  sa = sb / t_n;
  for (int i = n - 1; i >= 0; i--) {
    x = b[i] - b[(i + 1) % n] + sa;
    if (x % n != 0 || x <= 0) {
      cout << "NO\n";
      return;
    }
    a[(i + 1) % n] = x / n;
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
