#include <bits/stdc++.h>
using namespace std;
int inf = 1e9;
int mod = 1e9 + 7;
double eps = 1e-9;
int dr[] = {-1, 0, 0, 1};
int dc[] = {0, 1, -1, 0};
int rng(int l, int r) {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<int>(l, r)(rng);
}
int main() {
  int t, n, m, i, j;
  cin >> n >> m;
  vector<int> a(n), b(m), sa(n + 10, 0), sb(m + 10, 0);
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (i) sa[i] = sa[i - 1] + a[i - 1];
  }
  sa[i] = sa[i - 1] + a[i - 1];
  for (i = 0; i < m; i++) {
    cin >> b[i];
    if (i) sb[i] = sb[i - 1] + b[i - 1];
  }
  sb[i] = sb[i - 1] + b[i - 1];
  long long int x;
  cin >> x;
  vector<int> mxa(n + 2, inf), mxb(m + 2, inf);
  for (i = 0; i < n; i++)
    for (j = i; j < n; j++)
      mxa[j - i + 1] = min(mxa[j - i + 1], sa[j + 1] - sa[i]);
  for (i = 0; i < m; i++)
    for (j = i; j < m; j++)
      mxb[j - i + 1] = min(mxb[j - i + 1], sb[j + 1] - sa[i]);
  int ans = 0;
  for (i = 0; i < mxa.size(); i++)
    for (j = 0; j < mxb.size(); j++)
      if (mxb[j] * 1ll * mxa[i] <= x) ans = max(ans, j * i);
  cout << ans;
  return 0;
}
