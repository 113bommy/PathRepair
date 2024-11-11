#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const int N = 1e6 + 6, INF = 2e9;
vector<int> v[N];
long long int t[N * 4], up[N * 4], z[N], mx[N], lb[N], rb[N];
int timer = 0;
int n, k;
void push(int v, int L, int R) {
  if (up[v]) {
    if (L != R) {
      up[v * 2] += up[v];
      up[v * 2 + 1] += up[v];
    }
    t[v] += up[v];
    up[v] = 0;
  }
}
void upd(int l, int r, int x, int v = 1, int L = 0, int R = n - 1) {
  push(v, L, R);
  if (l > r) return;
  if (l == L && r == R) {
    up[v] += x;
    push(v, L, R);
  } else {
    int m = (L + R) >> 1;
    upd(l, min(m, r), x, v * 2, L, m);
    upd(max(m + 1, l), r, x, v * 2 + 1, m + 1, R);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
}
long long int que(int l, int r, int v = 1, int L = 0, int R = n - 1) {
  push(v, L, R);
  if (l > r) return -INF;
  if (l == L && r == R) return t[v];
  int m = (L + R) >> 1;
  return max(que(l, min(m, r), v * 2, L, m),
             que(max(m + 1, l), r, v * 2 + 1, m + 1, R));
}
set<pair<int, int>>* dfs(int node, int h) {
  lb[node] = timer++;
  if (v[node].empty()) {
    mx[node] = 1;
    auto st = new set<pair<int, int>>();
    st->insert({-h, node});
    upd(lb[node], lb[node], 1);
    rb[node] = timer - 1;
    return st;
  }
  upd(lb[node], lb[node], -INF);
  vector<set<pair<int, int>>*> t;
  long long int sum = 0;
  for (int to : v[node]) {
    t.push_back(dfs(to, h + 1));
    z[to] = max(0ll, que(lb[to], rb[to]));
    sum += z[to];
  }
  rb[node] = timer - 1;
  for (int to : v[node]) {
    long long int cs = sum - z[to];
    upd(lb[to], rb[to], cs);
    mx[node] = max(mx[node], cs + mx[to]);
  }
  for (int i = 1; i < t.size(); i++) {
    if (t[0]->size() < t[i]->size()) swap(t[0], t[i]);
  }
  for (int i = 1; i < t.size(); i++) {
    t[0]->insert(t[i]->begin(), t[i]->end());
  }
  while (!t[0]->empty() && -t[0]->begin()->first - h >= k) {
    int a = t[0]->begin()->second;
    upd(lb[a], lb[a], -INF);
    t[0]->erase(t[0]->begin());
  }
  return t[0];
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    v[p - 1].push_back(i);
  }
  dfs(0, 0);
  printf("%d", mx[0]);
  return 0;
}
