#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
int a[1000006];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  int l = 1, r = 1;
  while (r <= n) {
    while (a[l] == a[r] && r < n) r++;
    if (a[r] > a[l]) ans++;
    l++, r++;
  }
  cout << ans;
  return 0;
}
