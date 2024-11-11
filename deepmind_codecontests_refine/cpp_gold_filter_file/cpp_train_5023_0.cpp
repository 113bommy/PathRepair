#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int NMASK = 1 << 20;
int n;
int a[N], b[N], c[N];
int vst[N], deg[N];
vector<pair<int, int> > adj[NMASK], self_loop[NMASK];
vector<int> ans;
bool check(int ret) {
  stack<pair<int, int> > st;
  st.push(make_pair(a[1], 1));
  ans.clear();
  fill(vst + 1, vst + 1 + n, 0);
  fill(deg + 1, deg + 1 + n, 0);
  vst[1] = 1;
  while (!st.empty()) {
    pair<int, int> u = st.top();
    int fl = 0;
    while (!self_loop[u.first].empty()) {
      pair<int, int> p = self_loop[u.first].back();
      self_loop[u.first].pop_back();
      if (vst[(p.second + 1) / 2]) continue;
      fl = 1;
      vst[(p.second + 1) / 2]++;
      st.push(p);
      break;
    }
    if (!fl) {
      while (!adj[u.first].empty()) {
        pair<int, int> p = adj[u.first].back();
        adj[u.first].pop_back();
        if (vst[(p.second + 1) / 2]) continue;
        vst[(p.second + 1) / 2]++;
        st.push(p);
        break;
      }
    }
    if (!st.empty() && u == st.top()) {
      ans.push_back(u.second);
      ans.push_back(u.second + (u.second % 2 ? 1 : -1));
      st.pop();
    }
  }
  if ((int)(ans.size()) != 2 * n) return false;
  ans.push_back(ans[0]);
  for (int i = 1; i < 2 * n; i += 2)
    if (c[ans[i]] != c[ans[i + 1]] &&
        __builtin_ctz(c[ans[i]] ^ c[ans[i + 1]]) < ret)
      return false;
  ans.pop_back();
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    c[2 * i - 1] = a[i];
    c[2 * i] = b[i];
  }
  if (n == 1) {
    printf("%d\n1 2", min(20, __builtin_ctz(a[1] ^ b[1])));
    return 0;
  }
  for (int i = 20; i >= 0; i--) {
    for (int j = 1; j <= n; j++) {
      adj[a[j]].clear();
      adj[b[j]].clear();
      self_loop[a[j]].clear();
      self_loop[b[j]].clear();
    }
    for (int j = 1; j <= n; j++) {
      a[j] &= (1 << i) - 1;
      b[j] &= (1 << i) - 1;
      if (a[j] != b[j]) {
        adj[a[j]].push_back(make_pair(b[j], 2 * j));
        adj[b[j]].push_back(make_pair(a[j], 2 * j - 1));
      } else {
        self_loop[a[j]].push_back(make_pair(b[j], 2 * j));
        self_loop[b[j]].push_back(make_pair(a[j], 2 * j - 1));
      }
    }
    if (check(i)) {
      printf("%d\n", i);
      for (int x : ans) printf("%d ", x);
      break;
    }
  }
}
