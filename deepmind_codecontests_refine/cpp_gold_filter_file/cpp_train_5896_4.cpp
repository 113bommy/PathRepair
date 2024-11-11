#include <bits/stdc++.h>
using namespace std;
int n, i, j, a, b[200010], ans;
int main() {
  cin >> n;
  ans = 1;
  b[0] = 1;
  for (i = 1; i <= n; i++) {
    cin >> a;
    if (b[a] != 0) {
      b[a] = 0;
      b[i] = 1;
      continue;
    }
    ans++;
    b[i] = 1;
  }
  cout << ans << endl;
  return 0;
}
