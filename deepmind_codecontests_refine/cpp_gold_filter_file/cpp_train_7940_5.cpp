#include <bits/stdc++.h>
using namespace std;
int v[500010];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> v[i];
  v[0] = -1e9;
  v[n + 1] = INT_MAX;
  vector<int> b;
  b.push_back(0);
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    b.push_back(x);
  }
  b.push_back(n + 1);
  for (int i = 0; i <= n + 1; ++i) v[i] = v[i] - i;
  int ans = 0;
  for (int i = 0; i < (int)b.size() - 1; ++i) {
    int l = b[i], r = b[i + 1];
    if (v[l] > v[r]) return cout << "-1\n", 0;
    vector<int> lis;
    for (int j = l + 1; j < r; ++j) {
      if (v[l] <= v[j] and v[j] <= v[r]) {
        int pos = upper_bound(lis.begin(), lis.end(), v[j]) - lis.begin();
        if (pos >= (int)lis.size())
          lis.push_back(v[j]);
        else
          lis[pos] = v[j];
      }
    }
    ans += (r - l - 1) - lis.size();
  }
  cout << ans << "\n";
  return 0;
}
