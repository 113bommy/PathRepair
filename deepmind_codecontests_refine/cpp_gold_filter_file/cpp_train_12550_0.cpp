#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, c;
  cin >> n >> c;
  long long t[n];
  long long i;
  for (i = 0; i < n; ++i) {
    cin >> t[i];
  }
  long long ans = 1;
  long long prev = t[0];
  for (i = 1; i < n; i++) {
    if (abs(t[i] - prev) > c) {
      ans = 1;
    } else {
      ans++;
    }
    prev = t[i];
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
