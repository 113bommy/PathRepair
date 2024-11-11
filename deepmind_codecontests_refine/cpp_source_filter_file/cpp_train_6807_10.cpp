#include <bits/stdc++.h>
using namespace std;
inline int _pow(int a, int b) {
  int tmp = 1;
  for (; b; b >>= 1) {
    if (b & 1) tmp = (long long)tmp * a % 1000003;
    a = (long long)a * a % 1000003;
  }
  return tmp;
}
template <class T>
inline void R(T &xx) {
  xx = 0;
  char ch = getchar();
  bool F = 0;
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') F = 1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    xx = xx + xx + (xx << 3) + ch - 48, ch = getchar();
  if (F) xx = -xx;
}
int n;
int main() {
  R(n);
  if (n <= 2) return puts("-1"), 0;
  for (int i = 0; i < (int)(n); i++) printf("%d ", i);
  puts("");
  for (int i = 0; i < (int)(n); i++) printf("%d ", i);
  puts("");
  for (int i = 0; i < (int)(n); i++) printf("%d ", i * 2 % n);
  puts("");
  return 0;
}
