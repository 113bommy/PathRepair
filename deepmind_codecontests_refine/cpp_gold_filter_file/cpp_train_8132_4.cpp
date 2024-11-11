#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &t) {
  t = 0;
  char ch = getchar();
  int f = 1;
  while ('0' > ch || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  do {
    (t *= 10) += ch - '0';
    ch = getchar();
  } while ('0' <= ch && ch <= '9');
  t *= f;
}
int n, a;
long long b;
int main() {
  read(n);
  while (n--) {
    read(b);
    read(a);
    printf("%lld\n", (b - 1) * 9 + a);
  }
  return 0;
}
