#include <bits/stdc++.h>
using namespace std;
int n, m;
long long L[200001], R[200001];
pair<pair<long long, long long>, int> cau[200001];
pair<long long, int> a[200001];
set<pair<pair<long long, long long>, int> > s;
int ans[200001];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> L[i] >> R[i];
  for (int i = 1; i < n; i++)
    cau[i] = make_pair(make_pair(L[i + 1] - R[i], R[i + 1] - L[i]), i);
  sort(cau + 1, cau + n);
  for (int i = 1; i <= m; i++) {
    long long u;
    cin >> u;
    a[i] = make_pair(u, i);
  }
  sort(a + 1, a + m + 1);
  int u = 1;
  int sol = 0;
  for (int i = 1; i <= m; i++) {
    while (u < n && cau[u].first.first <= a[i].first) {
      s.insert(make_pair(make_pair(cau[u].first.second, cau[u].first.first),
                         cau[u].second));
      u++;
    }
    while (!s.empty() && (*s.begin()).first.first < a[i].first)
      s.erase(*s.begin());
    if (!s.empty()) {
      pair<pair<long long, long long>, int> t = *s.begin();
      s.erase(t);
      ans[t.second] = a[i].second;
      sol++;
    }
  }
  if (sol < n - 1)
    cout << "No";
  else {
    cout << "Yes\n";
    for (int i = 1; i <= n - 1; i++) cout << ans[i] << " ";
  }
}
