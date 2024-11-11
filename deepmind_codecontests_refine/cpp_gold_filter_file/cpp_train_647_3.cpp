#include <bits/stdc++.h>
template <typename T>
void scan(T &x) {
  x = 0;
  bool _ = 0;
  T c = getchar();
  _ = c == 45;
  c = _ ? getchar() : c;
  while (c < 48 || c > 57) c = getchar();
  for (; c < 48 || c > 57; c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
  x = _ ? -x : x;
}
template <typename T>
void printn(T n) {
  bool _ = 0;
  _ = n < 0;
  n = _ ? -n : n;
  char snum[65];
  int i = 0;
  do {
    snum[i++] = n % 10 + 48;
    n /= 10;
  } while (n);
  --i;
  if (_) putchar(45);
  while (i >= 0) putchar(snum[i--]);
}
template <typename First, typename... Ints>
void scan(First &arg, Ints &...rest) {
  scan(arg);
  scan(rest...);
}
template <typename T>
void print(T n) {
  printn(n);
  putchar(10);
}
template <typename First, typename... Ints>
void print(First arg, Ints... rest) {
  printn(arg);
  putchar(32);
  print(rest...);
}
using namespace std;
const int MM = 1e5 + 5;
int n, a[MM], pre[MM], suf[MM], ans;
int main() {
  scan(n);
  for (int i = 1; i <= n; i++) {
    scan(a[i]);
  }
  for (int j = 30; j >= -30; j--) {
    for (int i = 1; i <= n; i++) pre[i] = a[i] + max(pre[i - 1], 0);
    for (int i = n; i; i--) {
      suf[i] = a[i] + max(suf[i + 1], 0);
      if (a[i] == j) {
        ans = max(ans, pre[i] - a[i] + suf[i] - a[i]);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] == j) a[i] = -MM * 30;
    }
  }
  print(ans);
  return 0;
}
