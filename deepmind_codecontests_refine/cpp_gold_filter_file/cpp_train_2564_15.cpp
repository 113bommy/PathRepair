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
template <typename T>
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
template <typename T>
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
template <typename T>
inline void println(T first) {
  print(first), putchar('\n');
}
template <typename T>
inline void printsp(T first) {
  print(first), putchar(' ');
}
template <class T, class T1>
inline void print(T first, T1 second) {
  printsp(first), println(second);
}
template <class T, class T1, class T2>
inline void print(T first, T1 second, T2 z) {
  printsp(first), printsp(second), println(z);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
vector<int> a, b, c;
int main() {
  int n;
  gn(n);
  a.push_back(1);
  b.push_back(0);
  for (int i = 0; i < n; i++) {
    c.clear();
    int ok = 1;
    for (int j = 0; ok && j <= a.size(); j++) {
      int v = (j < b.size() ? b[j] : 0) + (j ? a[j - 1] : 0);
      c.push_back(v);
      if (abs(v) > 1) ok = 0;
    }
    if (!ok) {
      c.clear();
      for (int j = 0; j <= a.size(); j++) {
        int v = -(j < b.size() ? b[j] : 0) + (j ? a[j - 1] : 0);
        c.push_back(v);
      }
    }
    b = a, a = c;
  }
  printf("%d\n", a.size() - 1);
  for (int i = 0; i < a.size(); i++) printsp(a[i]);
  puts("");
  printf("%d\n", b.size() - 1);
  for (int i = 0; i < b.size(); i++) printsp(b[i]);
  return 0;
}
