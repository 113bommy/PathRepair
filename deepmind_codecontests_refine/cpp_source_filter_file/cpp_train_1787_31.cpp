#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int n;
char s[maxn];
inline bool check(int l, int r) {
  for (int k = 1; r - 2 * k >= l; ++k) {
    if (s[r] == s[r - k] && s[r] == s[r - 2 * k]) return false;
  }
  return true;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int p = min(i + 4, n);
    for (; check(i, p) && p < n; ++p)
      ;
    ans += n - p;
  }
  cout << ans << endl;
  return 0;
}
