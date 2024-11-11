#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans;
  string s;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if ((s[i] - '0') % 2 == 0) ans += (i + 1);
  }
  cout << ans;
  return 0;
}
