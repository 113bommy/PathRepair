#include <bits/stdc++.h>
using namespace std;
char s[200010], t[200010];
string ans;
void solve() {
  int n = strlen(s), x = 0;
  for (int i = 0; i < n; i++) {
    if (i) ans += '+';
    if (i < n - 1 && rand() % 2 == 0) {
      ans += (s[i]), ans += s[++i];
      x += 10 * (s[i - 1] - '0') + s[i] - '0';
    } else {
      ans += (s[i]);
      x += s[i] - '0';
    }
  }
  ans += '\n';
  sprintf(s, "%d", x);
}
int main() {
  srand(time(0));
  scanf("%s%s", s, t);
  while (1) {
    strcpy(s, t);
    ans = "";
    solve();
    solve();
    solve();
    if (strlen(s) == 1) return cout << ans, 0;
  }
}
