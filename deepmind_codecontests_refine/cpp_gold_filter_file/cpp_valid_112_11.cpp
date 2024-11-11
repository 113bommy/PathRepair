#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x[3], m;
  for (long long i = 0; i < 3; i++) cin >> x[i];
  cin >> m;
  sort(x, x + 3);
  long long maxm = x[0] + x[1] + x[2] - 3;
  long long minm = max((long long)0, x[2] - x[1] - x[0] - 1);
  if (m <= maxm && m >= minm) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
