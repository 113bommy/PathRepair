#include <bits/stdc++.h>
using namespace std;
int treeArr[1048576];
int result[524288];
int resLoc[524288];
struct QueryNode {
  int loc;
  int id;
  bool operator<(const QueryNode other) const { return loc < other.loc; }
  void read(int v_id) {
    scanf("%d", &loc);
    id = v_id;
  }
} queryNodes[524288];
int qlen;
int mxRgt;
struct PairNode {
  bool lr;
  int pos;
  int belong;
  bool operator<(const PairNode other) const {
    if (pos != other.pos)
      return pos < other.pos;
    else
      return lr || (!other.lr);
  }
  void set(int v_pos, bool v_lr, int v_belong) {
    pos = v_pos;
    lr = v_lr;
    belong = v_belong;
    if (lr == false && pos > mxRgt) mxRgt = pos;
  }
} pairNodes[524288 << 1];
struct Pair {
  int left, right;
  void read(int i);
} pairs[524288];
void Pair::read(int i) {
  scanf("%d%d", &pairs[i].left, &pairs[i].right);
  pairNodes[i * 2].set(left, true, i);
  pairNodes[i * 2 + 1].set(right, false, i);
}
void add(int pos) {
  while (pos <= mxRgt) {
    treeArr[pos]++;
    pos += (pos & (-pos));
  }
}
void sub(int pos) {
  while (pos <= mxRgt) {
    treeArr[pos]--;
    pos += (pos & (-pos));
  }
}
int sum(int pos) {
  int rtn = 0;
  while (pos) {
    rtn += treeArr[pos];
    pos -= (pos & (-pos));
  }
  return rtn;
}
void getResult(int j) {
  if (resLoc[queryNodes[j].id] == -1) {
    result[queryNodes[j].id] = sum(queryNodes[j].loc);
    resLoc[queryNodes[j].id] = queryNodes[j].loc;
  } else {
    result[queryNodes[j].id] +=
        sum(queryNodes[j].loc) - sum(resLoc[queryNodes[j].id]);
    resLoc[queryNodes[j].id] = queryNodes[j].loc;
  }
}
void solve(int n) {
  int i, j;
  i = j = 0;
  while (i < n && j < qlen) {
    if (pairNodes[i].pos < queryNodes[j].loc ||
        pairNodes[i].pos == queryNodes[j].loc && pairNodes[i].lr) {
      pairNodes[i].lr ? add(pairNodes[i].pos)
                      : sub(pairs[pairNodes[i].belong].left);
      i++;
    } else {
      getResult(j++);
    }
  }
  while (j < qlen) {
    getResult(j++);
  }
}
void output(int m) {
  int i;
  for (i = 0; i < m; i++) {
    printf("%d\n", result[i]);
  }
}
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    int cnt, i, j;
    mxRgt = 0;
    for (i = 0; i < n; i++) {
      pairs[i].read(i);
    }
    sort(pairNodes, pairNodes + n * 2);
    for (j = 0; j < m; j++) {
      scanf("%d", &cnt);
      for (i = 0; i < cnt; i++) {
        queryNodes[qlen++].read(j);
      }
    }
    sort(queryNodes, queryNodes + qlen);
    memset(treeArr, 0, sizeof(treeArr));
    memset(resLoc, -1, sizeof(resLoc));
    solve(n << 1);
    output(m);
  }
  return 0;
}
