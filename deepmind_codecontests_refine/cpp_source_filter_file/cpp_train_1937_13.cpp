#include <bits/stdc++.h>
using namespace std;
long long a[100005], i, n, t, ans;
map<int, int> mp;
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(a + 1, a + n + 1);
  for (i = 1; i <= 3; i++) {
    if (a[i] == a[3]) t++;
  }
  if (t == 3) ans = (mp[a[3]] - 2) * (mp[a[3]] - 1) * mp[a[3]] / 6;
  if (t == 2) ans = (mp[a[3]] - 1) * mp[a[3]] / 2;
  if (t == 1) ans = mp[a[3]];
  cout << ans;
}
