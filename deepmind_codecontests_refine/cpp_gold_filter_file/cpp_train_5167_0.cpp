#include <bits/stdc++.h>
using namespace std;
int a[26][100010];
int b[26];
int main() {
  int n, i, j, k, l, ans;
  string s;
  cin >> s;
  l = s.length();
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (i = 0; i < l; i++) {
    j = (int)(s[i] - 'a');
    a[j][b[j]] = i;
    b[j]++;
  }
  ans = 0x3f3f3f3f;
  for (i = 0; i < 26; i++) {
    sort(a[i], a[i] + b[i]);
    k = a[i][0] + 1;
    for (j = 1; j < b[i]; j++) {
      k = max(a[i][j] - a[i][j - 1], k);
    }
    k = max(l - a[i][b[i] - 1], k);
    if (b[i] != 0) ans = min(ans, k);
  }
  cout << ans << endl;
}
