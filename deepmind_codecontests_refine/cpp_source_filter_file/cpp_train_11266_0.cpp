#include <bits/stdc++.h>
using namespace std;
long long mi[1000000], lazy[1000000];
void down(int x) {
  if (lazy[x]) {
    lazy[x * 2] += lazy[x];
    mi[x * 2] += lazy[x];
    lazy[x * 2 + 1] += lazy[x];
    mi[x * 2 + 1] += lazy[x];
    lazy[x] = 0;
  }
}
void add(int root, int l, int r, int L, int R, int v) {
  if (l == L && r == R) {
    mi[root] += v;
    lazy[root] += v;
    return;
  }
  down(root);
  int mid = (l + r) / 2;
  if (R <= mid)
    add(root * 2, l, mid, L, R, v);
  else if (L > mid)
    add(root * 2 + 1, mid + 1, r, L, R, v);
  else {
    add(root * 2, l, mid, L, mid, v);
    add(root * 2 + 1, mid + 1, r, mid + 1, R, v);
  }
  mi[root] = min(mi[root * 2], mi[root * 2 + 1]);
}
void update(int root, int l, int r, int k, long long v) {
  if (l == r) {
    mi[root] = v;
    return;
  }
  int mid = (l + r) / 2;
  if (k <= mid)
    update(root * 2, l, mid, k, v);
  else
    update(root * 2 + 1, mid + 1, r, k, v);
  mi[root] = min(mi[root * 2], mi[root * 2 + 1]);
}
long long A[200010], B[200010], C[200010];
int main() {
  int i, n, a;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &A[i]);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a);
    B[A[i]] = a;
  }
  for (i = 1; i <= n; i++) {
    C[i] = C[i - 1] + B[i];
    update(1, 1, n, i, C[i]);
  }
  long long sum = 0, ans = 1e18;
  for (i = 1; i < n; i++) {
    a = A[i];
    sum += B[a];
    add(1, 1, n, a, n, -2 * B[a]);
    ans = min(ans, sum + mi[1]);
  }
  cout << ans << endl;
  return 0;
}
