#include <bits/stdc++.h>
using namespace std;
using namespace std;
void solve() {
  int a, b, c;
  int s;
  scanf("%d", &s);
  scanf("%d%d%d", &a, &b, &c);
  int sum = a + b + c;
  if (sum == 0) {
    printf("%d 0 0\n", s);
  } else {
    double k = (double)s / sum;
    printf("%.7lf %.7lf %.7lf\n", k * a, k * b, k * c);
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
