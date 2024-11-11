#include <bits/stdc++.h>
using namespace std;
int n, a, b, t;
int lr[500010];
int rl[500010];
char ori[500010];
int bslr(int k) {
  int curt = t;
  curt -= lr[k];
  if (curt < 0) return 0;
  curt -= a * (k - 1);
  if (curt <= 0) return k;
  int r = n + 1;
  int l = k + 1;
  int finalPos = n + 1;
  while (l <= r) {
    int mid = (r + l) >> 1;
    if (rl[mid] > curt) {
      l = mid + 1;
    } else {
      finalPos = mid;
      r = mid - 1;
    }
  }
  return k + (n + 1 - finalPos);
}
int ans = 0;
void solve() {
  lr[0] = -a;
  for (int i = 1; i <= n; i++) {
    lr[i] = lr[i - 1];
    lr[i] += a + 1;
    if (ori[i] == 'w') {
      lr[i] += b;
    }
  }
  rl[n + 1] = lr[1];
  for (int i = n; i > 1; i--) {
    rl[i] = rl[i + 1];
    rl[i] += a + 1;
    if (ori[i] == 'w') {
      rl[i] += b;
    }
  }
  rl[n + 1] = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, bslr(i));
  }
}
int main() {
  cin >> n >> a >> b >> t;
  scanf("%s", ori + 1);
  solve();
  reverse(ori + 2, ori + n + 1);
  solve();
  cout << ans << endl;
  return 0;
}
