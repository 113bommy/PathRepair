#include <bits/stdc++.h>
using namespace std;
int l[150];
int r[150];
string s[155];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  int y = n - 1;
  for (int i = 0; i < n; i++) {
    l[i] = -1;
    r[i] = -1;
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'W') {
        y = i;
        l[i] = j;
        break;
      }
    }
    for (int j = m - 1; j >= 0; j--) {
      if (s[i][j] == 'W') {
        r[i] = j;
        break;
      }
    }
  }
  int ans = -1;
  int last = 0;
  int q = 0;
  n = y + 1;
  for (int i = 0; i < n; i++) {
    if (l[i] == -1) {
      ans++;
      continue;
    }
    if (i % 2 == 0) {
      if (last > l[i]) {
        ans += last - l[i];
        last = l[i];
      }
      ans++;
      ans += r[i] - last;
      last = r[i];
      while (r[i + 1] == -1 && i + 1 != n) {
        i++;
        ans++;
      }
      if (i >= n - 1) break;
    } else {
      if (last < r[i]) {
        ans += r[i] - last;
        last = r[i];
      }
      ans++;
      ans += last - l[i];
      last = l[i];
      while (r[i + 1] == -1 && i + 1 != n) {
        i++;
        ans++;
      }
      if (i >= n - 1) break;
    }
  }
  cout << max(0, ans);
  return 0;
}
