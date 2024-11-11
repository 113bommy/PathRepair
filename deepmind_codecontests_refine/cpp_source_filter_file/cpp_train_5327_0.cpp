#include <bits/stdc++.h>
using namespace std;
int q;
int n, s, t;
int ans;
int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d%d", &n, &s, &t);
    if (n > s || n > t) {
      ans = min(s, t) + 1;
    }
    if (n <= s && n <= t) {
      ans = 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
