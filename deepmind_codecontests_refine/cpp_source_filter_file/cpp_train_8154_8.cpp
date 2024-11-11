#include <bits/stdc++.h>
using namespace std;
long long a[31][31], b[31], k[31], p[31];
long long n, u, r, ans;
void update(int done, int total, int flag) {
  if ((total - done) % 2 == 0) {
    long long sum = 0;
    for (long long i = 1; i <= n; i++) sum += a[done][i] * k[i];
    ans = max(ans, sum);
  }
  if (done == total) return;
  for (long long i = 1; i <= n; i++) a[done + 1][i] = (a[done][p[i]] + r);
  update(done + 1, total, 0);
  if (!flag) {
    for (long long i = 1; i <= n; i++) a[done + 1][i] = (a[done][i] ^ b[i]);
    update(done + 1, total, 1);
  }
}
int main() {
  cin >> n >> u >> r;
  for (long long i = 1; i <= n; i++) cin >> a[0][i];
  for (long long i = 1; i <= n; i++) cin >> b[i];
  for (long long i = 1; i <= n; i++) cin >> k[i];
  for (long long i = 1; i <= n; i++) cin >> p[i];
  ans = 0;
  update(0, u, 0);
  cout << ans << endl;
  return 0;
}
