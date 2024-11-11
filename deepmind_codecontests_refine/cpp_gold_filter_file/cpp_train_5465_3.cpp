#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, s, q, i, ans;
  while (scanf("%d %d %d", &t, &s, &q) == 3) {
    ans = 0;
    while (s < t) {
      s *= q;
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
