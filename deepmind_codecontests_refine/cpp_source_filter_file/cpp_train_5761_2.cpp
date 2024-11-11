#include <bits/stdc++.h>
using namespace std;
const int maxx = 2000 + 9;
bool ispalin[maxx][maxx];
int st[maxx];
int en[maxx];
int main() {
  string s;
  cin >> s;
  int n = (int)s.size();
  for (int i = 0; i < n; i++) {
    for (int j = i; ~j; j--) {
      if (j + 1 >= i - 1 || ispalin[j + 1][i - 1])
        ispalin[j][i] = (s[i] == s[j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      st[i] += ispalin[i][j];
      en[j] += ispalin[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) ans += en[i] * st[j];
  }
  cout << ans << endl;
  return 0;
}
