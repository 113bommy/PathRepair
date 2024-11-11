#include <bits/stdc++.h>
using namespace std;
const int N = 505000;
int n;
int top, cnt;
double ans, sum;
int a[N];
inline long long read() {
  long long re = 0, k = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') k = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    re = re * 10 + ch - '0';
    ch = getchar();
  }
  return re * k;
}
int main() {
  n = read();
  for (register int i = 1; i <= n; i++) {
    int opt = read();
    if (opt == 1) {
      int x = read();
      sum -= a[cnt];
      a[++cnt] = x;
      sum += a[cnt];
      ans = a[cnt] - (sum) / (top + 1);
      for (; top < cnt - 1; top++) {
        double now = (sum + a[top + 1]) / (top + 2);
        if (a[cnt] - now > ans)
          ans = a[cnt] - now, sum += a[top + 1];
        else
          break;
      }
    }
    if (opt == 2) {
      printf("%.10lf\n", ans);
    }
  }
  return 0;
}
