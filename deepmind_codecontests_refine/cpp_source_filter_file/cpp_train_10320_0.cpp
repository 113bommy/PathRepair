#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n + 1], b[n + 1];
  for (int i = 1; i < n + 1; ++i) cin >> a[i] >> b[i];
  int64_t sum = (n * (n + 1)) / 2 - 1, last = 1;
  cout << "1 ";
  for (int i = 1; i < n - 1; ++i) {
    last = (a[a[last]] == b[last] or b[a[last]] == b[last] ? a[last] : b[last]);
    cout << last << ' ';
    sum -= last;
  }
  cout << sum;
}
