#include <bits/stdc++.h>
using namespace std;
int f[1000002], a[1000002], z[1000002];
string s;
void kmp() {
  f[0] = f[1] = 0;
  int i, l = s.size(), j = 0;
  for (i = 2; i <= l; i++) {
    j = f[i - 1];
    while (1) {
      if (s[j] == s[i - 1]) {
        f[i] = j + 1;
        break;
      }
      if (j == 0) break;
      j = f[j];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  long long int ans = 0;
  int n, m, i, j;
  cin >> n >> m;
  cin >> s;
  int l = s.size();
  kmp();
  for (i = 0; i < m; i++) {
    cin >> a[i];
    a[i]--;
  }
  sort(a, a + m);
  for (i = 1; i < m; i++) {
    if (a[i] < a[i - 1] + l) {
      int x = a[i] - a[i - 1], y = l - x;
      j = l;
      while (j >= y && f[j] != y) j = f[j];
      if (f[j] != y) {
        ans = -1;
        break;
      }
    }
  }
  if (ans == -1)
    cout << 0 << endl;
  else {
    int cur = 0;
    for (i = 0; i < n && cur < m; i++) {
      while (cur < m && a[cur] + l <= i) cur++;
      if (a[cur] <= i && a[cur] + l > i) z[i] = 1;
    }
    ans = 1;
    for (i = 0; i < n; i++) {
      if (!z[i]) ans = (ans * 26) % 1000000007;
    }
    cout << ans << endl;
  }
  return 0;
}
