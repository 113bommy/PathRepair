#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool isvowel(char c) {
  c = tolower(c);
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
map<string, int> mp;
int main() {
  ios_base::sync_with_stdio(0), ios::sync_with_stdio(0), cin.tie(0),
      cout.tie(0);
  ;
  int c, a, b, n, x, ans = 0;
  cin >> c >> a >> b >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    if (x <= b || x >= c) continue;
    ans++;
  }
  return cout << ans << "\n", 0;
  return 0;
}
