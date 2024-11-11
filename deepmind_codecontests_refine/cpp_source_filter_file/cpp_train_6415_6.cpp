#include <bits/stdc++.h>
using namespace std;
int q;
int n;
int ans;
int main() {
  int i, j, k;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    if (n & 1) {
      n -= 9;
      ans = 1;
    } else {
      ans = 0;
    }
    if (n < 4) {
      printf("-1\n");
    } else {
      ans += n / 4;
      printf("%d\n", ans);
    }
  }
}
