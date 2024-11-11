#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5;
const int NN = N + 10;
const int MAXN = 1e9;
struct SegTreeNode {
  long long val;
  long long addMark;
};
struct Race {
  int l, r;
  long long p;
};
Race race[NN];
SegTreeNode node[4 * NN];
long long dp[NN];
long long cost[NN];
void initD(int n) {
  int i;
  for (i = 0; i <= n; i++) {
    dp[i] = 0;
  }
}
void buildTree(int ns, int ne, int root) {
  node[root].addMark = 0;
  if (ns == ne) {
    node[root].val = dp[ns];
  } else {
    int mid = (ns + ne) / 2;
    buildTree(ns, mid, root * 2 + 1);
    buildTree(mid + 1, ne, root * 2 + 2);
    node[root].val = max(node[root * 2 + 1].val, node[root * 2 + 2].val);
  }
}
void pushDown(int r) {
  if (node[r].addMark == 0) return;
  node[r * 2 + 1].addMark += node[r].addMark;
  node[r * 2 + 2].addMark += node[r].addMark;
  node[r * 2 + 1].val += node[r].addMark;
  node[r * 2 + 2].val += node[r].addMark;
  node[r].addMark = 0;
}
long long query(int qs, int qe, int ns, int ne, int r) {
  if (qe < ns || qs > ne) {
    return -1;
  }
  if (qs <= ns && ne <= qe) {
    return node[r].val;
  }
  pushDown(r);
  int mid = (ns + ne) / 2;
  return max(query(qs, qe, ns, mid, r * 2 + 1),
             query(qs, qe, mid + 1, ne, r * 2 + 2));
}
void update(int qs, int qe, int ns, int ne, int r, long long addVal) {
  if (qe < ns || qs > ne) {
    return;
  }
  if (qs <= ns && ne <= qe) {
    node[r].addMark += addVal;
    node[r].val += addVal;
    return;
  }
  pushDown(r);
  int mid = (ns + ne) / 2;
  update(qs, qe, ns, mid, r * 2 + 1, addVal);
  update(qs, qe, mid + 1, ne, r * 2 + 2, addVal);
  node[r].val = max(node[r * 2 + 1].val, node[r * 2 + 2].val);
}
int cmp(Race a, Race b) { return a.r < b.r; }
void solve() {
  int n, m;
  int l, r;
  long long p;
  int i, j, k;
  while (scanf("%d%d", &n, &m) != EOF) {
    assert(1 <= n && n <= N);
    assert(1 <= m && m <= N);
    int ioflag = 0;
    for (i = 0; i < n; i++) {
      ioflag = scanf("%I64d", cost + i);
      assert(ioflag == 1);
      assert(0 <= cost[i] && cost[i] <= MAXN);
    }
    for (i = 0; i < m; i++) {
      ioflag = scanf("%d%d%I64d", &l, &r, &p);
      assert(ioflag == 3);
      assert(1 <= l && l <= r && r <= n);
      assert(1 <= p && p <= MAXN);
      race[i].l = l;
      race[i].r = r;
      race[i].p = p;
    }
    sort(race, race + m, cmp);
    initD(n);
    buildTree(0, n, 0);
    update(0, n, 0, n, 0, dp[0]);
    for (i = 0, j = 0; i < n; i++) {
      update(0, i, 0, n, 0, -cost[i]);
      r = i + 1;
      while (race[j].r == r && j < m) {
        update(0, race[j].l - 1, 0, n, 0, race[j].p);
        j++;
      }
      dp[r] = max(dp[r - 1], query(0, n, 0, n, 0));
      update(r, r, 0, n, 0, dp[r]);
    }
    printf("%I64d\n", dp[n]);
  }
}
int main() {
  solve();
  return 0;
}
