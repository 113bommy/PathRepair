#include <bits/stdc++.h>
using namespace std;
deque<pair<int, int> > maxq;
deque<pair<int, int> > minq;
void pushmax(pair<int, int> element) {
  while (!maxq.empty() && element > maxq.back()) maxq.pop_back();
  maxq.push_back(element);
}
void pushmin(pair<int, int> element) {
  while (!minq.empty() && element < minq.back()) minq.pop_back();
  minq.push_back(element);
}
int st[4 * 100050];
int query(int node, int ll, int rl, int ql, int qr) {
  if (ll >= ql && rl <= qr)
    return st[node];
  else if (rl < ql || ll > qr)
    return 1e9;
  int left = query(2 * node + 1, ll, (ll + rl) / 2, ql, qr);
  int right = query(2 * node + 2, (ll + rl) / 2 + 1, rl, ql, qr);
  return min(left, right);
}
int update(int node, int ll, int rl, int q, int val) {
  if (rl < q || ll > q) return st[node];
  if (q == ll && q == rl)
    st[node] = val;
  else {
    int left = update(2 * node + 1, ll, (ll + rl) / 2, q, val);
    int right = update(2 * node + 2, (ll + rl) / 2 + 1, rl, q, val);
    st[node] = min(left, right);
  }
  return st[node];
}
int main() {
  int n, s, l;
  cin >> n >> s >> l;
  int a[100050], g[100050];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    pushmax(make_pair(a[i], n - i));
    pushmin(make_pair(a[i], i));
    g[i] = g[i - 1];
    while (!maxq.empty() && !minq.empty() &&
           maxq.front().first - minq.front().first > s) {
      pair<int, int> maxx = maxq.front(), minn = minq.front();
      if (n - maxx.second > minn.second) {
        g[i] = minn.second + 1;
        minq.pop_front();
      } else {
        g[i] = n - maxx.second + 1;
        maxq.pop_front();
      }
    }
  }
  int maxl = 0, minl = INT_MAX;
  for (int i = 0; i < l; i++) {
    minl = min(a[i], minl);
    maxl = max(a[i], maxl);
  }
  if (maxl - minl > s) {
    cout << -1 << endl;
    return 0;
  }
  int dp[100050];
  for (int i = 0; i < n; i++) dp[i] = 1e9;
  for (int i = 0; i < 4 * n; i++) st[i] = 1e9;
  dp[l - 1] = 1;
  update(0, 0, n - 1, l - 1, dp[l - 1]);
  for (int i = l; i < n; i++) {
    dp[i] = 1e9;
    if (g[i] - 1 <= i - l) {
      int qr = query(0, 0, n - 1, g[i] - 1, i - l);
      if (g[i] == 0) qr = 0;
      if (qr != 1e9) dp[i] = qr + 1;
    }
    update(0, 0, n - 1, i, dp[i]);
  }
  if (dp[n - 1] == 1e9)
    cout << -1 << endl;
  else
    cout << dp[n - 1] << endl;
}
