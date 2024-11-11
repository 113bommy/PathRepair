#include <bits/stdc++.h>
using namespace std;
long long arr[1000000], dp[1000000], dp1[100000], dp2[100000], dpp1[100000],
    dpp2[100000], seg[1000000];
long long build(long long in, long long l, long long r) {
  if (l == r) {
    seg[in] = l;
    return dp[l];
  }
  long long mid = (l + r) / 2;
  if (build(in * 2 + 1, l, mid) < build(in * 2 + 2, mid + 1, r)) {
    seg[in] = seg[in * 2 + 2];
    return dp[seg[in]];
  } else {
    seg[in] = seg[in * 2 + 1];
    return dp[seg[in]];
  }
}
long long query(long long in, long long l, long long r, long long ql,
                long long qr) {
  if (l > qr || r < ql) {
    return -1;
  }
  if (l >= ql && r <= qr) {
    return seg[in];
  }
  long long mid = (l + r) / 2;
  long long rl = query(in * 2 + 1, l, mid, ql, qr),
            rr = query(in * 2 + 2, mid + 1, r, ql, qr);
  if (rl == -1) return rr;
  if (rr == -1) return rl;
  if (dp[rl] < dp[rr]) return rr;
  return rl;
}
int main() {
  ios::sync_with_stdio(0);
  long long n, c2 = 0, c1 = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] == 2)
      c2++;
    else
      c1++;
    dp[i] = c2;
    dp2[i] = c2;
    dpp1[i] = c1;
  }
  c2 = c1 = 0;
  for (int i = n - 1; i >= 0; i--) {
    dp[i] += c1;
    if (arr[i] == 1)
      c1++;
    else
      c2++;
    dp1[i] = c1;
    dpp2[i] = c2;
  }
  build(0, 0, n - 1);
  long long ans = dpp2[0];
  for (int i = 0; i < n; i++) ans = max(ans, dpp1[i] + dpp2[i + 1]);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (i != 0)
        ans = max(ans, dp[query(0, 0, n - 1, i, j)] - dp2[i - 1] - dp1[j + 1] +
                           dpp1[i - 1] + dpp2[j + 1]);
      else
        ans = max(ans, dp[query(0, 0, n - 1, i, j)] - dp1[j + 1] + dpp2[j + 1]);
    }
  }
  cout << ans;
}
