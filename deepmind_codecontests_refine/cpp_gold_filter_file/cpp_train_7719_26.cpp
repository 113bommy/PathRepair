#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const double Pi = acos(-1);
const double e = exp(1.0);
const int mod = 1e9 + 7;
int main() {
  int n, m, ans;
  scanf("%d%d", &n, &m);
  if (m == 1 || m == 0)
    ans = 1;
  else if (m == 2 && m > 3)
    ans = 2;
  else if (m <= n / 2)
    ans = m;
  else
    ans = n - m;
  printf("%d\n", ans);
  return 0;
}
