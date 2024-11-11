#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, arr[N], arr2[N], seg[4 * N], lazy[4 * N];
inline void fix(int s, int e, int idx) {
  seg[idx] += lazy[idx];
  if (s != e) {
    seg[(idx << 1)] += lazy[idx];
    seg[(idx << 1) + 1] += lazy[idx];
  }
  lazy[idx] = 0;
}
int build(int s, int e, int idx) {
  if (s == e) return seg[idx] = arr2[s];
  return seg[idx] = max(build(s, ((s + e) >> 1), (idx << 1)),
                        build(((s + e) >> 1) + 1, e, (idx << 1) + 1));
}
int l, r, val;
inline int update(int s, int e, int idx) {
  fix(s, e, idx);
  if (s > r || e < l) return seg[idx];
  if (s >= l && e <= r) {
    lazy[idx] += val;
    fix(s, e, idx);
    return seg[idx];
  }
  return seg[idx] = max(update(s, ((s + e) >> 1), (idx << 1)),
                        update(((s + e) >> 1) + 1, e, (idx << 1) + 1));
}
int s, e, idx, mid;
inline int Lower_bound(int val) {
  s = 0, e = n, idx = 1;
  while (true) {
    fix(s, e, idx);
    if (s == e) return s;
    mid = ((s + e) >> 1);
    fix(s, mid, (idx << 1));
    fix(mid + 1, e, (idx << 1) + 1);
    if (seg[(idx << 1)] >= val) {
      idx = (idx << 1);
      e = mid;
    } else {
      idx = (idx << 1) + 1;
      s = mid + 1;
    }
  }
  assert(false);
}
int Idx;
inline int get() {
  s = 0, e = n, idx = 1;
  while (true) {
    fix(s, e, idx);
    if (s == e) return seg[idx];
    mid = ((s + e) >> 1);
    if (Idx <= mid) {
      idx = (idx << 1);
      e = mid;
    } else {
      idx = (idx << 1) + 1;
      s = mid + 1;
    }
  }
  assert(false);
}
int tmp1, tmp2, tmp3, tmp4, tmp5;
int tmp7 = 0, tmp8 = 0;
void check2(int cur) {
  for (int i = 1; i <= 4 * (n + 1); i++) seg[i] = lazy[i] = 0;
  arr[n] = cur;
  for (int i = 0; i <= n; i++) {
    arr2[i] = arr[i];
  }
  sort(arr2, arr2 + n + 1);
  build(0, n, 1);
  tmp7 = 0;
  for (int i = n; i >= 0; i--) {
    Idx = i;
    tmp1 = get();
    if (tmp1 <= 0) {
      tmp7 -= tmp1;
      continue;
    }
    if (i - tmp1 < 0) {
      l = 0, r = i - 1, val = -1;
      update(0, n, 1);
      tmp7 -= (i - tmp1);
      continue;
    }
    Idx = i - tmp1;
    tmp2 = get();
    tmp3 = Lower_bound(tmp2);
    Idx = i - 1;
    tmp4 = get();
    if (tmp2 == tmp4) {
      l = tmp3;
      r = tmp3 + tmp1 - 1;
      val = -1;
      update(0, n, 1);
    } else {
      tmp5 = Lower_bound(tmp2 + 1);
      l = tmp5;
      r = i - 1;
      val = -1;
      update(0, n, 1);
      l = tmp3;
      r = l + (tmp5 - (i - tmp1)) - 1;
      val - 1;
      update(0, n, 1);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  check2(0);
  tmp8 = tmp7;
  check2(n);
  tmp7 = n - tmp7;
  if (tmp7 < tmp8) {
    puts("-1");
    return 0;
  }
  for (int i = tmp8; i <= tmp7; i += 2) {
    printf("%d ", i);
  }
  puts("");
  return 0;
}
