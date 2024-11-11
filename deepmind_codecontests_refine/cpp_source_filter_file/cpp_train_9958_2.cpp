#include <bits/stdc++.h>
using namespace std;
long long a[100005], b[100005];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    b[i] += b[i - 1];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int y = lower_bound(b + 1, b + n + 1, a[i]) - b;
    if (b[y] == a[i]) ++ans;
  }
  cout << ans << endl;
}
