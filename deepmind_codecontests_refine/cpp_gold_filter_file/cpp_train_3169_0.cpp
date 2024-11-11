#include <bits/stdc++.h>
using namespace std;
vector<int> g1[30000 + 100], g2[30000 + 100];
set<int> st;
int Next[30000 + 100], Prev[30000 + 100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, start;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g1[u].push_back(v);
    g2[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    sort(g1[i].begin(), g1[i].end());
    sort(g2[i].begin(), g2[i].end());
  }
  start = 0;
  st.insert(0);
  st.insert(1);
  Next[start] = 1;
  Prev[1] = 0;
  for (int i = 2; i <= n; i++) {
    vector<int> d;
    bool flag = false;
    for (auto it : g1[i]) {
      if (it > i) continue;
      int t1 = Next[it];
      if (!binary_search(g1[i].begin(), g1[i].end(), t1)) {
        flag = true;
        Next[it] = i;
        Prev[t1] = i;
        Next[i] = t1;
        Prev[i] = it;
        break;
      } else {
        st.erase(it);
        d.push_back(it);
      }
    }
    if (!flag) {
      for (auto it : g2[i]) {
        if (it > i) continue;
        int t1 = Prev[it];
        if (!binary_search(g1[t1].begin(), g1[t1].end(), i)) {
          flag = true;
          Next[t1] = i;
          Prev[it] = i;
          Next[i] = it;
          Prev[i] = t1;
          break;
        } else {
          st.erase(t1);
          d.push_back(t1);
        }
      }
    }
    if (!flag) {
      auto it = st.begin();
      int t1 = Next[*it];
      Next[*it] = i;
      Prev[t1] = i;
      Next[i] = t1;
      Prev[i] = *it;
    }
    for (auto it : d) {
      st.insert(it);
    }
    st.insert(i);
  }
  int now = Next[0];
  while (now) {
    cout << now << " ";
    now = Next[now];
  }
}
