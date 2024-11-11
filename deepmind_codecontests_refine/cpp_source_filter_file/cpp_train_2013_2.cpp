#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 28;
const double INF = 1e12, EPS = 1e-9;
int n, m;
vector<vector<int> > e;
int na, v[100000], ans[100000];
int st1[100000], sz1, st2[100000], sz2;
void rec(int c, int cl) {
  v[c] = 1;
  if (cl == 1)
    st1[sz1++] = c;
  else
    st2[sz2++] = c;
  for (int i = 0; i < e[c].size(); i++)
    if (!v[e[c][i]]) rec(e[c][i], 3 - cl);
}
bool func(int *s, int s_, int *t, int t_, int cnt) {
  int res[2], sz = 0;
  for (int i = 0; i < s_; i++)
    if ((int)e[s[i]].size() <= t_ - 2) {
      res[sz++] = i;
      if (sz == cnt) break;
    }
  if (sz < cnt) return 0;
  for (int i = 0; i < sz; i++) {
    ans[res[i]] = na++;
    cnt = 0;
    for (int j = 0; j < t_; j++)
      if (!binary_search((e[res[i]]).begin(), (e[res[i]]).end(), t[j])) {
        ans[t[j]] = na++;
        if (++cnt == 2) break;
      }
  }
  return 1;
}
void run() {
  memset(ans, -1, sizeof(ans));
  cin >> n >> m;
  e.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    e[--a].push_back(--b);
    e[b].push_back(a);
  }
  for (int i = 0; i < n; i++) sort((e[i]).begin(), (e[i]).end());
  for (int i = 0; i < n; i++)
    if (!v[i]) rec(i, 1);
  if (n % 3) {
    cout << "NO" << endl;
    return;
  }
  if (sz1 % 3) {
    int *s = st1, *t = st2, s_ = sz1, t_ = sz2;
    if (sz1 % 3 == 2) swap(s, t), swap(s_, t_);
    if (!func(s, s_, t, t_, 1) && !func(t, t_, s, s_, 2)) {
      cout << "NO" << endl;
      return;
    }
  }
  for (int i = 0; i < sz1; i++)
    if (ans[st1[i]] < 0) ans[st1[i]] = na++;
  for (int i = 0; i < sz2; i++)
    if (ans[st2[i]] < 0) ans[st2[i]] = na++;
  cout << "YES" << endl;
  for (int i = 0; i < n; i++)
    cout << ans[i] / 3 + 1 << (i == n - 1 ? "\n" : " ");
}
int main() { run(); }
