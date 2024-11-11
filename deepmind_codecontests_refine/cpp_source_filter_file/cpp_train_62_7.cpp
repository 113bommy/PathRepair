#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int sz;
long long tree[400005];
void update(int idx, long long val) {
  idx += sz;
  while (idx) {
    tree[idx] = max(tree[idx], val);
    idx /= 2;
  }
}
long long query(int a, int b) {
  a += sz;
  b += sz;
  long long ret = -inf;
  while (a <= b) {
    if (a & 1) ret = max(ret, tree[a++]);
    if (!(b & 1)) ret = max(ret, tree[b--]);
    a /= 2;
    b /= 2;
  }
  return ret;
}
int n, d;
int arr[100005];
long long sum[100005];
int main() {
  for (int i = 0; i < 400005; i++) tree[i] = -inf;
  scanf("%d%d", &n, &d);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  sum[0] = arr[0];
  for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + arr[i];
  sz = 1;
  while (sz < n) sz *= 2;
  for (int i = 0; i < n; i++) update(i, sum[i]);
  int cnt = 0;
  long long diff = 0;
  for (int i = 0; i < n; i++) {
    if (sum[i] + diff > d) return !printf("-1\n");
    if (arr[i] == 0 && sum[i] + diff < 0) {
      long long q = query(i + 1, n - 1) + diff;
      long long p = -(sum[i] + diff);
      if (d - q < p) return !printf("-1\n");
      cnt++;
      diff += d - q;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
