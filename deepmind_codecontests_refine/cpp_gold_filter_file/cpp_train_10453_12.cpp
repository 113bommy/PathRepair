#include <bits/stdc++.h>
using namespace std;
int S[100005];
int main() {
  int n, l, r, ql, qr;
  cin >> n >> l >> r >> ql >> qr;
  int w;
  for (int i = 1; i <= n; i++) scanf("%d", &w), S[i] = S[i - 1] + w;
  int ans = 0x3f0f0f0f;
  for (int i = 0; i <= n; i++) {
    int SR = S[n] - S[i], ll = n - i;
    int now = S[i] * l + SR * r;
    if (i < ll) now += qr * (ll - i - 1);
    if (i > ll) now += ql * (i - ll - 1);
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
