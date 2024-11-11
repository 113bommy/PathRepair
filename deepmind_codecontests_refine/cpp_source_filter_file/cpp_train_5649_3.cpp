#include <bits/stdc++.h>
using namespace std;
const int N = 1 * 1000 * 1000 + 1;
int T, sum, maxMan, post, ans;
string s;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> s;
    int sum = maxMan = post = ans = 0;
    for (int i = 0; i < s.size(); i++) {
      sum += (s[i] == '+' ? 1 : -1);
      if (sum < maxMan) {
        maxMan = sum;
        ans += (-1 * maxMan - post) * (i + 1);
        post = -1 * maxMan;
      }
    }
    cout << ans + s.size() << endl;
  }
}
