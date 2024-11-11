#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y) {
  long long int m = 1000000007;
  long long int ans = 1;
  while (y > 0) {
    if (y & 1) ans = (ans * x) % m;
    x = (x * x) % m;
    y >>= 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int len = s.length();
    long long int l = 0, r = 0, u = 0, d = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == 'L') l++;
      if (s[i] == 'R') r++;
      if (s[i] == 'U') u++;
      if (s[i] == 'D') d++;
    }
    long long int lr = min(l, r);
    long long int ud = min(u, d);
    l = lr;
    r = lr;
    u = ud;
    d = ud;
    if (lr == 0 and ud != 0) {
      cout << "2\nUD"
           << "\n";
      continue;
    }
    if (ud == 0 and lr != 0) {
      cout << "2\nLR"
           << "\n";
      continue;
    }
    cout << 2 * (lr + ud) << "\n";
    if (lr > 0) cout << "L";
    for (int i = 0; i < ud; i++) cout << "U";
    if (lr > 0) cout << "R";
    lr -= 1;
    for (int i = 0; i < lr; i++) cout << "R";
    for (int i = 0; i < ud; i++) cout << "D";
    for (int i = 0; i < lr; i++) cout << "L";
    cout << "\n";
  }
  return 0;
}
