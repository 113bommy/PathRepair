#include <bits/stdc++.h>
using namespace std;
int deg[100000], s[100000];
int main() {
  int n;
  cin >> n;
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    cin >> deg[i] >> s[i];
    if (deg[i] == 1) {
      st.push(i);
    }
  }
  vector<pair<int, int> > ed;
  while (st.size()) {
    int u = st.top();
    st.pop();
    if (deg[u] != 1) break;
    deg[s[u]]--;
    s[s[u]] ^= u;
    if (deg[s[u]] == 1) {
      st.push(s[u]);
    }
    ed.push_back(pair<int, int>(u, s[u]));
  }
  cout << ed.size() << endl;
  for (int i = 0; i < ed.size(); ++i)
    cout << ed[i].first << " " << ed[i].second << endl;
}
