#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000,100000000")
using namespace std;
const int N = 100005;
struct Node {
  int v, c, l, r;
  void input() { cin >> v >> c >> l >> r; }
} a[N];
int n, dp[N], pre[N];
map<pair<int, int>, pair<int, int> > mx;
map<pair<int, int>, pair<int, int> >::iterator it;
int main() {
  memset(pre, -1, sizeof(pre));
  cin >> n;
  for (int i = 1; i <= n; i++) a[i].input();
  for (int i = 1; i <= n; i++) {
    if (a[i].l == 0)
      dp[i] = a[i].v, pre[i] = 0;
    else {
      it = mx.find(make_pair(a[i].l, a[i].r + a[i].c));
      if (it != mx.end()) {
        dp[i] = a[i].v + it->second.first;
        pre[i] = it->second.second;
      }
    }
    if (dp[i] > 0) {
      it = mx.find(make_pair(a[i].l + a[i].c, a[i].r));
      if (it == mx.end())
        mx[make_pair(a[i].l + a[i].c, a[i].r)] = make_pair(dp[i], i);
      else {
        if (it->second.first < dp[i]) {
          mx[make_pair(a[i].l + a[i].c, a[i].r)] = make_pair(dp[i], i);
        }
      }
    }
  }
  int ans = 0, idx;
  for (int i = 1; i <= n; i++) {
    if (a[i].r == 0) {
      if (dp[i] > ans) {
        ans = dp[i];
        idx = i;
      }
    }
  }
  if (ans == 0) {
    puts("0");
  } else {
    vector<int> ret;
    while (idx) {
      ret.push_back(idx);
      idx = pre[idx];
    }
    cout << ret.size() << endl;
    for (int i = ret.size() - 1; i >= 0; i--)
      cout << ret[i] << (i == 0 ? '\n' : ' ');
  }
  return 0;
}
