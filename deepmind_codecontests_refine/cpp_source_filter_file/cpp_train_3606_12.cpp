#include <bits/stdc++.h>
using namespace std;
char s[2003][2003];
int main() {
  int n, m, i, j, k, ans = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> m;
    int x = sqrt(m);
    if (x * x != m) ans = max(ans, m);
  }
  cout << ans << endl;
  return 0;
}
