#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int ls, cnt, n, ans;
signed main() {
  cin >> s + 1;
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'F') {
      if (cnt) ans = max(ans, cnt + ls), ls++;
    } else {
      cnt++;
      if (ls) ls--;
    }
  }
  printf("%d", ans);
}
