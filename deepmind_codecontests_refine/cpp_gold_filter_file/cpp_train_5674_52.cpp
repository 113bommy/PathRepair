#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, x, y, z, ans2, ans;
int ans1[101];
int main() {
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    y = -1;
    for (j = 1; j <= n; j++) {
      cin >> x;
      if (x > y) {
        y = x;
        z = j;
      }
    }
    ans1[z]++;
  }
  for (i = 1; i <= 101; i++) {
    if (ans1[i] > ans2) {
      ans2 = ans1[i];
      ans = i;
    }
  }
  cout << ans << endl;
}
