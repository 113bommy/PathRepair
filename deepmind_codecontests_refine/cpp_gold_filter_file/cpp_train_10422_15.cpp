#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O2")
const int LIM = 2e6 + 5, MOD = 1e9 + 7;
const long long INF = 1e16;
const int l = ceil(log2(LIM));
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n + 1, -1), b(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    a[i] = x;
    b[i] = y;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = ans + max(a[i], b[i]);
  }
  ans = ans + n;
  cout << ans << endl;
  return 0;
}
