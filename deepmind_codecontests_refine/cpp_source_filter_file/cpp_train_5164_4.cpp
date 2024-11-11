#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T, class T1>
inline void gn(T &first, T1 &second) {
  gn(first);
  gn(second);
}
template <class T, class T1, class T2>
inline void gn(T &first, T1 &second, T2 &z) {
  gn(first);
  gn(second);
  gn(z);
}
template <class T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
template <class T>
inline void printsp(T first) {
  print(first);
  putchar(' ');
}
template <class T>
inline void println(T first) {
  print(first);
  putchar('\n');
}
template <class T, class U>
inline void print(T first, U second) {
  printsp(first);
  println(second);
}
template <class T, class U, class V>
inline void print(T first, U second, V z) {
  printsp(first);
  printsp(second);
  println(z);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
int ch[300010], re[300010], a[300010];
int C(int n, int m) {
  return ((long long)ch[n] * re[m] % 1000000007) * (long long)re[n - m] %
         1000000007;
}
void pre() {
  ch[0] = 1;
  for (int i = 1; i < 300010; i++)
    ch[i] = (long long)ch[i - 1] * i % 1000000007;
  re[300010 - 1] = power(ch[300010 - 1], 1000000007 - 2, 1000000007);
  for (int i = 300010 - 1; i > 0; i--)
    re[i - 1] = (long long)re[i] * i % 1000000007;
  return;
}
int main() {
  pre();
  int n;
  gn(n);
  for (int i = 1; i <= n; i++) gn(a[i]);
  if (n == 1) {
    printf("%d\n", a[1]);
    return 0;
  }
  if (n == 2) {
    printf("%d\n", ((a[1] - a[2]) % 1000000007 + 1000000007) % 1000000007);
    return 0;
  }
  if (n & 1) {
    for (int i = 1; i < n; i++) {
      if (i & 1)
        a[i] = ((a[i] + a[i + 1]) % 1000000007 + 1000000007) % 1000000007;
      else
        a[i] = ((a[i] - a[i + 1]) % 1000000007 + 1000000007) % 1000000007;
    }
    n--;
  }
  if (n == 2) {
    printf("%d\n", (a[1] + a[2]) % 1000000007);
    return 0;
  }
  long long ans1 = 0, ans2 = 0;
  int m = n / 2;
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      ans1 =
          (ans1 + (long long)C(m - 1, i / 2) * a[i] % 1000000007) % 1000000007;
    } else {
      ans2 = (ans2 + (long long)C(m - 1, i / 2 - 1) * a[i] % 1000000007) %
             1000000007;
    }
  }
  if (m & 1 == 1)
    printf("%I64d\n", (ans1 + ans2) % 1000000007);
  else
    printf("%I64d\n", ((ans1 - ans2) % 1000000007 + 1000000007) % 1000000007);
  return 0;
}
