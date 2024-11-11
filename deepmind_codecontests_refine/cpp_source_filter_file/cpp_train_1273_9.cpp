#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n], b[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) cin >> b[i];
  long long c[n];
  for (long long i = 0; i < n; i++) c[i] = a[i] - b[i];
  sort(c, c + n);
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    auto ub = upper_bound(c + i + 1, c + i + n, -c[i]);
    cnt += (c + n - ub);
  }
  cout << cnt << "\n";
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  };
  solve();
  return 0;
}
