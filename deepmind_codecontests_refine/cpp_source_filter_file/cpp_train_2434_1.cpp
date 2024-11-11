#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, q, a[200001], cs[200002] = {};
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    cs[l]++;
    cs[r + 1]--;
  }
  for (int i = 1; i <= n; i++) {
    cs[i] += cs[i - 1];
  }
  sort(a, a + n);
  sort(cs, cs + n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += 1LL * a[i] * cs[i];
  cout << ans;
}
