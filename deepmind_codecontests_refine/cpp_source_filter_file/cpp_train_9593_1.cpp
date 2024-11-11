#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e7 + 10;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int n, k, cnt[M], pri[M], tt = 0, vis[M], minp[M], mu[M];
vector<int> d[N], E[N], A, B;
void add(int i, int x, int v) {
  if (x == int(d[i].size())) {
    cnt[v] += mu[v];
    return;
  }
  add(i, x + 1, v), add(i, x + 1, v * d[i][x]);
}
void clr(int i, int x, int v) {
  if (x == int(d[i].size())) {
    cnt[v] = 0;
    return;
  }
  clr(i, x + 1, v), clr(i, x + 1, v * d[i][x]);
}
int qry(int i, int x, int v) {
  if (x == int(d[i].size())) return cnt[v];
  return qry(i, x + 1, v) + qry(i, x + 1, v * d[i][x]);
}
void solve(int l, int r, vector<int> p) {
  if (l == r) {
    E[l] = p;
    return;
  }
  int mid = (l + r) >> 1;
  for (int i = l; i <= mid; i++) add(A[i], 0, 1);
  vector<int> ls, rs;
  for (auto i : p) {
    if (qry(i, 0, 1))
      ls.push_back(i);
    else
      rs.push_back(i);
  }
  for (int i = l; i <= mid; i++) clr(A[i], 0, 1);
  solve(l, mid, ls), solve(mid + 1, r, rs);
}
int main() {
  cin >> n >> k;
  vis[1] = mu[1] = 1;
  for (int i = 2; i < M; i++) {
    if (!vis[i]) pri[++tt] = i, mu[i] = -1, minp[i] = i;
    for (int j = 1; j <= tt && i * pri[j] < M; j++) {
      vis[i * pri[j]] = 1;
      minp[i * pri[j]] = pri[j];
      if (i % pri[j] == 0)
        break;
      else
        mu[i * pri[j]] = -mu[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    int x = gi();
    while (x > 1) {
      int y = minp[x];
      d[i].push_back(y);
      while (x % y == 0) x /= y;
    }
  }
  for (int i = 1; i <= n; i++)
    if (!qry(i, 0, 1))
      add(i, 0, 1), A.push_back(i);
    else
      B.push_back(i);
  if (int(A.size()) >= k) {
    for (int i = 0; i < k; i++) cout << A[i] << ' ';
    return 0;
  }
  for (auto i : A) clr(i, 0, 1);
  solve(0, int(A.size()) - 1, B);
  vector<pair<int, int> > v;
  for (int i = 0; i < int(A.size()); i++)
    v.push_back(make_pair(int(E[i].size()), i));
  sort(v.begin(), v.end(), greater<pair<int, int> >());
  int sum = 0;
  for (int i = 0; i < int(v.size()); i++) {
    sum += v[i].first + 1;
    if (sum >= k) {
      vector<int> ans;
      int req = k - (i + 1) * 2;
      for (int j = 0; j <= i; j++) {
        int tk = min(v[i].first - 1, req);
        req -= tk;
        ++tk;
        ans.push_back(A[v[j].second]);
        for (int k = 0; k < tk; k++) ans.push_back(E[v[j].second][k]);
      }
      for (auto i : ans) cout << i << ' ';
      return 0;
    }
  }
  return 0;
}
