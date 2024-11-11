#include <bits/stdc++.h>
using namespace std;
int n, t, k1, k2, max1, max2, r, k, sum, temp, cnt, ok, m, q, ask, p, x, w, l,
    ans, kk, maxx;
int a[400010], b[400010];
vector<int> v;
string s;
void solve() {
  cin >> n >> l;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back(a[i]);
  }
  k = l * 8 / n;
  if (k >= 800) {
    puts("0");
    return;
  }
  kk = (int)pow(2, k);
  sort(v.begin(), v.end());
  cnt = unique(v.begin(), v.end()) - v.begin();
  for (int i = 1; i <= n; i++) {
    temp = lower_bound(v.begin(), v.begin() + cnt, a[i]) - v.begin();
    b[temp]++;
    maxx = max(maxx, temp);
  }
  if (maxx)
    for (int i = 1; i <= maxx; i++) b[i] = b[i] + b[i - 1];
  if (maxx < kk) {
    puts("0");
    return;
  }
  ans = n - b[kk - 1];
  for (int i = kk; i <= maxx; i++) {
    ans = min(ans, n - (b[i] - b[i - kk]));
  }
  cout << ans << endl;
  return;
}
int main() {
  solve();
  return 0;
}
