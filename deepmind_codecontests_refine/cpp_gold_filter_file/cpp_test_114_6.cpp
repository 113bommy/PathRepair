#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10, INF = 1e18 + 10;
long long a[N], n, h;
void solve() {
  cin >> n;
  long long pos = 0, mn = INF;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (mn > a[i]) {
      mn = min(mn, a[i]);
      pos = i;
    }
  }
  int cnt = 0, j = 1;
  while (cnt < (n / 2)) {
    if (j != pos) {
      cout << a[j] << " " << a[pos] << endl;
      cnt++;
    }
    j++;
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
