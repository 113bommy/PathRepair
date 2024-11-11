#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535897;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    double ans = ((pi) / (2.0 * n));
    printf("%.10lf\n", 1.0 / (sin(ans) / cos(ans / 2.0)));
  }
  return 0;
}
