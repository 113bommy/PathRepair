#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int t, n, l[maxn], r[maxn], cnt, re[maxn], m, ans;
bool vis[maxn], qs[maxn];
vector<int> ps, s[2 * maxn], e[2 * maxn];
set<int> st;
int main() {
  cin >> t;
  while (t--) {
    ps.clear();
    st.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> l[i] >> r[i];
      r[i]++;
      ps.push_back(l[i]);
      ps.push_back(r[i]);
    }
    sort(ps.begin(), ps.end());
    ps.resize(unique(ps.begin(), ps.end()) - ps.begin());
    for (int i = 0; i < ps.size(); i++) {
      s[i].clear();
      e[i].clear();
    }
    for (int i = 0; i < n; i++) {
      l[i] = lower_bound(ps.begin(), ps.end(), l[i]) - ps.begin();
      r[i] = lower_bound(ps.begin(), ps.end(), r[i]) - ps.begin();
      s[l[i]].push_back(i);
      e[r[i]].push_back(i);
      vis[i] = 0;
      re[i] = 0;
      qs[i] = 0;
    }
    cnt = 0;
    m = 0;
    for (int i = 0; i < ps.size(); i++) {
      int cntl = cnt, il = -1, cntp = 2, il2 = -1;
      if (cnt == 1) il = (*st.begin());
      for (int u : e[i]) st.erase(u);
      cntp = st.size();
      if (cntp == 1) il2 = (*st.begin());
      for (int u : s[i]) {
        if (st.size() == 1) {
          qs[(*st.begin())] = 1;
        }
        st.insert(u);
        if (st.size() > 1) qs[u] = 1;
      }
      cnt = st.size();
      if (cnt && cntl == 0) m++;
      if (cntl > 1 && cnt == 1) {
        int x = (*st.begin());
        if (l[x] != i) {
          vis[x] = 1;
        }
      }
      if (cntl == 1 && cnt > 1) {
        if (vis[il] && r[il] != i) {
          re[il]++;
        }
      }
      if (cntl > 1 && cntp == 1 && cnt > 1) {
        vis[il2] = 1;
        re[il2]++;
      }
    }
    ans = -1;
    for (int i = 0; i < n; i++) {
      if (qs[i])
        ans = max(ans, re[i] + m);
      else
        ans = max(ans, m - 1);
    }
    cout << ans << endl;
  }
  return 0;
}
