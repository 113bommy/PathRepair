#include <bits/stdc++.h>
using namespace std;
int n, sz[400001], n2, b, b1;
bool an[400001];
vector<int> cn;
vector<int> tr[400001];
vector<pair<int, int> > ch;
;
void pl(int v = 1, int p = 0) {
  sz[v] = 1;
  bool cnc = true;
  for (int i = 0; i < tr[v].size(); ++i) {
    int u = tr[v][i];
    if (u == p) continue;
    pl(u, v);
    sz[v] += sz[u];
    if (sz[u] > n2) cnc = false;
  }
  if (cnc && n - sz[v] <= n2) cn.push_back(v);
}
int k;
void fn(int v, int p) {
  for (int i = 0; i < tr[v].size(); ++i)
    if (tr[v][i] != p) fn(tr[v][i], v);
  int s = n - sz[v] - sz[k];
  an[v] |= s <= n2;
}
int main() {
  scanf("%d", &n);
  if (n == 2) {
    printf("1 1");
    return 0;
  }
  n2 = n >> 1;
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    tr[a].push_back(b);
    tr[b].push_back(a);
  }
  pl();
  int t = cn[0];
  cn.clear();
  pl(t);
  int lm = cn.size();
  for (int i = 0; i < lm; ++i) {
    int c = cn[i];
    pl(c);
    ch.clear();
    for (int i = 0; i < tr[c].size(); ++i) {
      int u = tr[c][i];
      ch.push_back(make_pair(sz[u], u));
    }
    sort(ch.begin(), ch.end());
    b = ch.back().second, b1 = ch[ch.size() - 2].second;
    for (int i = 0; i < tr[c].size(); ++i)
      k = (tr[c][i] == b ? b1 : b), fn(tr[c][i], c);
    an[c] |= 1;
  }
  for (int i = 1; i < n + 1; ++i) printf("%d ", an[i]);
}
