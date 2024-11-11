#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long ar1[n], ar2[m];
  for (long long int i = 0; i < n; i++) cin >> ar1[i];
  for (long long int i = 0; i < m; i++) cin >> ar2[i];
  if (m == 1) {
    cout << n << '\n';
    return 0;
  }
  vector<long long> v;
  for (long long int i = 1; i < m; i++) v.push_back(ar2[i] - ar2[i - 1]);
  v.push_back(1000000007);
  for (long long int i = 1; i < n; i++) v.push_back(ar1[i] - ar1[i - 1]);
  long long pre[v.size()];
  pre[0] = 0;
  long long ans = 0;
  for (long long int i = 1; i < v.size(); i++) {
    long long tmp = pre[i - 1];
    if (tmp > 0 && v[tmp] != v[i]) tmp = pre[tmp - 1];
    if (v[tmp] == v[i]) tmp++;
    pre[i] = tmp;
    if (pre[i] == m - 1) ans++;
  }
  cout << ans << '\n';
  return 0;
}
