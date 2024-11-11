#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  ;
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto& it : a) cin >> it;
  for (auto& it : b) cin >> it;
  vector<long long> ans;
  for (int i = 0; i < n; i++) {
    long long mx = LLONG_MIN;
    for (int j = 0; j < m; j++) {
      long long pr = (a[i] * b[j]);
      mx = max(mx, pr);
    }
    ans.push_back(mx);
  }
  sort(ans.rbegin(), ans.rend());
  cout << ans[1];
}
