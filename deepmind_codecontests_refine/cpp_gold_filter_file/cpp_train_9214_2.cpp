#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    int n, i, j, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (i = 0; i < n; i++) {
      int cu = 0, cd = 0, cl = 0, cr = 0;
      for (j = i; j < n; j++) {
        if (s[j] == 'U')
          cu++;
        else if (s[j] == 'D')
          cd++;
        else if (s[j] == 'L')
          cl++;
        else
          cr++;
        if (cu == cd and cl == cr) ans++;
      }
    }
    cout << ans;
  }
  return 0;
}
