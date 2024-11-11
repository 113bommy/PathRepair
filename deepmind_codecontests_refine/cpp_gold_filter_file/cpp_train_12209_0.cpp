#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  long long t;
  cin >> n >> t;
  long long a[n];
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (t % 2 == 1) {
      cout << a[i] % 2 << " ";
    } else {
      if (a[i] == t / 2) {
        cout << cnt;
        ++cnt;
        cnt %= 2;
      } else if (a[i] <= t / 2) {
        cout << 1;
      } else
        cout << 0;
      cout << " ";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
    cout << "\n";
  }
  return 0;
}
