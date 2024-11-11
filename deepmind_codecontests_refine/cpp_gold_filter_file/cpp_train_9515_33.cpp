#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MAX = 1e5 + 10;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i < n + 1; i++) cin >> a[i];
    int o[n + 1], z[n + 1];
    o[0] = z[0] = 0;
    for (int i = 1; i < n + 1; i++) {
      o[i] = o[i - 1] + (a[i] == 1);
      z[i] = z[i - 1] + (a[i] == 0);
    }
    int ans = 0;
    for (int i = 1; i < n + 1; i++)
      for (int j = i; j < n + 1; j++)
        ans = max(ans, o[n] - (o[j] - o[i - 1]) + z[j] - z[i - 1]);
    cout << ans;
  }
}
