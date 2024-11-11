#include <bits/stdc++.h>
#pragma GCC optimize("O1")
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
void solve() {
  long long n;
  cin >> n;
  long long a[n + 10];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n, greater<long long>());
  for (long long i = 0; i < n - 2; i++) {
    if (a[i + 1] + a[i + 2] > a[i]) {
      if (a[i] + a[i + 1] > a[i + 2]) {
        if (a[i] + a[i + 2] > a[i + 1]) {
          cout << "YES";
          return;
        }
      }
    }
  }
  cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
