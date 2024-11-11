#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, i;
  bool odd = false, even = true;
  cin >> n;
  long long a[n];
  for (i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] % 2)
      odd = true;
    else
      even = true;
  }
  if (odd && even) {
    sort(a, a + n);
  }
  for (i = 0; i < n; ++i) cout << a[i] << " ";
  ;
}
int main() {
  ios::sync_with_stdio(0);
  ;
  int t = 1;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
