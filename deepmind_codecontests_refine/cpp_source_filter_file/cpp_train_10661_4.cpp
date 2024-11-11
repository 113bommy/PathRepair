#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  if (k >= n) {
    cout << -1;
    return;
  }
  long long a[100005];
  for (long long i = 1; i < k + 2; i++) {
    a[i] = i;
  }
  for (long long i = k + 2; i < n + 1; i++) {
    long long cur = i, next = i + 1;
    if (next <= n) {
      a[i] = next;
      a[i + 1] = cur;
    } else {
      a[i] = cur;
      swap(a[i], a[1]);
    }
  }
  for (long long i = 1; i < n + 1; i++) cout << a[i] << " ";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
