#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9 + 7;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s, t;
  int n, i, k;
  cin >> n >> k;
  cin >> s >> t;
  for (i = 0; i < n; i++)
    if (s[i] != t[i]) break;
  if (i == n) {
    cout << n << '\n';
    return 0;
  }
  int leaves = 0, taken = 0;
  long long int ans = i;
  for (; i < n; i++) {
    if (s[i] == 'a') leaves++;
    if (t[i] == 'b') leaves++;
    ans += (n - i) * 1LL * min(k - taken, leaves - taken);
    taken += min(k - taken, leaves - taken);
    if (taken == k) break;
    leaves = (leaves - 2) * 2 + 2;
  }
  cout << ans << '\n';
  return 0;
}
