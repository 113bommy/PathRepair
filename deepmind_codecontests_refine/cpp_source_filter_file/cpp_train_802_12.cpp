#include <bits/stdc++.h>
using namespace std;
const int Max = 5e5 + 10;
const int Mod = 1e9 + 7;
const long long int Inf = 1LL << 62;
int ar[Max];
int dp[Max];
int seg[Max * 4];
int update(int node, int l, int r, int idx) {
  if (l == r) {
    seg[node] = 1;
    return seg[node];
  }
  int mid = (l + r) >> 1, u = seg[node * 2], v = seg[node * 2 + 1];
  if (mid >= idx) {
    u = update(2 * node, l, mid, idx);
  } else {
    v = update(2 * node + 1, mid + 1, r, idx);
  }
  return seg[node] = u + v;
}
int query(int node, int l, int r, int L, int R) {
  if (R < l || L > r) {
    return 0;
  }
  if (L <= l && r <= R) {
    return seg[node];
  }
  int mid = (l + r) >> 1;
  int u = query(node * 2, l, mid, L, R);
  int v = query(node * 2 + 1, mid + 1, r, L, R);
  return u + v;
}
int main() {
  int n, k, d;
  scanf("%d %d %d", &n, &k, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ar[i]);
  }
  sort(ar + 1, ar + n + 1);
  update(1, 1, n + 1, 1);
  dp[1] = 1;
  int pos = 1;
  for (int i = 1; i <= n; i++) {
    while (pos < i && ar[i] - ar[pos] > d) {
      pos++;
    }
    dp[i + 1] = query(1, 1, n + 1, pos, i - k + 1);
    if (dp[i + 1]) {
      update(1, 1, n, i + 1);
    }
  }
  if (dp[n + 1]) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
