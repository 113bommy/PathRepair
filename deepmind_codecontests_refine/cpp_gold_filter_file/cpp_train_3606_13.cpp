#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, t, ans = 0;
  float j = -1000000, p = 0, q, s;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s;
    if (s < 0) {
      j = max(s, j);
      continue;
    }
    p = s;
    q = sqrt(s);
    if (q != ceil(q)) {
      j = max(j, p);
    }
  }
  ans = j;
  cout << ans;
}
