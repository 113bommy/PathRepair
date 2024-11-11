#include <bits/stdc++.h>
using namespace std;
long long a[100010], b[100010], tmp[100010];
int n, tot;
long long k;
int root[100010], ls[100010 * 20], rs[100010 * 20], sum[100010 * 20];
void insert(int proot, int &now, int l, int r, int po) {
  now = ++tot;
  sum[now] = sum[proot] + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (po > mid) {
    ls[now] = ls[proot];
    insert(rs[proot], rs[now], mid + 1, r, po);
  } else {
    rs[now] = rs[proot];
    insert(ls[proot], ls[now], l, mid, po);
  }
}
long long query(int right, int l, int r, long long x) {
  if (l == r) {
    if (tmp[l] <= x)
      return sum[right];
    else
      return 0;
  }
  int mid = (l + r) >> 1;
  if (tmp[mid] <= x) {
    return sum[ls[right]] + query(rs[right], mid + 1, r, x);
  } else
    return query(ls[right], l, mid, x);
}
int search(int n, long long x) {
  int mi = 1, ma = n, mid;
  while (mi <= ma) {
    mid = (mi + ma) >> 1;
    if (tmp[mid] == x) return mid;
    if (tmp[mid] > x)
      ma = mid - 1;
    else
      mi = mid + 1;
  }
  return 0;
}
int main() {
  tot = 0;
  scanf("%d%I64d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    b[i] = a[i] + b[i - 1];
  }
  sort(b, b + n + 1);
  int end = 0;
  tmp[++end] = b[0];
  for (int i = 1; i <= n; i++) {
    if (b[i] != b[i - 1]) tmp[++end] = b[i];
  }
  b[0] = 0;
  for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
  for (int i = 0; i <= n; i++) {
    if (i == 0) {
      insert(0, root[0], 1, end, search(end, b[i]));
    } else {
      insert(root[i - 1], root[i], 1, end, search(end, b[i]));
    }
  }
  long long mi = -100000000000000LL, ma = -mi, mid;
  long long ans = 0;
  while (mi <= ma) {
    mid = (mi + ma) >> 1;
    long long s = 0;
    for (int j = 1; j <= n; j++) {
      long long x = query(root[j - 1], 1, end, b[j] - mid);
      s += x;
    }
    if (s >= k) {
      ans = mid;
      mi = mid + 1;
    } else
      ma = mid - 1;
  }
  printf("%I64d\n", ans);
  return 0;
}
