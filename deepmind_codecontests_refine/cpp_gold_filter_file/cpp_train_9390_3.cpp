#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005, MAXM = 500005;
struct Edge {
  int from, to;
  int val;
  int id;
  Edge(int from = 0, int to = 0, int val = 0, int id = 0)
      : from(from), to(to), val(val), id(id) {}
  bool operator<(const Edge& b) const {
    if (val != b.val) return val < b.val;
    return from == 1;
  }
};
Edge a[MAXM], b[MAXM];
int N, M, K;
int father[MAXN];
int Find(int x) {
  if (father[x] < 0) return x;
  return father[x] = Find(father[x]);
}
int check(double shift, bool can, vector<int>& mst) {
  memset(father, -1, sizeof(father));
  mst.clear();
  for (int i = 1; i <= M; ++i) {
    b[i] = a[i];
    if (b[i].from == 1) b[i].val -= shift;
  }
  sort(b + 1, b + M + 1);
  int res = 0;
  for (int i = 1; i <= M; ++i) {
    int u = Find(b[i].from), v = Find(b[i].to);
    if (u == v) continue;
    if (!can && res + (b[i].from == 1) > K) continue;
    father[u] = v;
    mst.push_back(b[i].id);
    res += (b[i].from == 1);
  }
  return res;
}
int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= M; ++i) {
    scanf("%d%d%d", &a[i].from, &a[i].to, &a[i].val);
    if (a[i].from > a[i].to) swap(a[i].from, a[i].to);
    a[i].id = i;
  }
  int left = -100001, right = 100001, mid = (left + right) / 2;
  vector<int> mst;
  if (check(right, 1, mst) < K || check(left, 1, mst) > K ||
      mst.size() < N - 1) {
    puts("-1");
    return 0;
  }
  while (left + 1 < right) {
    if (check(mid, true, mst) < K)
      left = mid;
    else
      right = mid;
    mid = (left + right) / 2;
  }
  check(right, false, mst);
  printf("%d\n", N - 1);
  for (int id : mst) printf("%d ", id);
  puts("");
  return 0;
}
