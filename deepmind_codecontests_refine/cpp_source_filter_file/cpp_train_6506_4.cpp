#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (cin >> n >> m) {
    int num[m];
    memset(num, 0, sizeof(num));
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      num[(int)s[i] - 97] += 1;
    }
    int ans = 0;
    int k = 1;
    for (int i = 0; i < n; i++) {
      if (s[i] == s[i - 1] && i >= 1) continue;
      if (s[i] == s[i - 2] && i > 1) {
        ans -= k;
        k++;
      } else
        k = 1;
      for (int j = 0; j < m; j++) ans += n - num[j];
      ans--;
    }
    cout << ans + 1 << endl;
  }
  return 0;
}
