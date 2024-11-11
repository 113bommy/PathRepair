#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> v(n), t(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  for (int i = 0; i < n; ++i) cin >> t[i];
  vector<long long> pst(n + 1);
  for (int i = 1; i <= n; ++i) pst[i] = pst[i - 1] + t[i - 1];
  vector<long long> full(n + 1), melt(n);
  for (int i = 0; i < n; ++i) {
    int j = upper_bound(pst.begin(), pst.end(), v[i] + pst[i]) - pst.begin();
    --j;
    ++full[i];
    --full[j];
    if (j < n) melt[j] += v[i] + pst[i] - pst[j];
  }
  for (int i = 1; i <= n; ++i) full[i] += full[i - 1];
  for (int i = 0; i < n; ++i) {
    long long ans = t[i] * full[i] + melt[i];
    cout << ans << " ";
  }
  cout << endl;
}
