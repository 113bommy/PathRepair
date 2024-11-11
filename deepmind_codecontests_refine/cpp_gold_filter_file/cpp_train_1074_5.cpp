#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, x, y, z, m, n;
double ans;
int ara[300];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) cin >> ara[i];
  sort(ara, ara + n);
  if (n % 2 == 0) {
    for (i = 1; i < n; i += 2) {
      ans += acos(-1) * (ara[i] * ara[i] - ara[i - 1] * ara[i - 1]);
    }
  }
  if (n % 2 == 1) {
    ans += acos(-1) * (ara[0] * ara[0]);
    for (i = 2; i < n; i += 2) {
      ans += acos(-1) * (ara[i] * ara[i] - ara[i - 1] * ara[i - 1]);
    }
  }
  printf("%.10lf", ans);
  return 0;
}
