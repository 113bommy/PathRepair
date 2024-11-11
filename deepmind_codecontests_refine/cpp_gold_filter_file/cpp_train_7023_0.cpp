#include <bits/stdc++.h>
using namespace std;
string s[1123];
int n, m;
bool ok[1123];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> s[i];
  memset(ok, false, sizeof(ok));
  ok[1] = true;
  int res = 0;
  for (int col = 0; col < m; col++) {
    bool mustRemove = false;
    for (int i = 2; i <= n; i++)
      if (!ok[i] && s[i][col] < s[i - 1][col]) mustRemove = true;
    res += mustRemove;
    if (!mustRemove) {
      for (int i = 2; i <= n; i++) ok[i] |= s[i][col] > s[i - 1][col];
    }
  }
  cout << res << endl;
  return 0;
}
