#include <bits/stdc++.h>
using namespace std;
const int N = 200 * 1000 + 10, inf = 1000 * 1000 * 1000 + 100;
pair<int, int> p[N];
long long ans = 0;
map<int, int> mapi, sapi;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
    ans += (1LL * mapi[p[i].first]++);
    ans += (1LL * sapi[p[i].second]++);
  }
  sort(p, p + n);
  p[n] = make_pair(inf, inf);
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    if ((p[i].first == p[i + 1].first) && (p[i].second == p[i + 1].second))
      cnt++;
    if ((p[i].first != p[i + 1].first) || (p[i].second != p[i + 1].second)) {
      ans -= (1ll * (cnt * (cnt - 1)) / 2);
      cnt = 1;
    }
  }
  cout << ans << endl;
  return 0;
}
