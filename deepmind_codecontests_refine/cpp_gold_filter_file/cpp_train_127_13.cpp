#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  long long a[n], b[m];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (a[i] == b[j]) {
        cout << "YES" << endl << 1 << " " << a[i] << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
  return;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
