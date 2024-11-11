#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[100005], b[100005];
int main() {
  int l = -1e9, r = 1000000007 - 7;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  string s;
  cin >> s;
  for (int i = 1; i <= s.size(); i++) b[i] = s[i - 1] - '0';
  int pos = n;
  while (b[pos] == b[pos - 1]) pos--;
  for (int i = 5; i <= pos; i++) {
    if (b[i] == b[i - 1]) continue;
    if (b[i] == 1) {
      if (a[i] < l && a[i - 1] < l && a[i - 2] < l && a[i - 3] < l &&
          a[i - 4] < l)
        continue;
      if (!b[i - 1] && !b[i - 2] && !b[i - 3] && !b[i - 4])
        l = max(
            max(max(max(max(a[i], a[i - 1]), a[i - 2]), a[i - 3]), a[i - 4]) +
                1,
            l);
    } else {
      if (a[i] > r && a[i - 1] > r && a[i - 2] > r && a[i - 3] > r &&
          a[i - 4] > r)
        continue;
      if (b[i - 1] && b[i - 2] && b[i - 3] && b[i - 4])
        r = min(
            min(min(min(min(a[i], a[i - 1]), a[i - 2]), a[i - 3]), a[i - 4]) -
                1,
            r);
    }
  }
  cout << l << " " << r << endl;
  return 0;
}
