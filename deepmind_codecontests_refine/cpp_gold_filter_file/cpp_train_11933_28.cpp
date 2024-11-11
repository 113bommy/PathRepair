#include <bits/stdc++.h>
template <typename tp>
inline tp max(const tp& x, const tp& y) {
  return x > y ? x : y;
}
template <typename tp>
inline tp min(const tp& x, const tp& y) {
  return x < y ? x : y;
}
template <typename tp>
inline bool chkmax(tp& x, const tp& y) {
  return (x >= y) ? false : (x = y, true);
}
template <typename tp>
inline bool chkmin(tp& x, const tp& y) {
  return (x <= y) ? false : (x = y, true);
}
template <typename tp>
inline tp scanf(tp& in) {
  in = 0;
  char ch = getchar();
  tp f = 1;
  for (; ch > '9' || ch < '0'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) in = in * 10 + ch - '0';
  return in *= f;
}
int A;
int main() {
  scanf("%d", &A);
  printf("%d 2\n", A - 1 << 1 | 1);
  puts("1 2");
  return 0;
}
