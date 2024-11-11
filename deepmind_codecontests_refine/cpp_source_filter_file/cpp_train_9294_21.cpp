#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
const long long inf = 100000000;
const long long KOK = 100000;
const long long LOG = 30;
const long long li = 100005;
const long long mod = 1000000007;
int n, m, b[li], a[li], k, flag, t, mx, mpp[li], tree[li * 4], last[li];
int cev;
string s;
set<int> st;
vector<int> v[li];
inline void update(int node, int start, int end, int l, int r, int val) {
  if (start > end || start > r || end < l) return;
  if (start >= l && end <= r) {
    tree[node] = val;
    return;
  }
  update(node * 2, start, ((start + end) / 2), l, r, val),
      update(node * 2 + 1, ((start + end) / 2) + 1, end, l, r, val);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
inline int query(int node, int start, int end, int l, int r) {
  if (start > end || start > r || end < l) return inf;
  if (start >= l && end <= r) return tree[node];
  return min(query(node * 2, start, ((start + end) / 2), l, r),
             query(node * 2 + 1, ((start + end) / 2) + 1, end, l, r));
}
int main(void) {
  scanf("%d", &n);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    mx = max(mx, a[i]);
  }
  if (mx == 1) {
    printf("1\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int at = last[a[i]] + 1;
    if (at < i && a[i] != 1) {
      int bt = query(1, 1, n, 1, a[i] - 1);
      if (bt >= at) b[a[i]] = 1;
    }
    update(1, 1, n, a[i], a[i], i);
    last[a[i]] = i;
  }
  for (int i = 2; i <= n + 1; i++) {
    int at = last[i] + 1;
    if (at < n) {
      int bt = query(1, 1, n, 1, i - 1);
      if (bt >= at) b[i] = 1;
    }
  }
  int ind = n + 1;
  for (int i = 2; i <= n + 1; i++) {
    if (b[i] == 0) {
      ind = i;
      break;
    }
  }
  printf("%d\n", ind);
  return 0;
}
