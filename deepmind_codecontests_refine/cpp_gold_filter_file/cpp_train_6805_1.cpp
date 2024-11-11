#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  int ans1, ans2;
  while (cin >> m >> n) {
    if (m == n) {
      ans1 = m - 1;
      ans2 = n;
    } else if (m < n) {
      ans1 = n - 1;
      ans2 = m;
    } else if (m > n) {
      ans1 = m - 1;
      ans2 = n;
    }
    printf("%d %d\n", ans1, ans2);
  }
  return 0;
}
