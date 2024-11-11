#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
const int MOD = 1e9 + 7;
int N, M, Q;
struct Fenwick {
  int bit[MAX];
  int n;
  void init(int _n) {
    n = _n;
    memset(bit, 0, sizeof(bit));
  }
  int lowbit(int x) { return x & (-x); }
  int get(int x) {
    int res = 0;
    while (x) {
      res += bit[x];
      x -= lowbit(x);
    }
    return res;
  }
  void update(int x, int val) {
    while (x <= n) {
      bit[x] += val;
      x += lowbit(x);
    }
  }
  int query(int l, int r) { return get(r) - get(l - 1); }
} tree;
vector<int> xpos[MAX], ypos;
map<int, int> idx, idy, cntx;
int main() {
  int i, j, x, y;
  scanf("%d", &N);
  int num = 0;
  long long res = 0ll;
  tree.init(N);
  for (i = 0; i < N; ++i) {
    scanf("%d%d", &x, &y);
    if (!idy.count(y)) {
      idy[y] = num++;
      ypos.push_back(y);
    }
    xpos[idy[y]].push_back(x);
    cntx[x]++;
  }
  num = 0;
  for (auto it : cntx) {
    idx[it.first] = ++num;
    tree.update(num, 1);
  }
  sort(ypos.begin(), ypos.end());
  for (auto e_y : ypos) {
    sort(xpos[idy[e_y]].begin(), xpos[idy[e_y]].end());
    int pre = 1;
    for (auto e_x : xpos[idy[y]]) {
      res += 1LL * tree.query(pre, idx[e_x]) * tree.query(idx[e_x], num);
      pre = idx[e_x] + 1;
      cntx[e_x]--;
      if (cntx[e_x] == 0) {
        cntx.erase(e_x);
        tree.update(idx[e_x], -1);
      }
    }
  }
  printf("%lld", res);
}
