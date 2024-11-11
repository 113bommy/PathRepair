#include <bits/stdc++.h>
using namespace std;
int n, m, ans[100005], k[100005];
vector<pair<pair<int, int>, int> > a, b;
bool ok = true;
void solve() {
  sort((b).begin(), (b).end());
  sort((a).begin(), (a).end());
  set<pair<int, int> > q;
  set<pair<int, int> >::iterator it;
  int p = 0;
  for (int i = 0; i < m; i++) {
    int x, y, idx;
    x = b[i].first.first;
    y = b[i].first.second;
    idx = b[i].second;
    while (p < n && a[p].first.first <= x) {
      q.insert(make_pair(a[p].first.second, a[p].second));
      p++;
    }
    it = q.upper_bound(make_pair(y - 1, 100005));
    if (it == q.end()) {
      ok = false;
      return;
    } else {
      ans[idx] = it->second;
      k[it->second]--;
      if (k[it->second] == 0) q.erase(it);
    }
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    b.push_back(make_pair(make_pair(x, y), i));
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y >> k[i];
    a.push_back(make_pair(make_pair(x, y), i));
  }
  solve();
  if (ok) {
    cout << "YES\n";
    for (int i = 0; i < m; i++) cout << ans[i] + 1 << " ";
    cout << endl;
  } else
    cout << "NO\n";
}
