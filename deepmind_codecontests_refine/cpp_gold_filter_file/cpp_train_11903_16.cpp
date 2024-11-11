#include <bits/stdc++.h>
using namespace std;
unsigned long long int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int k, l, n;
  cin >> k;
  string second;
  cin >> second;
  l = second.length();
  vector<int> v, back(2e6, 0), fwd(2e6, 0);
  v.push_back(0);
  for (int i = 0; i < l; i++)
    if (second[i] == '1') v.push_back(i + 1);
  v.push_back(l + 1);
  n = (int)v.size();
  for (int i = 1; i < n - 1; i++) {
    back[i] = v[i] - v[i - 1], fwd[i] = v[i + 1] - v[i];
  }
  back[n - 1] = v[n - 1] - v[n - 2];
  unsigned long long int ans = 0;
  if (n - 2 < k)
    cout << "0";
  else if (k) {
    for (int i = k; i < n; i++) ans += 1LL * back[i - k + 1] * fwd[i];
    cout << ans << "\n";
  } else {
    for (int i = 1; i < n; i++) ans += 1LL * (back[i] - 1) * (back[i]) / 2;
    cout << ans << "\n";
  }
  return 0;
}
