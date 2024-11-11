#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int N = 0;
int n, xa, xb, ya, yb;
int main() {
  scanf("%d", &n);
  int ans = 0;
  while (n--) {
    scanf("%d%d%d%d", &xa, &xb, &ya, &yb);
    ans += (xb - xa + 1) * (yb - ya + 1);
  }
  cout << ans;
}
