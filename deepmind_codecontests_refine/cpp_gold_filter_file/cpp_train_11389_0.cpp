#include <bits/stdc++.h>
using namespace std;
const unsigned long long base = 31;
const int maxn = 1e5 + 100;
const int inf = 1e9 + 10;
const long long mod = 1e9 + 7;
int n, now;
unsigned long long w[maxn], p[maxn];
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
unsigned long long get(int l, int r) { return w[r] - w[l - 1] * p[r - l + 1]; }
int LCP(int x, int y) {
  int l, r, ret;
  l = 0;
  r = now;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (get(x - mid + 1, x) == get(y - mid + 1, y)) {
      l = mid + 1;
      ret = mid;
    } else
      r = mid - 1;
  }
  return ret;
}
int LCS(int x, int y) {
  int l = 0, ret, r = n - y + 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (get(x, x + mid - 1) == get(y, y + mid - 1)) {
      ret = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return ret;
}
char s[maxn];
int a[maxn];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] * base;
    w[i] = w[i - 1] * base + s[i] - 'a';
  }
  for (int len = 1; len <= n; len++) {
    int j = len, k = 2 * len;
    now = len;
    int flag = 0;
    while (k <= n) {
      int lcp = LCP(j, k), lcs = LCS(j, k);
      if (lcp + lcs > len) {
        for (int i = j - lcp + 1; i <= j - lcp + len; i++) a[i] = len;
        now = lcp;
        flag = 1;
      } else {
        now = len;
      }
      j += len;
      k += len;
    }
    if (flag) {
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (a[i] != len) {
          s[++cnt] = s[i];
        }
      }
      n = cnt;
      for (int i = 1; i <= n; i++) w[i] = (w[i - 1] * base + s[i] - 'a');
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%c", s[i]);
  }
  cout << endl;
  return 0;
}
