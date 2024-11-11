#include <bits/stdc++.h>
using namespace std;
int main() {
  int _;
  for (cin >> _; _; _--) {
    long long n;
    scanf("%d", &n);
    long long h;
    int ans = 0;
    while (n >= 2) {
      h = (sqrt(1.0 + 24.0 * n) - 1.0) / 6.0;
      n = n - (h * (h + 1) + h * (h - 1) / 2);
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
