#include <bits/stdc++.h>
using namespace std;
template <class T, class L>
bool smax(T &x, L y) {
  return x < y ? (x = y, 1) : 0;
}
template <class T, class L>
bool smin(T &x, L y) {
  return x > y ? (x = y, 1) : 0;
}
const int maxn = 10500 + 17, maxk = 1e3 + 17, mod = 1e9 + 7, base = 1e7 + 19,
          lg = 17, maxq = 3e4 + 17;
vector<int> iman[maxq << 2];
int n, k, nq, q, dp[lg][maxk], w[maxn], v[maxn], ans[maxq], po[maxk];
void majid(int st, int en, int idx, int l = 0, int r = q, int id = 1) {
  if (st <= l && r <= en) {
    iman[id].push_back(idx);
    return;
  }
  if (en <= l || r <= st) return;
  int mid = l + r >> 1;
  majid(st, en, idx, l, mid, id << 1), majid(st, en, idx, mid, r, id << 1 | 1);
}
void hamid(int l = 0, int r = q, int id = 1, int h = 1) {
  memcpy(dp[h], dp[h - 1], sizeof dp[h]);
  for (auto idx : iman[id])
    for (int wi = k - w[idx]; wi >= 0; wi--)
      smax(dp[h][wi + w[idx]], dp[h][wi] + v[idx]);
  partial_sum(dp[h], dp[h] + k + 1, dp[h],
              [](int &x, int &y) { return max(x, y); });
  if (r - l < 2) {
    for (int i = 1; i <= k; i++)
      ans[l] = (ans[l] + (long long)po[i - 1] * dp[h][i]) % mod;
    return;
  }
  int mid = l + r >> 1;
  hamid(l, mid, id << 1, h + 1), hamid(mid, r, id << 1 | 1, h + 1);
}
int st[maxn], en[maxn];
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> v[i] >> w[i];
  po[0] = 1;
  for (int i = 1; i <= k; i++) po[i] = (long long)po[i - 1] * base % mod;
  memset(en, 63, sizeof en);
  cin >> nq;
  for (int t, x; nq--;) {
    cin >> t;
    if (t == 1)
      cin >> v[n] >> w[n], st[n++] = q;
    else if (t == 2)
      cin >> x, en[x - 1] = q;
    else
      q++;
  }
  for (int i = 0; i < n; i++) majid(st[i], min(q, en[i]), i);
  hamid();
  for (int i = 0; i < q; i++) cout << ans[i] << '\n';
  return 0;
}
