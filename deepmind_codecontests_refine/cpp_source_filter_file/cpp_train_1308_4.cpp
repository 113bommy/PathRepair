#include <bits/stdc++.h>
using namespace std;
int crush[105];
int n;
int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
int main() {
  int i, j, k;
  int ans = 1;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &crush[i]);
  }
  for (i = 1; i <= n; i++) {
    int p = 0, w = i;
    for (j = 1; j <= 100 + 5; j++) {
      w = crush[w];
      if (w == i) {
        p = j;
        break;
      }
    }
    if (!p) {
      printf("-1\n");
      return 0;
    } else if (p & 1) {
      ans = ans * p / gcd(ans, p);
    } else {
      ans = ans * (p >> 1) / gcd(ans, (p >> 1));
    }
  }
  cout << ans << endl;
  return 0;
}
