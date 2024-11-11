#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
const int N = 1e5 + 2;
int ans[N];
vector<int> pos[N], vals[N];
int pad[N];
int find(int u) {
  if (pad[u] != pad[pad[u]]) return pad[u] = find(pad[u]);
  return pad[u];
}
void merge(int u, int v) {
  int pu = find(u), pv = find(v);
  if (pu != pv) {
    pad[pu] = pv;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> p(n), d(n);
  for (int i = int(0); i < int(n); ++i) {
    cin >> p[i];
    p[i]--;
    pad[i] = i;
  }
  for (int i = int(0); i < int(n); ++i) {
    cin >> d[i];
    if (i - d[i] > 0) merge(i, i - d[i]);
    if (i + d[i] < n) merge(i, i + d[i]);
  }
  set<int> st;
  for (int i = int(0); i < int(n); ++i) {
    int pai = find(i);
    pos[pai].push_back(i);
    vals[pai].push_back(p[i]);
    st.insert(pai);
  }
  for (auto x : st)
    if (!vals[x].empty()) sort(vals[x].begin(), vals[x].end());
  for (auto pai : st) {
    for (int i = int(0); i < int(int(pos[pai].size())); ++i) {
      ans[pos[pai][i]] = vals[pai][i];
    }
  }
  for (int i = int(0); i < int(n); ++i) {
    if (ans[i] != i) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
