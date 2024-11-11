#include <bits/stdc++.h>
using namespace std;
char orient[500010];
int fwd[500010], bwd[500010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, i, j, k, temp, t, m, a, b, T, final = 0;
  cin >> n >> a >> b >> T;
  cin >> orient;
  fwd[1] = 0;
  bwd[1] = 0;
  T--;
  if (orient[0] == 'w') T -= b;
  if (T >= 0) final = 1;
  for (i = 2; i <= n; i++) {
    if (orient[i - 1] == 'w') fwd[i] = b;
    fwd[i] += fwd[i - 1] + a + 1;
  }
  for (i = n; i >= 2; i--) {
    if (orient[i - 1] == 'w') bwd[i] = b;
    bwd[i] += bwd[(i + 1) % (n + 1)] + a + 1;
  }
  int ans = 0, l = 2;
  for (i = 1; i <= n; i++) {
    ans = 0;
    if (fwd[i] <= T) ans = i;
    temp = fwd[i] + a * (i - 1);
    temp = T - temp;
    while (bwd[l] > temp && l <= n) {
      l++;
    }
    ans += n - l + 1;
    final = max(ans, final);
  }
  ans = 0;
  int r = n;
  for (i = n; i >= 2; i--) {
    ans = 0;
    if (bwd[i] <= T) ans = n - i + 1;
    temp = bwd[i] + a * (n - i + 1);
    temp = T - temp;
    while (fwd[r] > temp && r > 1) {
      r--;
    }
    ans += r - 1;
    final = max(ans, final);
  }
  cout << min(final, n) << '\n';
  return 0;
}
