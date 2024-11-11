#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, sum;
int a[N];
int st[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
  for (int i = n; i; i--) st[i] = st[i + 1] + a[i];
  for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
  for (int i = n; i; i--) st[i] = min(st[i + 1], st[i]);
  int ans = sum;
  for (int i = 0; i <= n; i++) ans = max(ans, sum - 2 * (a[i] + st[i + 1]));
  cout << ans << endl;
  return 0;
}
