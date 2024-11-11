#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  n = 2 * n;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i + 1;
  sort(a.begin(), a.end());
  long long ans = a[0].second - 1;
  for (int i = 2; i < n; i += 2) {
    ans += abs(a[i].second - a[i - 2].second);
  }
  ans += a[1].second - 1;
  for (int i = 3; i < n; i += 2) {
    ans += abs(a[i].second - a[i - 2].second);
  }
  cout << ans;
}
