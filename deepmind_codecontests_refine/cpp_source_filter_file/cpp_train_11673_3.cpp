#include <bits/stdc++.h>
using namespace std;
int s[1005];
int main() {
  int n, m, sum, i, j, h;
  cin >> n >> m >> h;
  sum = 0;
  for (i = 1; i <= m; i++) {
    scanf("%d", s + i);
    sum += s[i];
  }
  if (sum < n) {
    puts("-1.0");
    return 0;
  }
  if (s[h] == 1) {
    puts("0.0");
    return 0;
  }
  if (sum == n) {
    puts("1.0");
    return 0;
  }
  double ans = 1;
  j = 1;
  for (i = sum - n - s[h] + 2; i <= sum - n; i++) {
    ans *= i;
    double t = (sum - j);
    ans /= t;
  }
  printf("%.10lf\n", 1 - ans);
}
