#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
  int n, m, k, i;
  cin >> m >> n >> k;
  for (i = 0; i < n; i++) cin >> a[i];
  int cap = 0, boxes = 0, ans = 0;
  for (i = n - 1; i >= 0; i--) {
    if (cap < a[i]) {
      boxes++;
      cap = k;
    }
    if (boxes > m) break;
    ans++;
    cap -= a[i];
  }
  cout << ans << endl;
  return 0;
}
