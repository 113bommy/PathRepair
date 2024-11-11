#include <bits/stdc++.h>
using namespace std;
const int mx = 1000010;
int a[mx];
int main() {
  int i, j, k, n;
  while (scanf("%d", &n) == 1) {
    memset(a, 0, sizeof a);
    for (i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      a[x]++;
    }
    int ans = 0;
    for (i = 0; i < mx - 1; i++) {
      a[i + 1] += (a[i] / 2);
      a[i] %= 2;
      ans += a[i];
    }
    cout << ans << endl;
  }
}
