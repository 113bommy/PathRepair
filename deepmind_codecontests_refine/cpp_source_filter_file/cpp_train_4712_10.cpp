#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    int ans = 0, lst = -1;
    for (int i = 1; i <= n; i++)
      if (a[i] * (i - lst) >= m) {
        ans++;
        lst = i;
      }
    cout << ans - 1 << endl;
  }
}
