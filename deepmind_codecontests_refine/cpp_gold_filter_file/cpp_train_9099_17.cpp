#include <bits/stdc++.h>
using namespace std;
const int maxn = 7005, maxp = 2e6;
int n, m;
struct node {
  int l, r, x;
};
vector<node> v[maxn];
int ls[maxp], rs[maxp];
void prepare() {
  for (int i = 0; i <= 20; i++) ls[1 << i] = 1;
  for (int i = 1, cnt = 1; i < maxp; i++) {
    if (ls[i]) {
      ls[i] = cnt;
      rs[i] = cnt + 1;
      cnt += 2;
    } else {
      ls[i] = -1;
      rs[i] = cnt;
      cnt++;
    }
  }
};
set<int> cnt;
void ask(int t, int l, int r) {
  for (int i = 0; i < (int)v[t].size(); i++) {
    if (v[t][i].l <= r && v[t][i].r >= l) cnt.insert(v[t][i].x);
  }
  if (t < n) ask(t + 1, ls[l] == -1 ? rs[l] : ls[l], rs[r]);
}
int main() {
  scanf("%d%d", &n, &m);
  prepare();
  for (int i = 1; i <= m; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int t, l, r, x;
      scanf("%d%d%d%d", &t, &l, &r, &x);
      v[t].push_back(node{l, r, x});
    } else {
      int t, v;
      scanf("%d%d", &t, &v);
      cnt.clear();
      ask(t, v, v);
      printf("%d\n", (int)cnt.size());
    }
  }
  return 0;
}
