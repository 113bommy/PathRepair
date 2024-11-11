#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
long long n;
long long t[N];
long long ans[N];
void solve() {
  long long cnt = 0;
  for (long long i = 1; i <= n; i++) {
    if (t[i] == t[1]) cnt++;
  }
  if (cnt == n) {
    cout << 1 << "\n";
    for (long long i = 1; i <= n; i++) cout << 1 << " ";
    cout << "\n";
    return;
  }
  if (n % 2 == 0) {
    cout << 2 << "\n";
    for (long long i = 1; i <= n; i++) {
      cout << i % 2 + 1 << " ";
    }
    cout << endl;
    return;
  }
  for (long long i = 1; i <= n; i++) {
    long long id = i + 1;
    if (id > n) id = id % n;
    if (t[i] == t[id]) {
      for (long long j = i + 1; j <= n; j++) {
        if (j % 2 == (i + 1) % 2)
          ans[j] = 1;
        else
          ans[j] = 2;
      }
      for (long long j = i; j >= 1; j--) {
        if (j % 2 == i % 2)
          ans[j] = 1;
        else
          ans[j] = 2;
      }
      cout << 2 << "\n";
      for (long long i = 1; i <= n; i++) cout << ans[i] << " ";
      cout << "\n";
      return;
    }
  }
  cout << 3 << "\n";
  for (long long i = 1; i < n; i++) cout << i % 2 + 1 << " ";
  cout << 3 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tests;
  cin >> tests;
  while (tests--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      cin >> t[i];
    }
    solve();
  }
}
