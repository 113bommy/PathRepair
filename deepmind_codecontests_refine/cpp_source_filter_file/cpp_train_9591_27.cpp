#include <bits/stdc++.h>
using namespace std;
int a[1010];
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= (n) / 2; i++) {
    int kol1 = 0, kol2 = 0, kik = 0;
    for (int j = 1; j <= n; j++) {
      if (j == i + kik * k) {
        kik++;
        continue;
      }
      if (a[j] == 1)
        kol1++;
      else
        kol2++;
    }
    ans = max(ans, abs(kol1 - kol2));
  }
  cout << ans;
}
