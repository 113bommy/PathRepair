#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, const U &b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, const U &b) {
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
template <class T1, class T2>
inline void gn(T1 &x1, T2 &x2) {
  gn(x1), gn(x2);
}
template <class T1, class T2, class T3>
inline void gn(T1 &x1, T2 &x2, T3 &x3) {
  gn(x1, x2), gn(x3);
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
inline void println(T first) {
  print(first);
  putchar('\n');
}
template <class T>
inline void printsp(T first) {
  print(first);
  putchar(' ');
}
template <class T1, class T2>
inline void print(T1 x1, T2 x2) {
  printsp(x1), println(x2);
}
template <class T1, class T2, class T3>
inline void print(T1 x1, T2 x2, T3 x3) {
  printsp(x1), printsp(x2), println(x3);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = (long long)a * a % m)
    if (b & 1) ans = (long long)ans * a % m;
  return ans;
}
char s[100010], t[100010];
int len[100010];
pair<int, int> p[11];
int main() {
  scanf("%s", s);
  int n;
  gn(n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", t + len[i - 1]);
    len[i] = len[i - 1] + strlen(t + len[i - 1]);
  }
  for (int i = 0; i < 10; i++) p[i] = pair<int, int>(1, i);
  for (int i = n; i >= 1; i--) {
    int L = 0, sz = 0;
    for (int j = len[i - 1] + 3; j < len[i]; j++) {
      int u = t[j] - '0';
      sz = ((long long)sz * power(10, p[u].first, 1000000007) + p[u].second) %
           1000000007;
      L = (L + p[u].first) % 1000000006;
    }
    int u = t[len[i - 1]] - '0';
    p[u] = pair<int, int>(L, sz);
  }
  int ans = 0;
  for (int i = 0; s[i]; i++) {
    int u = s[i] - '0';
    ans = ((long long)ans * power(10, p[u].first, 1000000007) + p[u].second) %
          1000000007;
  }
  println(ans);
}
