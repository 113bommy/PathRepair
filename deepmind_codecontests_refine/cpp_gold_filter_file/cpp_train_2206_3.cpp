#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
long long mod = 1000000007;
const int MX = 0x3f3f3f3f;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n, i, ans = MX, temp, j;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (i = 0; i <= n - 1; i++) {
      temp = i;
      for (j = 0; j <= n - 1; j++)
        if (t[temp] == s[j]) temp++;
      ans = min(ans, n - temp + i);
    }
    sort((s).begin(), (s).end());
    sort((t).begin(), (t).end());
    if (s != t)
      cout << -1 << "\n";
    else
      cout << ans << "\n";
  }
  return 0;
}
