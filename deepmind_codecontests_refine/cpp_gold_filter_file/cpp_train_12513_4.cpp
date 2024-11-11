#include <bits/stdc++.h>
using namespace std;
long long t, n, m, a[500012], b[500012];
long long res[500012];
long long s[500012], ss[500012];
void kaisa() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n, greater<long long>());
  for (int i = n; i >= 1; i--) {
    s[i] = s[i + 1] + a[i];
  }
  for (int i = n; i >= 1; i--) {
    ss[i] = a[i] + ss[i + m];
  }
  for (int i = 1; i <= m; i++) {
    long long st = n + 1 - i;
    res[i] = (s[st] - s[n + 1]);
  }
  for (int i = m + 1; i <= n; i++) {
    long long st = n + 1 - i;
    res[i] = res[i - 1] + ss[st];
  }
  for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }
}
int main() {
  kaisa();
  return 0;
}
