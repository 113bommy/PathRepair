#include <bits/stdc++.h>
using namespace std;
vector<int> ar[100001];
int n, col[100001], FT[200002], S[100001], T[100001], BLK = 400, res[100001];
int eleF[100001], nodeF[100001], FF[100001], bucket[400], timer;
struct query {
  int l, r, k, idx;
};
query Q[100001];
void dfs(int node, int par) {
  FT[timer] = node;
  S[node] = timer;
  timer++;
  for (int child : ar[node]) {
    if (child != par) dfs(child, node);
  }
  FT[timer] = node;
  T[node] = timer;
  timer++;
}
bool comp(query a, query b) {
  if (a.l / BLK != b.l / BLK) return a.l / BLK < b.l / BLK;
  if ((a.l / BLK) & 1) return a.r < b.r;
  return a.r > b.r;
}
int getBlock(int x) { return (x + BLK - 1) / BLK; }
void add(int idx) {
  int node = FT[idx];
  int c = col[node];
  nodeF[node]++;
  if (nodeF[node] == 2) {
    eleF[c]++;
    FF[eleF[c]]++;
    bucket[getBlock(eleF[c])]++;
    FF[eleF[c] - 1]--;
    bucket[getBlock(eleF[c] - 1)]--;
  }
}
void remov(int idx) {
  int node = FT[idx];
  int c = col[node];
  nodeF[node]--;
  if (nodeF[node] == 1) {
    eleF[c]--;
    FF[eleF[c]]++;
    bucket[getBlock(eleF[c])]++;
    FF[eleF[c] + 1]--;
    bucket[getBlock(eleF[c] + 1)]--;
  }
}
int getAnswer(int k, int n) {
  int LB = getBlock(k);
  int RB = getBlock(n);
  int s = 0;
  if (LB == RB) {
    for (int i = k; i <= n; i++) s += FF[i];
    return s;
  }
  for (int i = k; i <= LB * BLK; i++) s += FF[i];
  for (int i = LB + 1; i < RB; i++) s += bucket[i];
  for (int i = (RB - 1) * BLK + 1; i <= n; i++) s += FF[i];
  return s;
}
int main() {
  int q, a, b;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> col[i];
  for (int i = 1; i <= n - 1; i++)
    cin >> a >> b, ar[a].push_back(b), ar[b].push_back(a);
  timer = 1;
  dfs(1, -1);
  for (int i = 1; i <= q; i++) {
    cin >> a >> b;
    Q[i].l = S[a];
    Q[i].r = T[a];
    Q[i].k = b;
    Q[i].idx = i;
  }
  sort(Q + 1, Q + 1 + q, comp);
  int ML = 1, MR = 0;
  for (int i = 1; i <= q; i++) {
    int L = Q[i].l;
    int R = Q[i].r;
    int k = Q[i].k;
    int index = Q[i].idx;
    while (MR < R) MR++, add(MR);
    while (ML > L) ML--, add(ML);
    while (MR > R) remov(MR), MR--;
    while (ML < L) remov(ML), ML++;
    res[index] = getAnswer(k, n);
  }
  for (int i = 1; i <= q; i++) cout << res[i] << "\n";
}
