#include <bits/stdc++.h>
using namespace std;
const int maxn = 1100000;
const int magic = 3137;
unsigned long long p[maxn];
char s[maxn];
int match[maxn];
int n;
int check(int leng) {
  unsigned long long prefix = 0;
  for (int i = 0; i < leng; ++i) {
    prefix = prefix * magic + s[i];
  }
  int cnt = 1;
  unsigned long long cur = prefix;
  for (int i = leng; i < n && cnt < 3; ++i) {
    cur = cur * magic + s[i];
    cur -= p[leng] * s[i - leng];
    if (cur == prefix) {
      cnt++;
    }
  }
  return cnt >= 3;
}
int main() {
  p[0] = 1;
  for (int i = 1; i <= 1000000; ++i) {
    p[i] = p[i - 1] * magic;
  }
  scanf("%s", &s);
  n = strlen(s);
  unsigned long long prefix = 0, suffix = 0;
  for (int i = 0; i < n; ++i) {
    prefix = prefix * magic + s[i];
    suffix += p[i] * s[n - 1 - i];
    if (prefix == suffix) {
      match[i + 1] = 1;
    } else {
      match[i + 1] = 0;
    }
  }
  int lo = 1, hi = n, ans = 0;
  for (; lo <= hi;) {
    int m = (lo + hi) / 2;
    if (check(m)) {
      ans = m;
      lo = m + 1;
    } else {
      hi = m - 1;
    }
  }
  int lower = 1, upper = ans;
  for (int i = upper; i >= lower; --i) {
    if (match[i]) {
      s[i] = 0;
      printf("%s\n", s);
      return 0;
    }
  }
  printf("Just a legend\n");
}
