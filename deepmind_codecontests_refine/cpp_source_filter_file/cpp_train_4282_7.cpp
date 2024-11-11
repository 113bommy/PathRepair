#include <bits/stdc++.h>
using namespace std;
int n, a[1001], mn = INT_MAX;
long long s, cnt = 0;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mn = min(mn, a[i]);
  }
  for (int i = 2; i <= n; i++) {
    cnt += a[i] - mn;
  }
  cout << (cnt >= s ? mn
                    : (mn >= (s - cnt) / n + ((s - cnt) % n == 0 ? 0 : 1)
                           ? mn - (s - cnt) / n - ((s - cnt) % n == 0 ? 0 : 1)
                           : -1));
}
