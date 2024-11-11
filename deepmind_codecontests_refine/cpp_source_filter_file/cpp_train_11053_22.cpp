#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int SUM = 0, ff = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    SUM = (SUM << 3) + (SUM << 1) + (ch ^ 48);
    ch = getchar();
  }
  return SUM * ff;
}
const int N = 100010;
int a[N], p[N];
int ans[N];
int n;
inline int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  srand(19491001);
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) p[i] = i;
  int test = 150;
  while (test--) {
    random_shuffle(p + 1, p + n + 1);
    int gcd1 = 0, gcd2 = 0;
    for (int i = 1; i <= n; i++) {
      int x = gcd(gcd1, a[p[i]]);
      if (gcd1 != 1 && x != gcd1) {
        gcd1 = x;
        ans[p[i]] = 1;
      } else {
        gcd2 = gcd(gcd2, a[p[i]]);
        ans[p[i]] = 2;
      }
    }
    if (gcd1 == 1 && gcd2 == 1) {
      puts("YES");
      for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
      return 0;
    }
  }
  puts("NO");
  return 0;
}
