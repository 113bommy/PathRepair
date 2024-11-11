#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, a[100005] = {0}, l[10005] = {0}, r[100005] = {0};
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) l[i] = min(l[i - 1] + 1, a[i]);
  for (int i = 1; i <= n; i++) r[i] = min(r[i + 1] + 1, a[i]);
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, min(l[i], r[i]));
  cout << ans;
  return 0;
}
