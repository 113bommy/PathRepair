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
int a[505050];
int B[505050];
void update(int u) {
  for (; u < 505050; u += u & -u) B[u]++;
}
int calc(int u, int ans = 0) {
  for (; u; u -= u & -u) ans += B[u];
  return ans;
}
int main() {
  int n, k, d;
  gn(n, k, d);
  for (int i = 2; i <= n + 1; i++) gn(a[i]);
  sort(a + 2, a + n + 2);
  update(1);
  int j = 2;
  for (int i = 2; i <= n + 1; i++) {
    while (a[i] - a[j] > d) j++;
    if (i - j + 1 >= k) {
      if (calc(i - k) - calc(j - 2)) update(i);
    }
  }
  if (calc(n + 1) - calc(n))
    puts("YES");
  else
    puts("NO");
  return 0;
}
