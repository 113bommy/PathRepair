#include <bits/stdc++.h>
using namespace std;
long long n, res, a[1 << 17], S[1 << 17], mx, mi;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%lld", a + i);
  for (int i = 1; i < n; i++) {
    S[i] = S[i - 1] + abs(a[i] - a[i + 1]) * (i & 1 ? 1 : -1);
    res = max(res, max(mx - S[i], S[i] - mi)),
    i& 1 ? mx = max(mx, S[i]) : mi = min(mi, S[i]);
  }
  cout << res << endl;
}
