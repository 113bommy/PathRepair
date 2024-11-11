#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n, a[1005], b[1005];
long long ans = 1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) {
    long long cur1 = 1, cur2 = 1;
    for (int j = i; j <= n; j++) {
      cur1 |= a[j];
      cur2 |= b[j];
      ans = max(ans, cur1 + cur2);
    }
  }
  cout << ans << endl;
  return 0;
}
