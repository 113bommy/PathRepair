#include <bits/stdc++.h>
using namespace std;
typedef struct node {
  int p;
  int t;
  node() {}
  node(int _p, int _t) : p(_p), t(_t) {}
} node;
bool cmp(node x, node y) {
  if (x.p == y.p) return x.t < y.t;
  return x.p > y.p;
}
int main(int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;
  k--;
  vector<node> vp;
  int i;
  for (i = 0; i < n; ++i) {
    int p, t;
    cin >> p >> t;
    vp.push_back(node(p, t));
  }
  sort(vp.begin(), vp.end(), cmp);
  int ans = 0;
  for (i = 0; i < vp.size(); ++i)
    if (vp[k].p == vp[i].p && vp[k].t == vp[i].t) ++ans;
  cout << ans << endl;
  return 0;
}
