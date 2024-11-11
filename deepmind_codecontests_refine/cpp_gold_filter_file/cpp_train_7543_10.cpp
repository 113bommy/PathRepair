#include <bits/stdc++.h>
using namespace std;
int a[100005], cnt[100005];
int L, R;
int LL, RR;
map<int, int> mp_part, mp_LR;
map<int, int>::iterator it;
long long int ans = 0, n;
bool check_segment(int m, bool left) {
  if (left && m < LL || !left && m >= RR) return false;
  mp_part.clear();
  int len1 = m - L + 1;
  int len2 = R - m;
  if (len1 < len2) {
    for (int i = L; i <= m; ++i) ++mp_part[a[i]];
    for (it = mp_part.begin(); it != mp_part.end(); ++it) {
      if (it->second > (mp_LR[it->first] >> 1)) return false;
    }
  } else {
    for (int i = m + 1; i <= R; ++i) ++mp_part[a[i]];
    for (it = mp_part.begin(); it != mp_part.end(); ++it) {
      if (it->second > (mp_LR[it->first] >> 1)) return false;
    }
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    ++cnt[a[i]];
  }
  int odd_num = 0;
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] & 1) ++odd_num;
    if (odd_num >= 2) {
      printf("0\n");
      return 0;
    }
  }
  L = 1, R = n;
  while (a[L] == a[R] && L < R) {
    ++L;
    --R;
  }
  if (L - R == 0 || L - R == 1) {
    printf("%I64d\n", ((n * (n + 1)) >> 1));
    return 0;
  }
  if ((R - L + 1) & 1)
    LL = RR = (R + L) >> 1;
  else {
    LL = (R + L) >> 1;
    RR = LL + 1;
  }
  while (a[LL] == a[RR]) {
    --LL;
    ++RR;
  }
  for (int i = L; i <= R; ++i) ++mp_LR[a[i]];
  int l = L, r = R;
  int m = l + (r - l) >> 1;
  while (r - l > 4) {
    if (check_segment(m, true)) {
      r = m;
      m = (r + l) >> 1;
    } else {
      l = m;
      m = (r + l) >> 1;
    }
  }
  while (check_segment(r, true)) --r;
  ans -= r - L + 2;
  l = L, r = R, m = l + (r - l) / 2;
  while (r - l > 4) {
    if (check_segment(m, false)) {
      l = m;
      m = (r + l) >> 1;
    } else {
      r = m;
      m = (r + l) >> 1;
    }
  }
  while (check_segment(l, false)) ++l;
  ans -= R - l + 1;
  ans = (ans + (n + 3 * (R - L + 1)) / 2 + 1) * ((n - (R - L + 1)) / 2 + 1);
  printf("%I64d\n", ans);
  return 0;
}
