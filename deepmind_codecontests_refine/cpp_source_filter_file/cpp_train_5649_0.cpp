#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int ans = 0, in = 0, cur = 0, x = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '+')
        cur++;
      else
        cur--;
      ++x;
      if (cur < 0) {
        cur -= in;
        cur += ++in;
        ans += x;
      }
    }
    cout << ans + x << "\n";
  }
}
