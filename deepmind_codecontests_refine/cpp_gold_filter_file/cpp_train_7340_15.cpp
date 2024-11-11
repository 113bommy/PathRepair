#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 2e9;
const long long INFLL = 1e18;
const int MAX_N = 100000;
const int MAX_K = 20;
int N, Q;
vector<int> gp[MAX_N + 1];
int lv[MAX_N + 1], up[MAX_N + 1][MAX_K + 1], p[MAX_N + 1];
vector<int> v;
int in[MAX_N + 1], out[MAX_N + 1], ccnt;
void dfs(int x) {
  in[x] = ++ccnt;
  up[x][0] = p[x];
  for (int i = 1; i < MAX_K; i++) {
    up[x][i] = up[up[x][i - 1]][i - 1];
  }
  for (int i : gp[x]) {
    if (i == p[x]) continue;
    lv[i] = lv[x] + 1;
    p[i] = x;
    dfs(i);
  }
  out[x] = ccnt;
}
int lca(int x, int y) {
  for (int i = MAX_K - 1; i >= 0; i--) {
    if (lv[up[x][i]] >= lv[y]) {
      x = up[x][i];
    }
    if (lv[up[y][i]] >= lv[x]) {
      y = up[y][i];
    }
  }
  if (x == y) return x;
  for (int i = MAX_K - 1; i >= 0; i--) {
    if (up[x][i] != up[y][i]) {
      x = up[x][i];
      y = up[y][i];
    }
  }
  return up[x][0];
}
bool sf(int x, int y) { return (in[x] < in[y]); }
bool chk[MAX_N + 1];
struct SEG {
  struct NODE {
    int l, r;
    int sum;
  };
  vector<NODE> seg;
  int SZ;
  void add() { seg.push_back({-1, -1, 0}); }
  void Init(int x) {
    SZ = x;
    add();
    init(0, 1, SZ);
  }
  void init(int idx, int s, int e) {
    if (s == e) return;
    seg[idx].l = seg.size();
    add();
    seg[idx].r = seg.size();
    add();
    init(seg[idx].l, s, (s + e) / 2);
    init(seg[idx].r, (s + e) / 2 + 1, e);
  }
  void Add(int x, int y) { add(0, 1, SZ, x, y); }
  void add(int idx, int s, int e, int x, int y) {
    seg[idx].sum += y;
    if (s == e) return;
    if (x <= (s + e) / 2) {
      add(seg[idx].l, s, (s + e) / 2, x, y);
    } else {
      add(seg[idx].r, (s + e) / 2 + 1, e, x, y);
    }
  }
  void Rst(int x) { rst(0, 1, SZ, x); }
  void rst(int idx, int s, int e, int k) {
    seg[idx].sum = 0;
    if (s == e) return;
    if (k <= (s + e) / 2) {
      rst(seg[idx].l, s, (s + e) / 2, k);
    } else
      rst(seg[idx].r, (s + e) / 2 + 1, e, k);
  }
  int Sum(int x, int y) { return sum(0, 1, SZ, x, y); }
  int sum(int idx, int s, int e, int x, int y) {
    if (x <= s && e <= y) return seg[idx].sum;
    if (x > e || y < s) return 0;
    return sum(seg[idx].l, s, (s + e) / 2, x, y) +
           sum(seg[idx].r, (s + e) / 2 + 1, e, x, y);
  }
} Seg;
int main() {
  scanf("%d", &N);
  Seg.Init(N);
  for (int i = 1; i < N; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    gp[a].push_back(b);
    gp[b].push_back(a);
  }
  lv[1] = 1;
  dfs(1);
  scanf("%d", &Q);
  while (Q--) {
    while (!v.empty()) v.pop_back();
    int sz;
    scanf("%d", &sz);
    while (sz--) {
      int x;
      scanf("%d", &x);
      v.push_back(x);
      chk[x] = true;
    }
    sort(v.begin(), v.end(), sf);
    sz = (int)v.size();
    for (int i = 0; i < sz - 1; i++) {
      v.push_back(lca(v[i], v[i + 1]));
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    sort(v.begin(), v.end(), sf);
    bool tf = false;
    int ans = 0;
    for (int i = (int)v.size() - 1; i >= 0; i--) {
      int now = v[i];
      if (chk[now] && chk[p[now]]) {
        tf = true;
        break;
      }
      int num = Seg.Sum(in[now], out[now]);
      if (chk[now]) {
        ans += num;
        Seg.Add(in[now], 1 - num);
      } else if (num > 1) {
        ans++;
        Seg.Add(in[now], -num);
      }
    }
    for (int i = 0; i < v.size(); i++) {
      Seg.Rst(in[v[i]]);
      chk[v[i]] = false;
    }
    if (tf) {
      printf("-1\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
