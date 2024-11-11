#include <bits/stdc++.h>
using namespace std;
long long maxTree[21][610000];
long long lazy[21][610000];
long long input[610000];
long long power(int x, int i) {
  if (i == 1) return x;
  if (i == 0) return 1;
  long long ans = power(x, i / 2);
  if (i % 2 == 0) {
    return ans * ans;
  } else {
    return ans * ans * x;
  }
}
void build(int bit, int i, int l, int r) {
  if (l == r) {
    maxTree[bit][i] = input[l] % 2;
    input[l] /= 2;
    return;
  }
  build(bit, i * 2 + 1, l, (l + r) / 2);
  build(bit, i * 2 + 2, (l + r) / 2 + 1, r);
  maxTree[bit][i] = maxTree[bit][i * 2 + 1] + maxTree[bit][i * 2 + 2];
}
void update(int bit, int i, int l, int r, int s, int e, int v) {
  lazy[bit][i * 2 + 1] ^= lazy[bit][i];
  lazy[bit][i * 2 + 2] ^= lazy[bit][i];
  if (lazy[bit][i] == 1) maxTree[bit][i] = (r - l + 1) - maxTree[bit][i];
  lazy[bit][i] = 0;
  if (l >= s && r <= e) {
    lazy[bit][i * 2 + 1] ^= v;
    lazy[bit][i * 2 + 2] ^= v;
    if (v == 1) maxTree[bit][i] = (r - l + 1) - maxTree[bit][i];
    return;
  } else if (l > e || r < s)
    return;
  int mid = (l + r) / 2;
  update(bit, i * 2 + 1, l, mid, s, e, v);
  update(bit, i * 2 + 2, mid + 1, r, s, e, v);
  maxTree[bit][i] = maxTree[bit][i * 2 + 1] + maxTree[bit][i * 2 + 2];
}
int query(int bit, int i, int l, int r, int s, int e) {
  if (lazy[bit][i] == 1) maxTree[bit][i] = (r - l + 1) - maxTree[bit][i];
  lazy[bit][i * 2 + 1] ^= lazy[bit][i];
  lazy[bit][i * 2 + 2] ^= lazy[bit][i];
  lazy[bit][i] = 0;
  if (l >= s && r <= e) {
    return maxTree[bit][i];
  } else if (l > e || r < s)
    return 0;
  int mid = (l + r) / 2;
  return query(bit, i * 2 + 1, l, mid, s, e) +
         query(bit, i * 2 + 2, mid + 1, r, s, e);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &input[i]);
  }
  for (int i = 0; i < 21; ++i) build(i, 0, 1, n);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int a1, a2;
      scanf("%d%d", &a1, &a2);
      long long ans = 0, kos;
      for (int j = 0; j < 21; ++j) {
        kos = query(j, 0, 1, n, a1, a2);
        ans += kos * power(2, j);
      }
      printf("%I64d", ans);
    } else {
      int a1, a2, a3;
      scanf("%d%d%d", &a1, &a2, &a3);
      for (int j = 0; j < 21; ++j) {
        update(j, 0, 1, n, a1, a2, a3 % 2);
        a3 /= 2;
      }
    }
  }
}
