#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double t = 0, ans = 0, x;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    ans += x * (t * 2 + 1);
    t = x * (t + 1);
  }
  printf("%10.lf\n", ans);
  return 0;
}
