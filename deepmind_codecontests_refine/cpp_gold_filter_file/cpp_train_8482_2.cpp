#include <bits/stdc++.h>
using namespace std;
long long ans[200010], L[200010], R[200010];
vector<pair<pair<long long, long long>, long long> > v;
set<pair<long long, long long> > S;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> L[i] >> R[i];
  for (int i = 0; i < m; i++) {
    long long l;
    cin >> l;
    S.insert(make_pair(l, i));
  }
  for (int i = 1; i < n; i++)
    v.push_back(make_pair(make_pair(L[i] - R[i - 1], R[i] - L[i - 1]), i - 1));
  sort(v.begin(), v.end());
  for (int i = n - 2; i >= 0; i--) {
    set<pair<long long, long long> >::iterator it;
    long long idx, l, r;
    idx = v[i].second;
    l = v[i].first.first;
    r = v[i].first.second;
    it = S.upper_bound(make_pair(r, m));
    if (it == S.begin() || (--it)->first < l) {
      cout << "No\n";
      return 0;
    }
    ans[idx] = it->second;
    S.erase(it);
  }
  cout << "Yes\n";
  for (int i = 0; i < n - 1; i++) cout << ans[i] + 1 << " ";
  cout << "\n";
  return 0;
}
