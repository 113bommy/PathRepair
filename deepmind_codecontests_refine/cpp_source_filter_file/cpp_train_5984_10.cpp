#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  int cnt[300] = {};
  string s;
  cin >> s;
  int n = s.size();
  int ans = n;
  for (char c : s) ans += 2 * cnt[c]++;
  cout << ans << '\n';
}
