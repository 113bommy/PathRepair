#include <bits/stdc++.h>
using namespace std;
long long n, m, c, x, y, X, Y, ans[200001];
pair<pair<long long, long long>, int> a[200001];
multiset<pair<long long, int> > b;
int main() {
  cin >> n >> m;
  cin >> X >> Y;
  for (int i = 1; i < n; i++)
    cin >> x >> y, a[i] = {{y - X, x - Y}, i}, X = x, Y = y;
  for (int i = 1; i <= m; i++) cin >> x, b.insert(make_pair(x, i));
  sort(a + 1, a + n);
  for (int i = 1; i < n; i++) {
    multiset<pair<long long, int> >::iterator it =
        b.lower_bound(make_pair(a[i].first.second, 0));
    if (it == b.end() || it->first > a[i].first.first) {
      cout << "NO" << endl;
      return 0;
    }
    ans[a[i].second] = it->second;
    b.erase(it);
  }
  cout << "YES" << endl;
  for (int i = 1; i < n; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
