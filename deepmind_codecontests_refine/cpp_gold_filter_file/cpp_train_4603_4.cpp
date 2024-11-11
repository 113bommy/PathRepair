#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1e6 + 7;
int a[Nmax];
map<pair<long long, long long>, long long> mp;
int n;
int num[Nmax];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
  int q;
  cin >> q;
  long long ans = 0;
  while (q--) {
    int x, z;
    long long y;
    cin >> x >> y >> z;
    if (mp[pair<long long, long long>(x, y)]) {
      int now = mp[pair<long long, long long>(x, y)];
      mp[pair<long long, long long>(x, y)] = z;
      num[now]--;
      if (num[now] < a[now]) ans--;
      if (z) {
        num[z]++;
        if (num[z] <= a[z]) ans++;
      }
    } else {
      mp[pair<long long, long long>(x, y)] = z;
      ans -= min(a[z], num[z]);
      num[z]++;
      ans += min(a[z], num[z]);
    }
    cout << sum - ans << "\n";
  }
  return 0;
}
