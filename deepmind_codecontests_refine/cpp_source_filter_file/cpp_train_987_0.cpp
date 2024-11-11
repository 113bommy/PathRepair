#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll inf = 1;
const ll mod = 1E9;
int main() {
  ios::sync_with_stdio(false);
  int n;
  ll d;
  cin >> n >> d;
  vector<pll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  ll sum = 0, ans = 0;
  for (int i = 0, j = 0; i < n; i++) {
    if (i) sum -= a[i - 1].second;
    while (j < n && a[j].first - a[i].first <= d) {
      sum += a[j].second;
      j++;
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
