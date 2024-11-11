#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int x;
      scanf("%d", &x);
      if (i == j) {
        ans += x;
      }
    }
  ans %= 2;
  int q;
  cin >> q;
  while (q--) {
    int typ, num;
    scanf("%d", &typ);
    if (typ == 1 or typ == 2) {
      scanf("%d", &num);
      ans = !ans;
    } else {
      printf("%d", ans);
    }
  }
}
