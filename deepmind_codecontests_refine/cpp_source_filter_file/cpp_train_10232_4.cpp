#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f;
const double pi = 3.1415926535897932384626;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int maxn = 2e5 + 5;
int t, n, a[maxn], b[maxn];
char s[maxn];
int main() {
  t = read();
  while (t--) {
    n = read();
    scanf("%s", s);
    int ans = 0, lena = 1, lenb = 0, cnt = 1;
    a[lena] = 1;
    for (int i = 1; i < n; i++) {
      if (s[i] == s[i - 1])
        ++a[lena];
      else
        a[++lena] = 1;
    }
    for (int i = 1; i <= lena; i++) {
      if (a[i] > 1) b[++lenb] = i;
    }
    for (int i = 1; i <= lena; i++) {
      if (a[i] > 1) {
        ++ans;
        ++cnt;
      } else {
        if (cnt > lenb) {
          ans += (lena - cnt + 2) >> 1;
          break;
        } else {
          --a[b[cnt]];
          if (a[b[cnt]] <= 1) ++cnt;
          ++ans;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
