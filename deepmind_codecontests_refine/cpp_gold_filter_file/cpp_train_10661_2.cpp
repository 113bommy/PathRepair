#include <bits/stdc++.h>
using namespace std;
long long a[100005];
void solve() {
  long long n, k;
  cin >> n >> k;
  if (n == k) {
    cout << -1 << endl;
    return;
  };
  if (k == 0) {
    cout << n << " ";
    for (__typeof((n)) i = (1); i < (n); i++) cout << i << " ";
    return;
  }
  if (k == n - 1) {
    for (__typeof((n + 1)) i = (1); i < (n + 1); i++) cout << i << " ";
    return;
  }
  k = n - k;
  if (k % 2) cout << k << " ";
  for (__typeof((k / 2)) i = (0); i < (k / 2); i++)
    cout << 2 * i + 2 - k % 2 << " " << 2 * i + 1 + k % 2 << " ";
  for (__typeof((n + 1)) i = (k + 1); i < (n + 1); i++) cout << i << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
