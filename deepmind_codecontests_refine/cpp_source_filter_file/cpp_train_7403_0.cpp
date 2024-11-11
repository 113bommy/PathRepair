#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int t, n, m, l, s[30];
long long ans;
bool used[200010];
char str[200010];
void solve() {
  int n, m, l;
  scanf("%d%d%d", &n, &m, &l);
  scanf("%s", &str);
  ans = inf;
  for (int i = 0; i < 26; i++) {
    s[i] = 0;
  }
  for (int i = 0; i < l; i++) {
    s[str[i] - 'A']++;
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 1; j <= l; j++) {
      used[j] = false;
    }
    used[0] = true;
    for (int j = 0; j < 26; j++) {
      if (i == j) {
        continue;
      }
      for (int k = l; k >= s[i]; k--) {
        used[k] |= used[k - s[j]];
      }
    }
    for (int j = 0; j < l; j++) {
      if (!used[j]) {
        continue;
      }
      int x, y;
      x = max(0, n - j);
      y = max(m - (l - s[i] - j), 0);
      if (x + y <= s[i]) {
        ans = min(ans, 1LL * x * y);
      }
    }
  }
  printf("%I64d\n", ans);
}
int main() {
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
