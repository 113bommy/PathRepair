#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const int B = 10;
const int L = 1010;
struct HP {
  int len, s[L];
  HP() { (*this) = 0; }
  HP(int i) { (*this) = i; }
  HP operator=(int i) {
    if (i == 0) {
      len = 1;
      s[1] = 0;
      return *this;
    }
    for (len = 0; i > 0;) {
      s[++len] = i % B;
      i /= B;
    }
    return *this;
  }
  HP operator*(const HP &b) const {
    int i, j;
    HP c;
    c.len = len + b.len;
    for (i = 1; i <= c.len; ++i) {
      c.s[i] = 0;
    }
    for (i = 1; i <= len; ++i) {
      for (j = 1; j <= b.len; ++j) {
        c.s[i + j - 1] += s[i] * b.s[j];
      }
    }
    for (i = 1; i < c.len; ++i) {
      c.s[i + 1] += c.s[i] / B;
      c.s[i] %= B;
    }
    while (c.s[i]) {
      c.s[i + 1] = c.s[i] / B;
      c.s[i] %= B;
      ++i;
    }
    while (i > 1 && !c.s[i]) {
      --i;
    }
    c.len = i;
    return c;
  }
  HP operator+(const HP &b) const {
    int i;
    HP c;
    c.s[1] = 0;
    for (i = 1; i <= len || i <= b.len || c.s[i]; ++i) {
      if (i <= len) {
        c.s[i] += s[i];
      }
      if (i <= b.len) {
        c.s[i] += b.s[i];
      }
      c.s[i + 1] = c.s[i] / B;
      c.s[i] %= B;
    }
    c.len = i - 1;
    if (c.len == 0) {
      c.len = 1;
    }
    return c;
  }
  bool operator<(const HP &b) const {
    int i;
    if (b.len > len) return 1;
    if (len > b.len) return 0;
    for (int i = len; i >= 1; --i) {
      if (s[i] < b.s[i]) return 1;
      if (b.s[i] < s[i]) return 0;
    }
    return 0;
  }
  HP operator-(const HP &b) const {
    int i, j;
    HP c;
    for (i = 1, j = 0; i <= len; ++i) {
      c.s[i] - s[i] - j;
      if (i <= b.len) {
        c.s[i] -= b.s[i];
      }
      if (c.s[i] < 0) {
        j = 1;
        c.s[i] += B;
      } else {
        j = 0;
      }
    }
    c.len = len;
    while (c.len > 1 && !c.s[c.len]) {
      --c.len;
    }
    return c;
  }
  void print() {
    for (int i = len; i >= 1; --i) {
      putchar(s[i] + '0');
    }
    putchar('\n');
  }
};
HP a[N];
bool fl[N];
HP pw[N];
int main() {
  HP *dp = a + 1;
  bool *ok = fl + 1;
  dp[-1] = 0;
  ok[-1] = 1;
  pw[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw[i] = pw[i - 1] * 2;
  }
  int n;
  scanf("%d", &n);
  for (int i = 0, x; i < n; ++i) {
    char s[10];
    scanf("%s%d", s, &x);
    if (s[0] == 'w') {
      if (ok[x])
        dp[x] = max(dp[x], dp[-1]);
      else
        dp[x] = dp[-1];
      ok[x] = 1;
    } else {
      if (ok[x]) dp[-1] = max(dp[-1], dp[x] + pw[x]);
    }
  }
  HP ans = 0;
  for (int i = -1; i <= 2000; ++i) {
    ans = max(dp[i], ans);
  }
  ans.print();
  return 0;
}
