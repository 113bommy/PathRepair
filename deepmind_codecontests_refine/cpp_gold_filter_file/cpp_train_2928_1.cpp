#include <bits/stdc++.h>
using namespace std;
const long long SIZE = 5228;
const long long INF = 1e14;
vector<vector<long long>> t(2);
void change(long long id, long long v, long long l, long long r, long long pos,
            long long val) {
  if (l == r - 1) {
    t[id][v] = val;
    return;
  }
  long long m = (l + r) / 2;
  if (pos < m) {
    change(id, 2 * v + 1, l, m, pos, val);
  } else {
    change(id, 2 * v + 2, m, r, pos, val);
  }
  t[id][v] = max(t[id][2 * v + 1], t[id][2 * v + 2]);
}
long long ask(long long id, long long v, long long l, long long r,
              long long askl, long long askr) {
  if (l >= askr || r <= askl) {
    return -INF;
  }
  if (l >= askl && r <= askr) {
    return t[id][v];
  }
  long long m = (l + r) / 2;
  return max(ask(id, 2 * v + 1, l, m, askl, askr),
             ask(id, 2 * v + 2, m, r, askl, askr));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, k, x;
  cin >> n >> k >> x;
  long long cnt = 1;
  long long last = k - 1;
  for (long long i = last + 1; i < n; ++i) {
    if (i - last == k) {
      cnt++;
      last = i;
    }
  }
  if (cnt > x) {
    cout << -1 << endl;
    return 0;
  }
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<long long>> dp(n, vector<long long>(x + 1));
  t[0].assign(4 * n, 0);
  t[1].assign(4 * n, 0);
  for (long long q = 0; q < x; ++q) {
    for (long long i = 0; i < n; ++i) {
      if (q == 0) {
        if (i <= k - 1) {
          dp[i][q] = a[i];
        } else {
          dp[i][q] = -INF;
        }
      } else {
        dp[i][q] = ask(0, 0, 0, n, max(0ll, i - k), i) + a[i];
      }
      change(1, 0, 0, n, i, dp[i][q]);
    }
    swap(t[0], t[1]);
    t[1].assign(4 * n, 0);
  }
  long long ans = -INF;
  for (long long i = n - k; i < n; ++i) {
    ans = max(ans, dp[i][x - 1]);
  }
  cout << ans << endl;
}
