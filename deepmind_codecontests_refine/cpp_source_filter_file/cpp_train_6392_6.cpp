#include <bits/stdc++.h>
using namespace std;
long long m, r, up, down;
double ans = 0, x = sqrt(2);
void done(long long now) {
  if (now == 0) return;
  ans += x;
  --now;
  if (now == 0) return;
  ans += x * now * 2;
  ans += now * (now - 1);
}
int main() {
  int i, j;
  scanf("%I64d%I64d", &m, &r);
  for (i = 1; i <= m; ++i) {
    done(i - 1);
    done(m - i);
  }
  ans = ans / m / m;
  ans += 2.000;
  printf("%.9lf", ans * m);
  return 0;
}
