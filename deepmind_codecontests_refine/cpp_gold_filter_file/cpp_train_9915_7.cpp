#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 100;
int a[M], cnt[M];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  fill(cnt, cnt + M, 0);
  for (int i = 1; i <= n; i++) {
    cnt[i] += cnt[i - 1];
    if (a[i] > a[i - 1] and a[i] > a[i + 1]) ++cnt[i];
  }
  int mx = 1, st = 1;
  for (int i = 1; i + k - 1 <= n; i++) {
    int l = i, r = i + k - 2;
    int sub = cnt[r] - cnt[l] + 1;
    if (sub > mx) {
      mx = sub;
      st = l;
    }
  }
  cout << mx << ' ' << st << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
