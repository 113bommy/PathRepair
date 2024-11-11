#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n, k;
long long a[MAXN];
long long tar;
map<long long, pair<int, int> > mp;
int id = 0;
long long ans = 0;
void solve() {
  ++id;
  for (int i = 0; i <= n; i++) {
    if (mp[a[i] - tar].second == id) ans += mp[a[i] - tar].first;
    if (mp[a[i]].second != id) {
      mp[a[i]] = pair<int, int>(1, id);
    } else
      mp[a[i]].first++;
  }
}
int main() {
  cin >> n >> k;
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> tar;
    a[i] = a[i - 1] + tar;
  }
  if (abs(k) != 1)
    for (tar = 1; abs(tar) <= 1e14; tar *= k) solve();
  else {
    tar = 1;
    solve();
    if (k == -1) {
      tar = -1;
      solve();
    }
  }
  cout << ans << endl;
  return 0;
}
