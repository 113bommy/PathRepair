#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int k;
  cin >> k;
  map<int, int> sum;
  map<int, int> vall;
  for (int i = 1; i <= k; ++i) {
    int n;
    cin >> n;
    int a[n + 10];
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      cnt += a[i];
    }
    for (int j = 1; j <= n; ++j) {
      if (sum[cnt - a[j]] != 0) {
        cout << "YES\n";
        cout << sum[cnt - a[j]] << ' ' << vall[cnt - a[j]] << '\n';
        cout << i << ' ' << a[j] << '\n';
        return 0;
      }
    }
    for (int j = 1; j <= n; ++j) {
      sum[cnt - a[j]] = i;
      vall[cnt - a[j]] = j;
    }
  }
  cout << "NO\n";
  return 0;
}
