#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
  vector<long long> b(n);
  for (int i = 0; i < n; i++) cin >> b[i];
  vector<vector<long long> > use(k);
  for (int i = 0; i < n; i++) {
    use[a[i]].emplace_back(b[i]);
  }
  long long ans = 0;
  set<long long> bad;
  int need = 0;
  for (int i = 0; i < k; i++) {
    if ((int)(use[i]).size() == 0) need++;
    sort((use[i]).begin(), (use[i]).end());
    reverse((use[i]).begin(), (use[i]).end());
    while ((int)(use[i]).size() > 1) {
      bad.insert(use[i].back());
      use[i].pop_back();
    }
  }
  while (need--) {
    ans += *bad.begin();
    bad.erase(bad.begin());
  }
  cout << ans << '\n';
  return 0;
}
