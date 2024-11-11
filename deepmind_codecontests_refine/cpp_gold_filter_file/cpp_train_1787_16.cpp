#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-5;
const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3f;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  long long ans = 0;
  int n = s.length();
  s = ' ' + s;
  int l = n - 2;
  int r = n + 1;
  if (n < 3) {
    cout << 0;
    return 0;
  }
  while (l) {
    for (int i = 1; l + i + i <= min(n, r); i++) {
      if (s[l] == s[l + i] && s[l] == s[l + i + i]) {
        r = l + i + i;
        break;
      }
    }
    ans += max(0, n - r + 1);
    l--;
  }
  cout << ans;
  return 0;
}
