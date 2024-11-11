#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> grf[200005];
set<pair<int, int> > st;
int outdeg[200005];
int label[200005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    grf[u].push_back(v);
    outdeg[v]++;
  }
  for (int i = 1; i <= n; i++) {
    st.insert(make_pair(outdeg[i], -i));
  }
  int id = n;
  while (!st.empty()) {
    int now = -(*st.begin()).second;
    st.erase(st.begin());
    label[now] = id--;
    for (int i = 0; i < grf[now].size(); i++) {
      int nxt = grf[now][i];
      st.erase(st.find(make_pair(outdeg[nxt], -nxt)));
      outdeg[nxt]--;
      st.insert(make_pair(outdeg[nxt], -nxt));
    }
  }
  for (int i = 1; i <= n; i++) cout << label[i] << " ";
  cout << endl;
  return 0;
}
