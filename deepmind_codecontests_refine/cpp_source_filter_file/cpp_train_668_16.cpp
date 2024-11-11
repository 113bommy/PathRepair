#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  int l = s.length();
  s = " " + s;
  int aO[l + 5], aE[l + 5], bO[l + 5], bE[l + 5], ans[l + 5][2];
  if (s[1] == 'a') {
    aO[1] = 1;
    aE[1] = 0;
    bO[1] = 0;
    bE[1] = 0;
  } else {
    aO[1] = 0;
    aE[1] = 0;
    bO[1] = 1;
    bE[1] = 0;
  }
  ans[1][0] = 1;
  ans[1][1] = 0;
  for (int i = 2; i <= l; i++) {
    if (i % 2) {
      if (s[i] == 'a') {
        aO[i] = aO[i - 1] + 1;
        aE[i] = aE[i - 1];
        bO[i] = bO[i - 1];
        bE[i] = bE[i - 1];
        ans[i][0] = ans[i - 1][0] + aO[i - 1] + 1;
        ans[i][1] = ans[i - 1][1] + aE[i - 1];
      } else {
        aO[i] = aO[i - 1];
        aE[i] = aE[i - 1];
        bO[i] = bO[i - 1] + 1;
        bE[i] = bE[i - 1];
        ans[i][0] = ans[i - 1][0] + bO[i - 1] + 1;
        ans[i][1] = ans[i - 1][1] + bE[i - 1];
      }
    } else {
      if (s[i] == 'a') {
        aO[i] = aO[i - 1];
        aE[i] = aE[i - 1] + 1;
        bO[i] = bO[i - 1];
        bE[i] = bE[i - 1];
        ans[i][0] = ans[i - 1][0] + aE[i - 1] + 1;
        ans[i][1] = ans[i - 1][1] + aO[i - 1];
      } else {
        aO[i] = aO[i - 1];
        aE[i] = aE[i - 1];
        bO[i] = bO[i - 1];
        bE[i] = bE[i - 1] + 1;
        ans[i][0] = ans[i - 1][0] + bE[i - 1] + 1;
        ans[i][1] = ans[i - 1][1] + bO[i - 1];
      }
    }
  }
  cout << ans[l][1] << " " << ans[l][0] << endl;
}
