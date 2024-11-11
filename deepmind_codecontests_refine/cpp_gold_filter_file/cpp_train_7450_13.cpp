#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, i, j, k, ans;
  cin >> n >> k;
  vector<long long> s(n + 1);
  s[1] = 1;
  for (i = 1; i <= n; i++) s[i] = s[i - 1] * 2 + 1;
  k--;
  for (i = n; i >= 1; i--) {
    if (k == s[i] / 2) {
      ans = i;
      break;
    }
    if (k > s[i] / 2) k = k - s[i] / 2 - 1;
  }
  cout << ans << "\n";
  return 0;
}
