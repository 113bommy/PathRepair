#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  long long x, y;
  long long x2, y2;
  int n;
  scanf("%lld%lld", &x, &y);
  scanf("%lld%lld", &x2, &y2);
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a * x + b * x + c > 0 && a * x2 + b * x2 + c < 0)
      cnt++;
    else if (a * x + b * x + c < 0 && a * x2 + b * x2 + c > 0)
      cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
