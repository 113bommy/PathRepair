#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 10;
const int inf = (int)2e9;
int tree[4 * N], arr[N], pos[N], n;
int answer = 0;
void build(int node, int b, int e) {
  if (b == e) {
    tree[node] = b;
    return;
  }
  int lft = 2 * node, rt = lft + 1, mid = (b + e) / 2;
  build(lft, b, mid);
  build(rt, mid + 1, e);
  if (arr[tree[lft]] > arr[tree[rt]])
    tree[node] = tree[lft];
  else
    tree[node] = tree[rt];
}
int query(int node, int b, int e, int i, int j) {
  if (e < i || b > j) return 0;
  if (b >= i && e <= j) return tree[node];
  int lft = 2 * node, rt = lft + 1, mid = (b + e) / 2;
  int p = query(lft, b, mid, i, j);
  int q = query(rt, mid + 1, e, i, j);
  if (arr[p] > arr[q])
    return p;
  else
    return q;
}
void solve(int l, int r) {
  if (l > r) return;
  int mid = query(1, 1, n, l, r);
  if (mid - l < r - mid) {
    for (int i = l; i < mid; i++) {
      int need = arr[mid] - arr[l];
      if (pos[need] > mid && pos[need] <= r) answer += 1;
    }
  } else {
    for (int i = mid + 1; i <= r; i++) {
      int need = arr[mid] - arr[i];
      if (pos[need] >= l && pos[need] < mid) answer += 1;
    }
  }
  solve(l, mid - 1);
  solve(mid + 1, r);
}
int main() {
  scanf("%d", &n);
  arr[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    pos[arr[i]] = i;
  }
  build(1, 1, n);
  solve(1, n);
  printf("%d\n", answer);
  return 0;
}
