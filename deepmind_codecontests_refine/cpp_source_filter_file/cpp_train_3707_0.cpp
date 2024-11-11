#include <bits/stdc++.h>
using namespace std;
const int MX = 35005;
int dp[MX], tree[5 * MX], lasy[5 * MX], n, k, ar[MX], last[MX];
int st, en;
void push(int x) {
  if (2 * x < 3 * MX) tree[2 * x] += lasy[x], lasy[2 * x] += lasy[x];
  if (2 * x + 1 < 3 * MX)
    tree[2 * x + 1] += lasy[x], lasy[2 * x + 1] += lasy[x];
  lasy[x] = 0;
}
void update(int x = 1, int l = 0, int r = n) {
  push(x);
  if (st > en) return;
  if (st > r || en < l) return;
  if (st <= l && r <= en) {
    tree[x]++;
    lasy[x]++;
    return;
  }
  update(2 * x, l, (l + r) / 2);
  update(2 * x + 1, (l + r) / 2 + 1, r);
  tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
}
int val;
void insert(int x = 1, int l = 0, int r = n) {
  push(x);
  if (l > st || r < st) return;
  if (l == r) {
    tree[x] += val;
    return;
  }
  insert(2 * x, l, (l + r) / 2);
  insert(2 * x + 1, (l + r) / 2 + 1, r);
  tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
}
int answer(int x = 1, int l = 0, int r = n) {
  push(x);
  if (l == r) return tree[x];
  if (tree[2 * x] > tree[2 * x + 1])
    return answer(2 * x, l, (l + r) / 2);
  else
    return answer(2 * x + 1, (l + r) / 2 + 1, r);
}
bitset<MX> vis;
int main() {
  scanf("%d", &n);
  scanf("%d", &k);
  for (int i = 1; i <= n; i++) scanf("%d", &ar[i]);
  k--;
  for (int j = 1; j <= k; j++) {
    for (int i = 1; i < j; i++) {
      st = i;
      val = dp[i];
      insert();
      last[ar[i]] = i;
    }
    for (int i = j; i <= n; i++) {
      st = last[ar[i]], en = i - 1;
      update();
      int zbr = answer();
      st = i, val = dp[i];
      insert();
      dp[i] = zbr;
      last[ar[i]] = i;
    }
    memset(tree, 0, sizeof tree);
    memset(lasy, 0, sizeof lasy);
    memset(last, 0, sizeof last);
  }
  int res = 0, cur = 0;
  for (int i = n; i >= 0; i--) {
    res = max(res, dp[i] + cur);
    cur += !vis[ar[i]];
    vis[ar[i]] = 1;
  }
  cout << res;
  return 0;
}
