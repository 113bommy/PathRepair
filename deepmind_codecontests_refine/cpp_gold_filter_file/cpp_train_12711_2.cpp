#include <bits/stdc++.h>
using namespace std;
template <typename T>
T read1() {
  T t = 0;
  char k;
  bool vis = 0;
  do (k = getchar()) == '-' && (vis = 1);
  while ('0' > k || k > '9');
  while ('0' <= k && k <= '9')
    t = (t << 3) + (t << 1) + (k ^ '0'), k = getchar();
  return vis ? -t : t;
}
int m, s;
unsigned long long a[2097152], b[2097152];
template <typename T>
void FWT_or(T *a, int s) {
  for (int i = 1, j = 2; j <= s; i <<= 1, j <<= 1)
    for (int x = 0; x < s; x += j)
      for (int y = 0; y < i; ++y) a[i + x + y] = a[i + x + y] + a[x + y];
}
template <typename T>
void IFWT_or(T *a, int s) {
  for (int i = 1, j = 2; j <= s; i <<= 1, j <<= 1)
    for (int x = 0; x < s; x += j)
      for (int y = 0; y < i; ++y) a[i + x + y] = a[i + x + y] - a[x + y];
}
char str[1 << 21 | 1];
int main() {
  s = 1 << (m = read1<long long>());
  scanf("%s", str);
  for (int i = 0; i < s; ++i)
    a[i] = str[i] ^ '0', a[i] <<= __builtin_popcount(i) << 1;
  scanf("%s", str);
  for (int i = 0; i < s; ++i)
    b[i] = str[i] ^ '0', b[i] <<= __builtin_popcount(i) << 1;
  FWT_or(a, s);
  FWT_or(b, s);
  for (int i = 0; i < s; ++i) a[i] *= b[i];
  IFWT_or(a, s);
  for (int i = 0; i < s; ++i)
    str[i] = '0' ^ (a[i] >> (__builtin_popcount(i) << 1) & 3);
  puts(str);
  return 0;
}
