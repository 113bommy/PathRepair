#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 15;
const long long p = 1e9 + 7;
char s[MAXN];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int x;
    scanf("%d", &x);
    scanf("%s", s);
    long long len = strlen(s), rlen = strlen(s);
    int i = 1;
    while (i <= x) {
      rlen--;
      if (len <= x) {
        long long tmp = len;
        while (len - tmp < rlen * (s[i - 1] - '0' - 1)) {
          s[len] = s[i + ((len - tmp) % rlen)];
          len++;
          if (len > x) break;
        }
      }
      rlen = (rlen * (s[i - 1] - '0')) % p;
      i++;
    }
    printf("%lld\n", (x + rlen) % p);
  }
  return 0;
}
