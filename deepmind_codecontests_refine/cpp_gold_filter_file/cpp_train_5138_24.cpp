#include <bits/stdc++.h>
using namespace std;
int main() {
  long n;
  cin >> n;
  long long int ans = 0, ans1, k, a1, a2, x, y, m, s = 0;
  vector<pair<long, pair<long, long>>> r;
  for (int i = 0; i < n; ++i) {
    cin >> k;
    s += k;
    cin >> a1 >> x >> y >> m;
    ans1 = 0;
    r.push_back(make_pair(0, make_pair(a1, i + 1)));
    for (int j = 1; j < k; ++j) {
      a2 = ((a1 * x) % m + y % m) % m;
      if (a2 < a1) ans1++;
      a1 = a2;
      if (r.size() <= 200000)
        r.push_back(make_pair(ans1, (make_pair(a2, i + 1))));
    }
    ans = max(ans, ans1);
  }
  cout << ans << '\n';
  sort(r.begin(), r.end());
  if (s <= 200000)
    for (int i = 0; i < s; ++i)
      cout << r[i].second.first << " " << r[i].second.second << '\n';
  return 0;
}
