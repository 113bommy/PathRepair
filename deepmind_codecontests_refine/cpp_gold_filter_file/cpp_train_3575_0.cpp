#include <bits/stdc++.h>
using namespace std;
int n, g, r, q;
int l[411111];
int delay[411111];
long long s[411111];
long long f[411111];
int lch[222222], rch[222222], minV[222222], size;
int lis[222222], ln;
int MOD(int x) { return ((r + g) + x % (r + g)) % (r + g); }
int make(int b, int e) {
  int cur = ++size;
  if (b == e) {
    minV[cur] = 1000000000;
    return cur;
  }
  int mid = b + e >> 1;
  lch[cur] = make(b, mid);
  rch[cur] = make(mid + 1, e);
  minV[cur] = 1000000000;
  return cur;
}
void insert(int pos, int x, int b, int e, int r) {
  minV[r] = min(x, minV[r]);
  if (b == e) {
    return;
  }
  int mid = b + e >> 1;
  if (pos <= mid) {
    insert(pos, x, b, mid, lch[r]);
  } else {
    insert(pos, x, mid + 1, e, rch[r]);
  }
}
int get(int B, int E, int b, int e, int r) {
  if (E < b || e < B) {
    return 1000000000;
  }
  if (B <= b && e <= E) {
    return minV[r];
  }
  int ret = 1000000000;
  int mid = b + e >> 1;
  if (B <= mid) ret = min(ret, get(B, E, b, mid, lch[r]));
  if (mid + 1 <= E) ret = min(ret, get(B, E, mid + 1, e, rch[r]));
  return ret;
}
int getIdx(int x) { return lower_bound(lis, lis + ln, x) - lis; }
int firstLEThan(int t) { return lower_bound(lis, lis + ln, t) - lis; }
int firstSEThan(int t) { return upper_bound(lis, lis + ln, t) - lis - 1; }
int signal(int x) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }
int findMin(int b, int e) {
  b = MOD(b);
  e = MOD(e);
  int sgn = signal(b - e);
  b = firstLEThan(b);
  e = firstSEThan(e);
  if (signal(b - e) == 1 && sgn <= 0) {
    return 1000000000;
  }
  if (b > e) {
    return min(get(b, ln - 1, 0, ln - 1, 1), get(0, e, 0, ln - 1, 1));
  } else {
    return get(b, e, 0, ln - 1, 1);
  }
}
int main() {
  scanf("%d%d%d", &n, &g, &r);
  for (int i = 0; i <= n; i++) {
    scanf("%d", l + i);
  }
  s[0] = 0;
  for (int i = 1; i <= n + 1; i++) {
    s[i] = s[i - 1] + l[i - 1];
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", delay + i);
  }
  lis[ln++] = -2;
  lis[ln++] = -1;
  lis[ln++] = r + g;
  lis[ln++] = r + g + 1;
  for (int i = 0; i <= n + 1; i++) {
    int k_i = s[i] % (r + g);
    lis[ln++] = MOD(k_i);
  }
  sort(lis, lis + ln);
  ln = unique(lis, lis + ln) - lis;
  make(0, ln - 1);
  for (int i = n; i >= 1; --i) {
    int k_i = s[i] % (g + r);
    int t = findMin(k_i - r, k_i - 1);
    if (t == 1000000000) {
      f[i] = s[n + 1] - s[i];
    } else {
      long long tmp = s[t] - s[i];
      tmp = (tmp + r + g - 1) / (r + g) * (r + g);
      f[i] = tmp + f[t];
    }
    insert(getIdx(k_i), i, 0, ln - 1, 1);
  }
  for (int i = 0; i < q; i++) {
    int k_i = (g + r - delay[i] % (g + r)) % (g + r);
    int t = findMin(k_i - r, k_i - 1);
    long long ans = 0;
    if (t == 1000000000) {
      ans = s[n + 1] + delay[i];
    } else {
      long long tmp = s[t] + delay[i];
      tmp = (tmp + r + g - 1) / (r + g) * (r + g);
      ans = tmp + f[t];
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
