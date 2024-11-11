#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 10;
const int maxv = 1e3 + 10;
const double eps = 1e-9;
int n, k;
int getSg(int num) {
  if (k & 1) {
    if (num == 1) return 1;
    if (num == 2) return 0;
    if (num == 3) return 1;
    if (num == 4) return 2;
    if (num & 1) return 0;
    int t = getSg(num / 2);
    if (t == 2) return 1;
    return 2;
  } else {
    if (num == 1) return 1;
    if (num == 2) return 2;
    if (num & 1) return 0;
    return 1;
  }
}
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      x = getSg(x);
      ans ^= x;
    }
    if (ans)
      puts("Kevin");
    else
      puts("Nicky");
  }
  return 0;
}
