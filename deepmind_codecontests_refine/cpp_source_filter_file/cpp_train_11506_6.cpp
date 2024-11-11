#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
bool a[1003];
int main() {
  int n, x, m, ans = 0, c;
  string s;
  cin >> n >> m;
  while (m--) {
    cin >> s >> s >> s;
    if (s[0] == 'l') {
      cin >> s >> x;
      for (int i = x; i <= n; i++) a[i] = true;
      c = 0;
      for (int i = x - 1; i && !c; i--)
        if (a[i]) c = 1;
      if (!c) ans = -1;
    } else {
      cin >> s >> x;
      for (int i = x; i; i--) a[i] = true;
      c = 0;
      for (int i = x + 1; i <= n && !c; i++)
        if (a[i]) c = 1;
      if (!c) ans = -1;
    }
  }
  for (int i = 1; i <= n && ans != -1; i++) ans += !a[i];
  cout << ans;
  return 0;
}
