#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int i, j, k, n, m, z, y, x, ans;
  string ch, ch1;
  cin >> ch;
  cin >> ch1;
  n = ch.length();
  m = ch1.length();
  x = m - 1;
  vector<long long int> l(m, 0);
  vector<long long int> r(m, 0);
  for (i = n - 1; i >= 0; i--) {
    if (ch[i] == ch1[x]) {
      r[x] = i;
      x--;
    }
    if (x < 0) break;
  }
  x = 0;
  for (i = 0; i < n; i++) {
    if (ch[i] == ch1[x]) {
      l[x] = i;
      x++;
    }
    if (x >= m) break;
  }
  x = 0;
  ans = r[0];
  ans = max(ans, n - l[m - 1] - 1);
  for (i = 0; i < m; i++) {
    y = r[i] - l[i] - 1;
    ans = max(ans, y);
  }
  cout << ans;
}
