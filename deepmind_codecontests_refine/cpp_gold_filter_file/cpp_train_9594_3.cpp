#include <bits/stdc++.h>
using namespace std;
int n, m;
int r[200], l[200];
int main() {
  memset(l, 10, sizeof(l));
  memset(r, -1, sizeof(r));
  cin.sync_with_stdio(false);
  cin >> n >> m;
  string s;
  int w = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (int j = 0; j < m; ++j)
      if (s[j] == 'W') {
        if (l[i] > m) l[i] = j;
        r[i] = j;
        w++;
      }
  }
  if (!w) {
    cout << 0;
    return 0;
  }
  int e = 0;
  for (int i = n - 1; i >= 0; --i)
    if (l[i] < m) {
      e = i + 1;
      break;
    }
  int j = 0;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (i == e) {
      --res;
      break;
    }
    if (i & 1) {
      if (i == n - 1)
        res += j - l[i];
      else {
        int k = min(l[i], l[i + 1]);
        if (k >= m) k = j;
        res += abs(j - k) + 1;
        j = k;
      }
    } else {
      if (i == n - 1)
        res += r[i] - j;
      else {
        int k = max(r[i], r[i + 1]);
        if (k == -1) k = j;
        res += abs(k - j) + 1;
        j = k;
      }
    }
  }
  cout << res;
  return 0;
}
