#include <bits/stdc++.h>
using namespace std;
const int MAX = 200020, GAP = 16;
struct query {
  int start, end, index;
  query() {}
  query(int start, int end, int index) : start(start), end(end), index(index) {}
  bool operator<(const query &t) const { return start < t.start; }
};
struct segment {
  int l, r, sum;
  bool all;
  segment() {}
  segment(int l, int r, int sum, bool all) : l(l), r(r), sum(sum), all(all) {}
  void merge(segment &f, segment &s) {
    l = f.l;
    r = s.r;
    sum = f.sum + s.sum;
    if (sum == 0) all = 1;
  }
};
int n, start[MAX], length[MAX], xList[MAX * 2], xFull;
int numQuery, res[MAX];
query queries[MAX];
void input() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &start[i], &length[i]);
    xList[xFull++] = start[i];
    xList[xFull++] = start[i] + length[i];
  }
  sort(xList, xList + xFull);
  xFull = unique(xList, xList + xFull) - xList;
  scanf("%d", &numQuery);
  for (int i = 0; i < numQuery; i++) {
    scanf("%d%d", &queries[i].start, &queries[i].end);
    queries[i].index = i;
  }
  sort(queries, queries + numQuery);
}
segment tree[GAP << 1];
void initTree() {
  for (int i = 0; i < xFull - 1; i++)
    tree[GAP + i] = segment(i, i, xList[i + 1] - xList[i], 0);
  for (int i = xFull - 1; i < GAP; i++)
    tree[GAP + i] = segment(xFull - 1, xFull - 1, 0, 0);
  for (int i = GAP - 1; i > 0; i--) tree[i].merge(tree[i * 2], tree[i * 2 + 1]);
}
void fillTree(int target, int ll, int rr) {
  segment &now = tree[target];
  if (ll <= now.l && now.r <= rr) {
    now.all = 1;
    now.sum = 0;
  } else if (now.all || now.r < ll || rr < now.l)
    return;
  else {
    fillTree(target * 2, ll, rr);
    fillTree(target * 2 + 1, ll, rr);
    now.merge(tree[target * 2], tree[target * 2 + 1]);
  }
}
int countTree(int target, int ll, int rr) {
  segment &now = tree[target];
  if (ll <= now.l && now.r <= rr) {
    return now.sum;
  } else if (now.all || now.r < ll || rr < now.l)
    return 0;
  else {
    int result = 0;
    result += countTree(target * 2, ll, rr);
    result += countTree(target * 2 + 1, ll, rr);
    return result;
  }
}
int posToIndex(int t) { return lower_bound(xList, xList + xFull, t) - xList; }
void solve() {
  int processing = numQuery - 1;
  for (int current = n; current >= 1; current--) {
    fillTree(1, posToIndex(start[current]),
             posToIndex(start[current] + length[current]) - 1);
    while (queries[processing].start == current) {
      query &nowQuery = queries[processing];
      res[nowQuery.index] = countTree(1, posToIndex(start[current]),
                                      posToIndex(start[nowQuery.end]) - 1);
      processing--;
    }
  }
  for (int queryNum = 0; queryNum < numQuery; queryNum++)
    printf("%d\n", res[queryNum]);
}
int main() {
  input();
  initTree();
  solve();
  return 0;
}
