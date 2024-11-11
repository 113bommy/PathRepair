#include <bits/stdc++.h>
using namespace std;
int t;
int a, b, c;
int aa, bb, cc;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &a, &b, &c);
    int ans = 1e9;
    for (int i = 1; i <= 10000; i++) {
      for (int j = i; j <= 10000; j += i) {
        for (int k = j; k <= 10000; k += j) {
          int cost = abs(i - a) + abs(j - b) + abs(k - c);
          if (ans > cost) {
            aa = i, bb = j, cc = k;
            ans = cost;
          }
        }
      }
    }
    printf("%d\n", ans);
    printf("%d %d %d\n", aa, bb, cc);
  }
  return 0;
}
