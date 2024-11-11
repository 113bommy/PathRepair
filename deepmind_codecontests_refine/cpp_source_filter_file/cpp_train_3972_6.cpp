#include <bits/stdc++.h>
using namespace std;
const long long NMAX = 300011;
const long long MMAX = 21111;
const long long inf = 2e9;
struct event {
  int first, second;
  int t;
} ev[NMAX * 5];
long long ans[NMAX * 5];
int ls = 1;
map<pair<int, int>, int> s;
int n = 3e5;
int p[NMAX * 2];
int cnt[NMAX * 2];
long long cntx[NMAX * 2], cnty[NMAX * 2];
int lider(int v) {
  if (p[v] == v) return v;
  return p[v];
}
long long res = 0;
void go(int tl, int tr) {
  if (tl == tr - 1) {
    if (ev[tl].t == 0) ans[tl] = res;
    return;
  }
  int m = (tl + tr) / 2;
  stack<int> st;
  for (int i = m; i < tr; i++) {
    if (ev[i].t != 0 && ev[i].t < tl) {
      int v = ev[i].first;
      int u = ev[i].second + n;
      v = lider(v);
      u = lider(u);
      if (v != u) {
        if (cnt[v] < cnt[u]) swap(u, v);
        st.push(u);
        res -= cntx[v] * cnty[v];
        res -= cntx[u] * cnty[u];
        cnt[v] += cnt[u];
        cntx[v] += cntx[u];
        cnty[v] += cnty[u];
        res += cntx[v] * cnty[v];
        p[u] = v;
      }
    }
  }
  go(tl, m);
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    int v = p[u];
    res -= cntx[v] * cnty[v];
    cntx[v] -= cntx[u];
    cnty[v] -= cnty[u];
    cnt[v] -= cnt[u];
    res += cntx[v] * cnty[v];
    res += cntx[u] * cnty[u];
    p[u] = u;
  }
  for (int i = tl; i < m; i++) {
    if (ev[i].t != 0 && ev[i].t >= tr) {
      int v = ev[i].first;
      int u = ev[i].second + n;
      v = lider(v);
      u = lider(u);
      if (v != u) {
        if (cnt[v] < cnt[u]) swap(u, v);
        st.push(u);
        res -= cntx[v] * cnty[v];
        res -= cntx[u] * cnty[u];
        cnt[v] += cnt[u];
        cntx[v] += cntx[u];
        cnty[v] += cnty[u];
        res += cntx[v] * cnty[v];
        p[u] = v;
      }
    }
  }
  go(m, tr);
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    int v = p[u];
    res -= cntx[v] * cnty[v];
    cntx[v] -= cntx[u];
    cnty[v] -= cnty[u];
    cnt[v] -= cnt[u];
    res += cntx[v] * cnty[v];
    res += cntx[u] * cnty[u];
    p[u] = u;
  }
  return;
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> ev[ls].first >> ev[ls].second;
    if (s[{ev[ls].first, ev[ls].second}] == 0) {
      s[{ev[ls].first, ev[ls].second}] = ls;
    } else {
      ev[ls].t = s[{ev[ls].first, ev[ls].second}];
      ev[s[{ev[ls].first, ev[ls].second}]].t = ls;
      s.erase(s.find({ev[ls].first, ev[ls].second}));
    }
    ls++;
    ev[ls].t = 0;
    ev[ls].first = -1;
    ev[ls].second = -1;
    ls++;
  }
  while (!s.empty()) {
    auto w = *s.begin();
    s.erase(s.begin());
    ev[ls].first = w.first.first;
    ev[ls].second = w.first.second;
    ev[ls].t = w.second;
    ev[w.second].t = ls;
    ls++;
  }
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    cnt[i] = 1;
    cntx[i] = 1;
    cnty[i] = 0;
  }
  for (int i = n + 1; i <= n + n; i++) {
    p[i] = i;
    cnt[i] = 1;
    cntx[i] = 0;
    cnty[i] = 1;
  }
  go(1, ls);
  for (int i = 1; i < ls; i++) {
    if (ev[i].t == 0) cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}
