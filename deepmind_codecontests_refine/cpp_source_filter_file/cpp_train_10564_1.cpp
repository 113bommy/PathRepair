#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
int k, n, m;
int a[N];
bool f[N];
int t[N], r[N];
vector<int> v[N];
int cnt[N];
int ps;
int mndelt;
set<int> st;
void clear() {
  fill(f, f + n + 1, 0);
  fill(cnt, cnt + m, 0);
  for (int i = 1; i <= n; ++i) {
    v[i].clear();
  }
  st.clear();
}
bool check(int i) {
  if (f[i]) return 1;
  if (ps == -1) {
    if (cnt[m - 1] + v[i].size() >= a[i]) return 1;
    return 0;
  }
  if (st.count(i)) {
    if (cnt[ps] + v[i].size() >= a[i]) {
      return 1;
    }
  }
  int rest = cnt[m - 1] - mndelt;
  if (rest + v[i].size() >= a[i]) return 1;
  return 0;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      st.insert(i);
    }
    for (int i = 1; i < m; ++i) {
      scanf("%d%d", t + i, r + i);
      cnt[i] = cnt[i - 1] + (t[i] == 0);
      v[t[i]].push_back(i);
    }
    ps = -1;
    for (int i = 1; i < m; ++i) {
      if (r[i] == 1) {
        ps = i;
        break;
      }
    }
    if (ps != -1) {
      for (int i = m - 1; i >= ps; --i) {
        if (t[i]) {
          st.erase(t[i]);
        }
      }
      mndelt = INF;
      for (auto i : st) {
        mndelt = min(a[i] - (int)v[i].size(), mndelt);
      }
      mndelt = max(0, mndelt);
      for (auto i : st) {
        if (mndelt == a[i] - v[i].size()) f[i] = 1;
      }
    }
    for (int i = 1; i <= n; ++i) {
      putchar(check(i) ? 'Y' : 'N');
    }
    putchar('\n');
    clear();
  }
  return 0;
}
