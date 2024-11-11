#include <bits/stdc++.h>
using namespace std;
char _;
const int maxN = 200 * 1000 + 5;
const int mod = 1000 * 1000 * 1000 + 7;
const int base = 701;
const int SQ = 600;
const int maxL = 302;
int seg[4 * maxN];
void add(int p, int val, int s, int e, int ind) {
  seg[ind] = (1LL) * seg[ind] * val % mod;
  if (e - s == 1) return;
  int mid = (s + e) >> 1;
  if (p < mid)
    add(p, val, s, mid, 2 * ind);
  else
    add(p, val, mid, e, 2 * ind + 1);
}
int get(int l, int r, int s, int e, int ind) {
  if (l >= e || r <= s) return 1;
  if (l <= s && e <= r) return seg[ind];
  int mid = (s + e) >> 1;
  return (1LL) * get(l, r, s, mid, 2 * ind) * get(l, r, mid, e, 2 * ind + 1) %
         mod;
}
int power(int n, int k) {
  if (k == 0) return 1;
  int ans = power(n, k / 2);
  ans = (1LL) * ans * ans % mod;
  if (k & 1) ans = (1LL) * ans * n % mod;
  return ans;
}
int a[maxN];
int las[5 * maxN];
int cur[5 * maxN];
vector<pair<int, int> > que[maxN];
int ans[maxN];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 4 * maxN; i++) seg[i] = 1;
  for (int i = 2; i < 5 * maxN; i++)
    if (las[i] == 0)
      for (int j = i; j < 5 * maxN; j += i) las[j] = i;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    que[r].push_back({l, i});
  }
  memset(cur, -1, sizeof cur);
  for (int i = 0; i < n; i++) {
    int tmp = a[i];
    while (tmp > 1) {
      int xx = las[tmp], cnt = 0;
      while (tmp % xx == 0) tmp /= xx, cnt++;
      if (cur[xx] > -1) {
        int tt = (1LL) * xx * power(xx - 1, mod - 2) % mod;
        add(cur[xx], tt, 0, n, 1);
      }
      int tt = (1LL) * (xx - 1) * power(xx, cnt - 1) % mod;
      add(i, tt, 0, n, 1);
      cur[xx] = i;
    }
    for (int j = 0; j < (int)que[i].size(); j++)
      ans[que[i][j].second] = get(que[i][j].first, i + 1, 0, n, 1);
  }
  for (int i = 0; i < q; i++) cout << ans[i] << endl;
  return 0;
}
