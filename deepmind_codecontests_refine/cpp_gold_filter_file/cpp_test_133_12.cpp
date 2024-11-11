#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const long long mod = 19260817;
const long long INF = 1e14 + 10;
const long long maxn = 100010;
long long t, n;
char s1[3], s2[3], s[150];
signed main() {
  cin >> t;
  while (t--) {
    long long tot = -1;
    bool flag = 0;
    scanf("%lld", &n);
    scanf("%s", s1);
    s[++tot] = s1[0];
    s[++tot] = s1[1];
    for (long long i = 1; i <= n - 3; i++) {
      scanf("%s", s2);
      if (s2[0] != s1[1]) {
        flag = 1;
        s[++tot] = s2[0];
        s[++tot] = s2[1];
      } else if (s2[0] == s1[1]) {
        s[++tot] = s2[1];
      }
      s1[0] = s2[0];
      s1[1] = s2[1];
    }
    if (!flag) s[++tot] = 'a';
    s[++tot] = '\0';
    printf("%s\n", s);
  }
  return 0;
}
