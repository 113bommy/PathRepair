#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const double eps = 1e-9;
bool up[N];
int main() {
  int n, pos;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &pos);
    up[pos] = true;
  }
  double a_min = 10, a_max = 2e9;
  int cnt = 1;
  for (int i = 1; i <= pos; i++) {
    if (up[i])
      a_max = min(a_max, 10.0 * (i + 1) / cnt - eps);
    else
      a_min = max(a_min, 10.0 * (i + 1) / cnt);
    cnt += up[i];
  }
  double L_min = a_min * cnt - 10 * pos;
  double L_max = a_max * cnt - 10 * pos;
  int p_min = pos + (int)L_min / 10;
  int p_max = pos + (int)L_max / 10;
  if (p_min == p_max)
    printf("unique\n%d\n", p_min);
  else
    puts("not unique");
  return 0;
}
