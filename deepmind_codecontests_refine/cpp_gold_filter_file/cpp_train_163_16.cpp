#include <bits/stdc++.h>
using namespace std;
long long n, k, p;
struct node {
  long long pos, what;
} A[3010], B[3010];
bool cmp1(node x, node y) { return x.pos < y.pos; }
bool cmp2(node x, node y) { return abs(x.pos - p) > abs(y.pos - p); }
bool check(long long mid) {
  long long l = 1, r = k;
  for (register long long i = 1; i <= n; i++) {
    if (A[i].pos < p) {
      while (abs(A[i].pos - B[l].pos) + abs(B[l].pos - p) > mid) l++;
      if (l > r) return false;
      l++;
    } else {
      while (abs(A[i].pos - B[r].pos) + abs(B[r].pos - p) > mid) r--;
      if (l > r) return false;
      r--;
    }
  }
  return true;
}
signed main() {
  scanf("%lld%lld%lld", &n, &k, &p);
  for (register long long i = 1; i <= n; i++) {
    long long pos;
    scanf("%lld", &A[i].pos);
    A[i].what = 1;
  }
  for (register long long i = 1; i <= k; i++) {
    long long pos;
    scanf("%lld", &B[i].pos);
    B[i].what = 2;
  }
  sort(A + 1, A + n + 1, cmp2);
  sort(B + 1, B + k + 1, cmp1);
  long long l = 0, r = 3e9 + 10, mid, res;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid)) {
      res = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%lld", res);
  return 0;
}
