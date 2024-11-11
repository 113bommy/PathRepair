#include <bits/stdc++.h>
using namespace std;
map<char, int> mp;
void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> sum(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 1) {
      sum[i] = sum[i - 1] + mp[s[i - 1]];
    } else {
      sum[i] = sum[i - 1] - mp[s[i - 1]];
    }
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    if (sum[r] - sum[l - 1] == 0)
      cout << 0 << "\n";
    else if (abs(sum[r] - sum[l - 1]) % 2 == 1)
      cout << 1 << "\n";
    else
      cout << 2 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  mp['+'] = 1;
  mp['-'] = -1;
  int tc;
  cin >> tc;
  while (tc-- > 0) solve();
  return 0;
}
