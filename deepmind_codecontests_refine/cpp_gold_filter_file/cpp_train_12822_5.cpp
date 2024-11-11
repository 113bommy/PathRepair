#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long a[m + 1];
  for (long long i = 1; i < m + 1; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  long long cur = 0;
  long long now = 0;
  a[0] = 0;
  for (long long i = 1; i < m + 1; i++) {
    cur += a[i] - a[i - 1];
    if (cur > k) {
      cur = cur % k;
      if (cur == 0) {
        cur = k;
      }
    }
    now++;
    if (i == m || cur + a[i + 1] - a[i] > k) {
      cur -= now;
      ans++;
      now = 0;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
