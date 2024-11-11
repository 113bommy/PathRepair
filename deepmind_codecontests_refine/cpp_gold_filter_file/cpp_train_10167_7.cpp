#include <bits/stdc++.h>
using namespace std;
struct ac {
  long long val;
  int pos;
  bool operator()(ac x, ac y) {
    if (x.val != y.val) {
      return x.val > y.val;
    } else {
      return x.pos > y.pos;
    }
  }
};
struct wfcmp {};
priority_queue<ac, vector<ac>, ac> que;
vector<ac> ans;
bool cmp(ac &x, ac &y) { return x.pos < y.pos; }
int n;
void solve() {
  int i, j, k;
  while (!que.empty()) {
    que.pop();
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &k);
    ac x;
    x.pos = i;
    x.val = k;
    que.push(x);
  }
  ans.clear();
  int c = 0;
  ac x, y;
  x = que.top();
  que.pop();
  while (!que.empty()) {
    y = que.top();
    que.pop();
    if (x.val != y.val) {
      ans.push_back(x);
      x = y;
      continue;
    }
    ac p;
    p.val = x.val * 2;
    p.pos = y.pos;
    que.push(p);
    x = que.top();
    que.pop();
  }
  ans.push_back(x);
  sort(ans.begin(), ans.end(), cmp);
  printf("%d\n", ans.size());
  for (i = 0; i < ans.size(); i++) {
    printf("%lld ", ans[i].val);
  }
  printf("\n");
}
int main() {
  while (scanf("%d", &n) != EOF) {
    solve();
  }
  return 0;
}
