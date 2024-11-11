#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
long long mod1 = 1e9 + 7;
const int maxL = 22;
const int maxn = 1e5 + 100;
const int baze = 330;
int data[2][4 * maxn + 10];
void add(int seg, int pos, int val, int st = 0, int en = maxn, int id = 1) {
  data[seg][id] = max(data[seg][id], val);
  if (en - st < 2) return;
  int mid = (st + en) >> 1;
  if (pos < mid)
    return add(seg, pos, val, st, mid, id << 1);
  else
    return add(seg, pos, val, mid, en, id << 1 ^ 1);
}
int get(int seg, int l, int r, int st = 0, int en = maxn, int id = 1) {
  if (l <= st && en <= r) return data[seg][id];
  if (r <= st || en <= l) return 0;
  int mid = (st + en) >> 1;
  return max(get(seg, l, r, st, mid, id << 1),
             get(seg, l, r, mid, en, id << 1 ^ 1));
}
int n;
int m;
int st[maxn], en[maxn], ar[maxn], dp[2][maxn];
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0, l, r; i < n; i++) {
    cin >> l >> r;
    st[l]++;
    en[r]++;
  }
  int cur = 0;
  for (int i = 1; i <= m; i++) {
    cur += st[i];
    ar[i - 1] = cur;
    cur -= en[i];
  }
  n = m;
  for (int i = n - 1; i >= 0; i--) {
    dp[0][i] = max(get(0, ar[i], maxn) + 1, get(1, 0, ar[i]) + 1);
    dp[1][i] = get(1, 0, ar[i]) + 1;
    add(0, ar[i], dp[0][i]);
    add(1, ar[i], dp[1][i]);
  }
  int mx = 0;
  mx = max(mx, *max_element(dp[0], dp[0] + n));
  mx = max(mx, *max_element(dp[1], dp[1] + n));
  cout << mx << endl;
}
