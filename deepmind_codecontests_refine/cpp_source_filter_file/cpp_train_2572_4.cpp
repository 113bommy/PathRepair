#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int mp[MAXN];
pair<int, int> pr[MAXN];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> mp[i];
    pr[i] = {mp[i] % m, i};
  }
  sort(pr, pr + n);
  int l = 0, r = n - 1;
  long ans = 0;
  int mo = 0, cnt = 0;
  while (l <= r) {
    int ll = (mo - pr[l].first + m) % m;
    int rr = (mo - pr[r].first + m) % m;
    if (ll < rr) {
      mp[pr[l].second] += ll;
      ans += ll;
      l++;
    } else {
      mp[pr[r].second] += rr;
      ans += rr;
      r--;
    }
    cnt++;
    if (cnt == n / m) {
      mo++;
      cnt = 0;
    }
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) cout << mp[i] << " ";
  return 0;
}
