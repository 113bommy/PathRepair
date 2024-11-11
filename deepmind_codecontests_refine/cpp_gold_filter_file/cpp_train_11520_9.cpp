#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
vector<int> val[100010];
int x[100010];
int td[100010 * 4], ti[100010 * 4];
int queryd(int node, int lo, int hi, int l, int r) {
  if (l > hi or r < lo) return 0;
  if (lo >= l and hi <= r) return td[node];
  int md = (lo + hi) >> 1;
  int p1 = queryd(node << 1, lo, md, l, r);
  int p2 = queryd(node << 1 | 1, md + 1, hi, l, r);
  return max(p1, p2);
}
void updated(int node, int lo, int hi, int idx, int val) {
  if (lo == hi) {
    td[node] = max(td[node], val);
    return;
  }
  int md = (lo + hi) >> 1;
  if (idx <= md)
    updated(node << 1, lo, md, idx, val);
  else
    updated(node << 1 | 1, md + 1, hi, idx, val);
  td[node] = max(td[node << 1], td[node << 1 | 1]);
}
int queryi(int node, int lo, int hi, int l, int r) {
  if (l > hi or r < lo) return 0;
  if (lo >= l and hi <= r) return ti[node];
  int md = (lo + hi) >> 1;
  int p1 = queryi(node << 1, lo, md, l, r);
  int p2 = queryi(node << 1 | 1, md + 1, hi, l, r);
  return max(p1, p2);
}
void updatei(int node, int lo, int hi, int idx, int val) {
  if (lo == hi) {
    ti[node] = max(ti[node], val);
    return;
  }
  int md = (lo + hi) >> 1;
  if (idx <= md)
    updatei(node << 1, lo, md, idx, val);
  else
    updatei(node << 1 | 1, md + 1, hi, idx, val);
  ti[node] = max(ti[node << 1], ti[node << 1 | 1]);
}
int ai[100010], ad[100010], md[100010];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0, l, r; i < n; ++i) {
    cin >> l >> r;
    x[l]++;
    x[r + 1]--;
  }
  for (int i = 1; i <= m; ++i) {
    x[i] += x[i - 1];
  }
  for (int i = 1; i <= m; ++i) {
    auto xz = queryi(1, 0, n, 0, x[i]);
    ai[i] = xz + 1;
    updatei(1, 0, n, x[i], xz + 1);
  }
  for (int i = m; i > 0; --i) {
    auto xz = queryd(1, 0, n, 0, x[i]);
    ad[i] = xz + 1;
    updated(1, 0, n, x[i], xz + 1);
  }
  md[m] = ad[m];
  int ans = 0;
  for (int i = m - 1; i > 0; --i) {
    md[i] = max(ad[i], md[i + 1]);
  }
  for (int i = 1; i < m; ++i) {
    ans = max(ans, ai[i] + md[i + 1]);
  }
  cout << ans << endl;
}
