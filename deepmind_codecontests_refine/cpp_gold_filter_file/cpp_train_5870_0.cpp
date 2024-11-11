#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
bool truth[N];
int nvar;
int neg(int x) { return N - 1 - x; }
vector<int> g[N];
int n, lw[N], idx[N], qidx, cmp[N], qcmp;
stack<int> st;
void tjn(int u) {
  lw[u] = idx[u] = ++qidx;
  st.push(u);
  cmp[u] = -2;
  for (int v : g[u]) {
    if (!idx[v] || cmp[v] == -2) {
      if (!idx[v]) tjn(v);
      lw[u] = min(lw[u], lw[v]);
    }
  }
  if (lw[u] == idx[u]) {
    int x, l = -1;
    do {
      x = st.top();
      st.pop();
      cmp[x] = qcmp;
      if (min(x, neg(x)) < nvar) l = x;
    } while (x != u);
    if (l != -1) truth[qcmp] = (cmp[neg(l)] < 0);
    qcmp++;
  }
}
void scc() {
  memset(idx, 0, sizeof(idx));
  qidx = 0;
  memset(cmp, -1, sizeof(cmp));
  qcmp = 0;
  for (int i = 0; i < n; i++)
    if (!idx[i]) tjn(i);
}
void addor(int a, int b) {
  g[neg(a)].push_back(b);
  g[neg(b)].push_back(a);
}
bool satisf(int _nvar) {
  nvar = _nvar;
  n = N;
  scc();
  for (int i = 0; i < nvar; i++)
    if (cmp[i] == cmp[neg(i)]) return false;
  return true;
}
bool intersect(pair<int, int>& a, pair<int, int>& b) {
  if (a.first < b.first && b.first < a.second) {
    return a.second < b.second;
  } else if (a.first < b.second && b.second < a.second) {
    return b.first < a.first;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a > b) swap(a, b);
    v.push_back({a, b});
  }
  for (int i = 0; i < m; i++)
    for (int j = i + 1; j < m; j++) {
      if (intersect(v[i], v[j])) {
        addor(i, j);
        addor(neg(i), neg(j));
      }
    }
  if (satisf(m)) {
    for (int i = 0; i < m; i++) cout << "io"[truth[cmp[i]]];
    cout << '\n';
  } else
    cout << "Impossible" << '\n';
}
