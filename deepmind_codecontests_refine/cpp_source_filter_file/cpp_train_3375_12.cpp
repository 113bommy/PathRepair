#include <bits/stdc++.h>
const double PI = 3.141592653589793238460;
using namespace std;
const int maxn = 100001;
const int blk = 600;
vector<int> ar[maxn];
int s[maxn], t[maxn], ft[2 * maxn], col[maxn];
int nodeF[maxn], eleF[maxn];
int first[maxn];
int ans[maxn];
int timer;
int bucket[maxn];
struct query {
  int l;
  int r;
  int idx;
  int k;
};
query Q[maxn];
void dfs(int u, int par) {
  s[u] = timer;
  ft[timer] = u;
  timer++;
  for (int c : ar[u])
    if (c != par) dfs(c, u);
  t[u] = timer;
  ft[timer] = u;
  timer++;
}
int getBlock(int idx) { return (idx + blk - 1) / blk; }
void add(int idx) {
  int node = ft[idx];
  int c = col[node];
  nodeF[node]++;
  if (nodeF[node] == 2) {
    eleF[c]++;
    first[eleF[c]]++;
    bucket[getBlock(eleF[c])]++;
    first[eleF[c] - 1]--;
    bucket[getBlock(eleF[c] - 1)]--;
  }
}
void remove(int idx) {
  int node = ft[idx];
  int c = col[node];
  nodeF[node]--;
  if (nodeF[node] == 1) {
    eleF[c]--;
    first[eleF[c]]++;
    bucket[getBlock(eleF[c])]++;
    first[eleF[c] + 1]--;
    bucket[getBlock(eleF[c] + 1)]++;
  }
}
bool comp(query a, query b) {
  int x = a.l / blk;
  int y = b.l / blk;
  if (x != y) return x < y;
  return x % 2 ? a.r < b.r : a.r > b.r;
}
int getAns(int k, int n) {
  int res = 0;
  int LB = getBlock(k);
  int RB = getBlock(n);
  if (LB == RB) {
    for (int i = k; i <= n; i++) res += first[i];
  } else {
    for (int i = k; i <= LB * blk; i++) res += first[i];
    for (int i = LB + 1; i < RB; i++) res += bucket[i];
    for (int i = RB * blk + 1; i <= n; i++) res += first[i];
  }
  return res;
}
int main() {
  int q, a, b, k, n;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> col[i];
  for (int i = 1; i <= n - 1; i++)
    cin >> a >> b, ar[a].push_back(b), ar[b].push_back(a);
  timer = 1;
  dfs(1, -1);
  for (int i = 1; i <= q; i++) {
    cin >> a >> k;
    Q[i].l = s[a];
    Q[i].r = t[a];
    Q[i].k = k;
    Q[i].idx = i;
  }
  sort(Q + 1, Q + q + 1, comp);
  int ML = 1, MR = 0;
  for (int i = 1; i <= q; i++) {
    int L = Q[i].l;
    int R = Q[i].r;
    int idx = Q[i].idx;
    k = Q[i].k;
    while (MR < R) MR++, add(MR);
    while (ML > L) ML--, add(ML);
    while (MR > R) remove(MR), MR--;
    while (ML < L) remove(ML), ML++;
    ans[idx] = getAns(k, n);
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
  return 0;
}
