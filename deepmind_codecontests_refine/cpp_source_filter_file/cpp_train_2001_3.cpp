#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, mod = 1000000007;
const double pi = 3.1415926535897932, eps = 1e-6;
int n, nxt[26], dp[200005], mx;
char s[200005];
int main() {
  scanf("%d%s", &n, s + 1);
  for (int(i) = (1); (i) <= (n); (i)++) {
    int val = 0;
    for (int(j) = (s[i] - 97 + 1); (j) <= (25); (j)++)
      val = max(val, nxt[j] + 1);
    dp[i] = val;
    nxt[s[i] - 97] = val;
    mx = max(mx, dp[i]);
  }
  printf("%d\n", mx);
  for (int(i) = (1); (i) <= (n); (i)++) printf("%d ", dp[i]);
  return 0;
}
