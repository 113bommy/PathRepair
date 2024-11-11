#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-10;
inline int read() {
  static char ch;
  bool sgn = false;
  while (ch = getchar(), ch < '0' || ch > '9')
    if (ch == '-') sgn = true;
  int res = ch - 48;
  while (ch = getchar(), ch >= '0' && ch <= '9') res = res * 10 + ch - 48;
  return sgn ? -res : res;
}
const int N = 5e3 + 5;
int n, sg[N];
bool mex[N];
char s[N];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    memset(mex, 0, sizeof(mex));
    for (int j = 1; j <= i; j++) {
      int l = ((0) < (j - 2) ? (j - 2) : (0)),
          r = ((0) < (i - j - 1) ? (i - j - 1) : (0));
      mex[sg[l] ^ sg[r]] = 1;
    }
    for (int j = 0;; j++) {
      if (!mex[j]) {
        sg[i] = j;
        break;
      }
    }
  }
  int ans = 0, t = 0;
  for (int i = 1; i < n; i++) {
    if (s[i - 1] == s[i + 1])
      t++;
    else {
      ans ^= sg[t];
      t = 0;
    }
  }
  ans ^= sg[t];
  if (ans == 0) return puts("Second");
  puts("First");
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == s[i + 1]) {
      ans = t = 0;
      for (int j = 1; j < i - 1; j++) {
        if (s[j - 1] == s[j + 1])
          t++;
        else {
          ans ^= sg[t];
          t = 0;
        }
      }
      ans ^= sg[t];
      t = 0;
      for (int j = i + 2; j < n; j++) {
        if (s[j - 1] == s[j + 1])
          t++;
        else {
          ans ^= sg[t];
          t = 0;
        }
      }
      ans ^= sg[t];
      if (ans == 0) {
        printf("%d", i);
        return 0;
      }
    }
  }
}
