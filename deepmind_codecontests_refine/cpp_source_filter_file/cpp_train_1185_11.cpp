#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0;
  char ch = getchar();
  bool fu = 0;
  while (!isdigit(ch)) {
    if (ch == '-') fu = 1;
    ch = getchar();
  }
  while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
  return fu ? -res : res;
}
double ans;
double a, b;
double sum;
int main() {
  a = (double)read() / (double)read(), b = (double)read() / (double)read();
  ans = a;
  sum = (1 - a) * (1 - b);
  for (register int i = 1; i <= 1000; i++) {
    ans += sum * a;
    sum *= (1.0 - a) * (1 - b);
  }
  printf("%.12lf\n", ans);
  return 0;
}
