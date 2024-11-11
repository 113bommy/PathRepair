#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000100;
int tin[MAXN], tout[MAXN], a[MAXN];
int d[8 * MAXN], p[8 * MAXN];
vector<int> g[MAXN];
inline void push(int v, int l, int r) {
  d[v] += p[v];
  if (l != r) {
    p[v << 1] += p[v];
    p[v << 1 | 1] += p[v];
  }
  p[v] = 0;
}
void update(int v, int l, int r, int ql, int qr, const int &val) {
  push(v, l, r);
  if (l == ql && r == qr) {
    p[v] += val;
    push(v, l, r);
    return;
  }
  int mid = l + r >> 1;
  if (mid >= qr)
    update(v << 1, l, mid, ql, qr, val);
  else if (mid < ql)
    update(v << 1 | 1, mid + 1, r, ql, qr, val);
  else {
    update(v << 1, l, mid, ql, mid, val);
    update(v << 1 | 1, mid + 1, r, mid + 1, qr, val);
  }
  d[v] = max(d[v << 1] + p[v << 1], d[v << 1 | 1] + p[v << 1 | 1]);
}
int pos = 0;
void dfs(int v) {
  tin[v] = pos++;
  for (auto to : g[v]) dfs(to);
  tout[v] = pos;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  stack<int> st;
  for (int i = 1; i <= n; i++) {
    while (!st.empty() && a[st.top()] < a[i]) {
      g[i].push_back(st.top());
      st.pop();
    }
    st.push(i);
  }
  while (!st.empty()) {
    g[0].push_back(st.top());
    st.pop();
  }
  dfs(0);
  for (int i = 1; i <= k; i++) {
    update(1, 0, pos, tin[i], tout[i] - 1, 1);
  }
  for (int i = k; i <= n; i++) {
    cout << d[1] + p[1] << ' ';
    if (i != n) {
      update(1, 0, pos, tin[i + 1], tout[i + 1] - 1, +1);
      update(1, 0, pos, tin[i - k + 1], tout[i - k + 1] - 1, -1);
    }
  }
}
