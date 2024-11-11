#include <bits/stdc++.h>
using namespace std;
bool o;
char chh, ss[1 << 17], *A = ss, *B = ss;
inline char gc() {
  return A == B && (B = (A = ss) + fread(ss, 1, 1 << 17, stdin), A == B) ? EOF
                                                                         : *A++;
}
inline void getstr(char *a, int &n) {
  a[n = 1] = gc();
  while (!((a[1] >= '0' && a[1] <= '9') || (a[1] >= 'A' && a[1] <= 'Z') ||
           (a[1] >= 'a' && a[1] <= 'z')))
    a[1] = gc();
  while (((a[n] >= '0' && a[n] <= '9') || (a[n] >= 'A' && a[n] <= 'Z') ||
          (a[n] >= 'a' && a[n] <= 'z')))
    a[++n] = gc();
  n--;
}
template <typename _Tp>
inline void rd(_Tp &x);
template <typename _Tp>
inline void wr(_Tp x);
template <typename _Tp>
inline _Tp mx(_Tp x, _Tp y);
template <typename _Tp>
inline _Tp mn(_Tp x, _Tp y);
int t;
long long n, k;
int qwq[21];
inline int dfs(int i) {
  if (i == 0) return 0;
  if (qwq[i] ^ -1) return qwq[i];
  int tp = 0;
  if (i >= 1)
    if (!dfs(i - 1)) tp = 1;
  if (i >= 2)
    if (!dfs(i - 2)) tp = 1;
  if (i >= k)
    if (!dfs(i - k)) tp = 1;
  return qwq[i] = tp;
}
int main() {
  rd(t);
  while (t--) {
    rd(n);
    rd(k);
    if (n < k) {
      if (n % 3)
        puts("Alice");
      else
        puts("Bob");
    } else if (k % 3) {
      if (n % 3)
        puts("Alice");
      else
        puts("Bob");
    } else {
      long long tp = k / 3 - 1;
      n %= tp * 3 + 4;
      if (n == 0 || (n < tp * 3 && n % 3 == 0))
        puts("Bob");
      else
        puts("Alice");
    }
  }
}
template <typename _Tp>
inline void rd(_Tp &x) {
  o = 0;
  x = 0;
  while (chh ^ 45 && (chh < 48 || chh > 57)) chh = gc();
  if (chh == 45) o = 1, chh = gc();
  while (chh > 47 && chh < 58) {
    x = (x << 1) + (x << 3) + (chh ^ 48);
    chh = gc();
  }
  if (o) x = -x;
}
template <typename _Tp>
inline void wr(_Tp x) {
  if (x < 0) x = -x, putchar(45);
  if (x < 10) {
    putchar(x + 48);
    return;
  }
  wr(x / 10);
  putchar(x % 10 + 48);
}
template <typename _Tp>
inline _Tp mx(_Tp x, _Tp y) {
  return x > y ? x : y;
}
template <typename _Tp>
inline _Tp mn(_Tp x, _Tp y) {
  return x < y ? x : y;
}
