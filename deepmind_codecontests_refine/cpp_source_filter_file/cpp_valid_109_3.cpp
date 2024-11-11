#include <bits/stdc++.h>
using namespace std;
void kaam() {
  int n, ans = 0;
  cin >> n;
  string s, h = "", g;
  cin >> s;
  g = s;
  sort(s.begin(), s.end());
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '0') break;
    ans++;
    h += s[i];
    ans += stoi(h);
    h = "";
  }
  if (g[n - 1] == s[n - 1] && ans > 0) ans--;
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) kaam();
  return 0;
}
