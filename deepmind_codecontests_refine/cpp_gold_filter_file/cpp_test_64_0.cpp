#include <bits/stdc++.h>
using namespace std;
template <typename T>
void cmax(T& x, T y) {
  if (x < y) x = y;
}
template <typename T>
void cmin(T& x, T y) {
  if (y < x) x = y;
}
int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
const int N = 500005;
int n, m;
int P1 = 1e9 + 21, P2 = 1000438447, P3 = 998244353;
char s[N], t[N];
struct {
  int h1[N], h2[N], h3[N], b1[N], b2[N], b3[N];
  void ins(char* s) {
    b1[0] = b2[0] = b3[0] = 1;
    for (int i = (1); i <= (N - 5); i++) {
      b1[i] = 10ll * b1[i - 1] % P1;
      b2[i] = 10ll * b2[i - 1] % P2;
      b3[i] = 10ll * b3[i - 1] % P3;
    }
    int len = strlen(s + 1);
    for (int i = (1); i <= (len); i++) {
      h1[i] = (10ll * h1[i - 1] + s[i] - '0') % P1;
      h2[i] = (10ll * h2[i - 1] + s[i] - '0') % P2;
      h3[i] = (10ll * h3[i - 1] + s[i] - '0') % P3;
    }
  }
  tuple<int, int, int> get(int l, int r) {
    return {(h1[r] - 1ll * b1[r - l + 1] * h1[l - 1] % P1 + P1) % P1,
            (h2[r] - 1ll * b2[r - l + 1] * h2[l - 1] % P2 + P2) % P2,
            (h3[r] - 1ll * b3[r - l + 1] * h3[l - 1] % P3 + P3) % P3};
  }
} S, T;
int lcp(int x) {
  int l = 1, r = min(m, n - x + 1), ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (S.get(x, x + mid - 1) == T.get(1, mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return ans;
}
tuple<int, int, int> add(tuple<int, int, int> x, tuple<int, int, int> y) {
  tuple<int, int, int> z;
  int a, b, c, d, e, f;
  tie(a, b, c) = x, tie(d, e, f) = y;
  z = {(a + d) % P1, (b + e) % P2, (c + f) % P3};
  return z;
}
void chk(int a, int b, int c) {
  if (add(S.get(a, b), S.get(b + 1, c)) == T.get(1, m)) {
    printf("%d %d\n%d %d\n", a, b, b + 1, c);
    exit(0);
  }
}
int main() {
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1), m = strlen(t + 1);
  S.ins(s), T.ins(t);
  if (m > 1) {
    for (int i = (1); i <= (n); i++)
      if (i + 2 * m - 3 <= n) chk(i, i + m - 2, i + 2 * m - 3);
  }
  for (int i = (1); i <= (n); i++)
    if (i + m - 1 <= n) {
      int t = lcp(i);
      if (t >= m) continue;
      if (i - m + t >= 1) chk(i - m + t, i - 1, i + m - 1);
      if (i + 2 * m - 1 - t <= n) chk(i, i + m - 1, i + 2 * m - 1 - t);
      if (i - m + t + 1 >= 1) chk(i - m + t + 1, i - 1, i + m - 1);
      if (i + 2 * m - 2 - t <= n) chk(i, i + m - 1, i + 2 * m - 2 - t);
    }
}
