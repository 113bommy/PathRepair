#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
long long a[N], b[N], c[N], sz[N], p[N], ans[N], n, q, k, cnt, le, ri, ty[N],
    xx[N];
vector<pair<long long, long long> > tree[4 * N];
map<long long, pair<long long, long long> > fix[4 * N];
stack<pair<pair<int, int>, pair<int, int> > > st;
int get_col(int a) {
  if (p[a] == a) return p[a];
  return get_col(p[a]);
}
void col(int a, int b) {
  a = get_col(a);
  b = get_col(b);
  if (a == b) return;
  if (sz[a] < sz[b]) swap(a, b);
  st.push({{a, b}, {sz[a], sz[b]}});
  sz[a] += sz[b];
  p[b] = a;
  sz[b] = 0;
}
void update(int node, int le, int ri, int start, int end, int v, int u) {
  if (le > end || ri < start) return;
  if (le >= start && ri <= end) {
    tree[node].push_back({v, u});
    return;
  }
  int mid = (le + ri) / 2;
  update(2 * node, le, mid, start, end, v, u);
  update(2 * node + 1, mid + 1, ri, start, end, v, u);
}
void uncol(int a, int b, int c, int d) {
  p[a] = a;
  p[b] = b;
  sz[a] = c;
  sz[b] = d;
}
void dfs(int node, int le, int ri) {
  int pre = st.size();
  for (int i = 0; i < tree[node].size(); i++) {
    col(tree[node][i].first, tree[node][i].second);
  }
  int lst = st.size();
  int ad = lst - pre;
  if (le == ri) {
    ans[le] = sz[get_col(a[le])];
    while (ad) {
      ad--;
      pair<pair<int, int>, pair<int, int> > x = st.top();
      st.pop();
      uncol(x.first.first, x.first.second, x.second.first, x.second.second);
    }
    return;
  }
  int mid = (le + ri) / 2;
  dfs(2 * node, le, mid);
  dfs(2 * node + 1, mid + 1, ri);
  while (ad) {
    ad--;
    pair<pair<int, int>, pair<int, int> > x = st.top();
    st.pop();
    uncol(x.first.first, x.first.second, x.second.first, x.second.second);
  }
}
int main() {
  cin >> n >> q >> k;
  cnt = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    sz[i] = 1;
  }
  cnt = 1;
  for (int i = 1; i <= q; i++) {
    cin >> ty[i];
    if (ty[i] == 1) {
      cin >> a[i] >> b[i];
      c[i] = cnt;
      continue;
    }
    if (ty[i] == 2) {
      cin >> a[i];
      b[i] = cnt;
      continue;
    }
    if (ty[i] == 3) {
      cnt++;
      xx[cnt] = i;
      continue;
    }
  }
  for (int i = cnt + 1; i <= cnt + k; i++) xx[i] = 1e9;
  for (int i = 1; i <= q; i++) {
    if (ty[i] == 1) {
      le = i;
      ri = min(q, xx[c[i] + k] - 1);
      update(1, 1, q, le, ri, a[i], b[i]);
      continue;
    }
  }
  dfs(1, 1, q);
  for (int i = 1; i <= q; i++) {
    if (ty[i] == 2) {
      cout << ans[i] << " ";
    }
  }
}
