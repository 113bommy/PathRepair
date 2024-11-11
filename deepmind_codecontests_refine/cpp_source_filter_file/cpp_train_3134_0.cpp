#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200000;
const int MAX_K = 5000000;
const int MAX_Q = 1100000;
const int MAX_T = 10;
const int INF = 1e8;
int N, Q;
int arr[MAX_N + 1];
vector<pair<int, int> > gp[MAX_N + 1];
vector<int> vt[MAX_N + 1];
int idx[MAX_T + 1][MAX_K + 1];
int use, now = 1;
void make_edge(int x, int y, int z) {
  gp[x].push_back({y, z});
  gp[y].push_back({x, z});
}
void dfs(int x, int y) {
  if (y == vt[x].size()) {
    for (int j = 0; j < MAX_T; j++) {
      if (idx[j][now] != 0) {
        make_edge(idx[j][now], x, j + vt[x].size() - use);
      }
    }
    return;
  } else {
    dfs(x, y + 1);
    use++;
    now *= vt[x][y];
    dfs(x, y + 1);
    now /= vt[x][y];
    use--;
  }
}
void dfs2(int x, int y) {
  if (y == vt[x].size()) {
    idx[vt[x].size() - use][now] = x;
    return;
  } else {
    dfs2(x, y + 1);
    use++;
    now *= vt[x][y];
    dfs2(x, y + 1);
    now /= vt[x][y];
    use--;
  }
}
struct Query {
  int x, y, z;
  bool operator<(const Query &a) const { return x < a.x; }
};
vector<Query> query;
struct SEG {
  struct NODE {
    int l, r;
    int mn;
  };
  int SZ;
  vector<NODE> seg;
  void add() { seg.push_back({-1, -1, INF}); }
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
  void Update(int x, int y) { update(0, 1, SZ, x, y); }
  void update(int idx, int s, int e, int x, int y) {
    seg[idx].mn = min(seg[idx].mn, y);
    if (s == e) return;
    if (x <= (s + e) / 2)
      update(seg[idx].l, s, (s + e) / 2, x, y);
    else
      update(seg[idx].r, (s + e) / 2 + 1, e, x, y);
  }
  int Mn(int x, int y) { return mn(0, 1, SZ, x, y); }
  int mn(int idx, int s, int e, int x, int y) {
    if (x <= s && e <= y) {
      return seg[idx].mn;
    }
    if (x > e || y < s) return INF;
    return min(mn(seg[idx].l, s, (s + e) / 2, x, y),
               mn(seg[idx].r, (s + e) / 2 + 1, e, x, y));
  }
} Seg;
int ans[MAX_Q + 1];
void Add(int x) {
  for (pair<int, int> i : gp[x]) {
    if (i.first > x) {
      Seg.Update(i.first, i.second);
    }
  }
}
int main() {
  scanf("%d%d", &N, &Q);
  Seg.Init(N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &arr[i]);
    for (int j = 2; j * j <= arr[i]; j++) {
      while (arr[i] % (j * j) == 0) {
        arr[i] /= j * j;
      }
      if (arr[i] % j == 0) {
        vt[i].push_back(j);
        arr[i] /= j;
      }
    }
    if (arr[i] != 1) {
      vt[i].push_back(arr[i]);
      arr[i] = 1;
    }
    use = 0;
    now = 1;
    dfs(i, 0);
    use = 0;
    now = 1;
    dfs2(i, 0);
  }
  for (int i = 1; i <= Q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    query.push_back({l, r, i});
  }
  sort(query.begin(), query.end());
  int n = N;
  while (!query.empty()) {
    Query q = query.back();
    query.pop_back();
    while (n >= q.x) {
      Add(n);
      n--;
    }
    ans[q.z] = Seg.Mn(q.x, q.y);
  }
  for (int i = 1; i <= Q; i++) {
    printf("%d\n", ans[i]);
  }
}
