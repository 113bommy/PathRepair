#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  int ch = getchar();
  T f = 1;
  x = 0;
  while (!('0' <= ch && ch <= '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - 48;
    ch = getchar();
  }
  x *= f;
}
const int N = 1e5 + 10;
long long sum[N];
long long n, q, l, r;
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(sum[i]);
    sum[i] += sum[i - 1];
  }
  read(q);
  ++q;
  while (--q) {
    read(l);
    read(r);
    printf("%l64d\n", (sum[r] - sum[l - 1]) / 10);
  }
  return 0;
}
