#include <bits/stdc++.h>
using namespace std;
int n, a[105], maxn, ans;
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    maxn = max(maxn, a[i]);
  }
  for (int i = 1; i <= n; i++) {
    ans += (maxn - a[i]);
  }
  cout << ans;
  return 0;
}
