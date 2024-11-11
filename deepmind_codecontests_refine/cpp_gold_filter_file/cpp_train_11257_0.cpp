#include <bits/stdc++.h>
using namespace std;
int64_t n, k, ans;
string s;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> s;
  for (int64_t c = 0; c < 26; c++) {
    char ch = 'a' + c;
    int64_t curr = 0;
    for (int64_t i = 0; i <= n - k; i++) {
      if (s[i] != ch) continue;
      int64_t cnt = 0;
      while (i < n && s[i] == ch && cnt != k) i++, cnt++;
      i--;
      if (cnt == k) curr++;
    }
    ans = max(ans, curr);
  }
  cout << ans;
  return 0;
}
