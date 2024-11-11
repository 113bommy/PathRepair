#include <bits/stdc++.h>
using namespace std;
long long n, x, ans1 = -1, ans = 1e17, ch, mx, mn;
long long a[6], b[100000], act[100000];
vector<pair<long long, long long>> c;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (long long i = 0; i < 6; i++) {
    cin >> a[i];
  }
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
    for (long long j = 0; j < 6; j++) {
      c.push_back({b[i] - a[j], i});
    }
  }
  sort(c.begin(), c.end());
  long long r = -1;
  long long tr = 0;
  long long l = -1;
  for (long long i = 0; i < c.size(); i++) {
    while (tr < n && r < c.size() - 1) {
      r++;
      if (act[c[r].second] == 0) {
        tr++;
      }
      act[c[r].second]++;
    }
    while (act[c[l + 1].second] > 1) {
      l++;
      act[c[l].second]--;
      i++;
    }
    if (tr == n) {
      ans = min(ans, c[r].first - c[l + 1].first);
    }
    l++;
    act[c[l].second]--;
    if (act[c[l].second] == 0) tr--;
  }
  if (n == 1) ans = 0;
  cout << ans;
}
