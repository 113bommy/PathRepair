#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int M = 200000;
const int nmax = 200010;
const int MOD = (1e9) + 7;
int a[nmax], fq[nmax];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) fq[a[i]]++;
  for (int i = 1; i <= M; i++) fq[i] = fq[i - 1] + fq[i];
  long long int ans = 0;
  for (int i = 1; i <= n; i++) {
    int p = 0;
    int x = a[i];
    while (x > 0) {
      x /= 2;
      p++;
    }
    ans += p;
  }
  for (int i = 1; i <= M; i++) {
    long long int cur_ans = 0;
    int sol = 0;
    for (int it = 0, sz = 1, j = i; j <= M; it++, j *= 2, sz *= 2) {
      int nn = fq[j + sz - 1] - fq[j - 1];
      if (sol + nn >= k) {
        cur_ans = cur_ans + 1LL * (k - sol) * it;
        ans = min(ans, cur_ans);
        break;
      } else {
        cur_ans = cur_ans + 1LL * nn * it;
        sol += nn;
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
