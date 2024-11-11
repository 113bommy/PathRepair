#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct node {
  int w, c, num;
  node(int _w, int _c) : w(_w), c(_c) {}
  node(int _w, int _c, int _num) : w(_w), c(_c), num(_num) {}
  node() {}
  long long cnt() const { return 1LL * (w - w / 2) * num; }
  bool operator<(const node &b) const {
    long long tmp1 = cnt();
    long long tmp2 = b.cnt();
    return tmp1 < tmp2;
  }
} nodes[maxn];
vector<pair<int, int> > V[maxn];
int dfs(int u, int pre) {
  int res = 0;
  bool f = false;
  for (int i = 0; i < V[u].size(); i++) {
    pair<int, int> tmp = V[u][i];
    int v = tmp.first, idx = tmp.second;
    if (v == pre) continue;
    f = true;
    int num = dfs(v, u);
    nodes[idx].num = num;
    res += num;
  }
  if (!f) {
    res++;
  }
  return res;
}
long long ct[2][6000000];
int ct_cnt[3];
long long sum[2][6000000];
int n;
long long S;
void init() {
  memset(ct_cnt, 0, sizeof(ct_cnt));
  for (int i = 1; i <= n; i++) {
    V[i].clear();
  }
}
void init2(int flag) {
  priority_queue<node> Q;
  for (int i = 1; i < n; i++) {
    if (nodes[i].c == flag) {
      Q.push(nodes[i]);
    }
  }
  while (!Q.empty()) {
    node tmp = Q.top();
    Q.pop();
    long long can_ct = tmp.cnt();
    ct[flag - 1][++ct_cnt[flag - 1]] = can_ct;
    if (tmp.w / 2 != 0) {
      Q.push(node(tmp.w / 2, tmp.c, tmp.num));
    }
  }
  for (int i = 1; i <= ct_cnt[flag - 1]; i++) {
    sum[flag - 1][i] = sum[flag - 1][i - 1] + ct[flag - 1][i];
  }
}
int get_idx(long long val) {
  int l = 1, r = ct_cnt[1];
  int ans = -1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (sum[1][mid] >= val) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return ans;
}
long long work() {
  long long all = 0;
  for (int i = 1; i < n; i++) {
    all += nodes[i].w * nodes[i].num;
  }
  long long need_del = all - S;
  if (need_del <= 0) {
    return 0;
  }
  int ans = 1e9;
  for (int i = 0; i <= ct_cnt[0]; i++) {
    long long tmp1 = sum[0][i];
    if (tmp1 >= need_del) {
      ans = min(ans, i);
      break;
    }
    long long tmp2 = need_del - tmp1;
    int idx = get_idx(tmp2);
    if (idx == -1) {
      continue;
    }
    ans = min(ans, i + idx * 2);
  }
  return ans;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %lld", &n, &S);
    init();
    int u, v, w, c;
    for (int i = 1; i < n; i++) {
      scanf("%d %d %d %d", &u, &v, &w, &c);
      V[u].push_back(make_pair(v, i));
      V[v].push_back(make_pair(u, i));
      nodes[i] = node(w, c);
    }
    dfs(1, -1);
    init2(1);
    init2(2);
    printf("%lld\n", work());
  }
}
