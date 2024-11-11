#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    long long int k = n / m;
    long long int a[n];
    vector<vector<long long int>> val(m);
    vector<pair<long long int, long long int>> f;
    long long int ans = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      val[a[i] % m].push_back(i);
    }
    for (long long int i = 0; i < m; i++) {
      long long int cur = i % m;
      while (val[cur].size() > k) {
        long long int elem = val[cur].back();
        val[cur].pop_back();
        f.push_back(make_pair(elem, i));
      }
      while (val[cur].size() < k && !f.empty()) {
        long long int elem = f.back().first;
        long long int idx = f.back().second;
        val[cur].push_back(elem);
        f.pop_back();
        a[elem] += i - idx;
        ans += i - idx;
      }
    }
    cout << ans << endl;
    for (long long int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
