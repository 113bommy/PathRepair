#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cc, ans = 0;
  scanf("%d", &n);
  for (int i = 2; i < n; i++) {
    long long a = 1;
    cc = 1;
    for (int j = 1; j < n - 1; j++) {
      a = (a * i) % n;
      if (a == 1) {
        cc = 0;
        break;
      }
    }
    a = (a * i) % n;
    if (a == 1) cc = 0;
    if (cc) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
