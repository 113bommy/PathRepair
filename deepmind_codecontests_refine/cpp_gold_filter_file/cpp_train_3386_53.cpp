#include <bits/stdc++.h>
using namespace std;
const int o = 1 << 18;
const int maxn = 200005;
int n;
int arr[maxn], tmpp[maxn], t[o * 2];
long long org, sol;
long long pref[maxn];
void down(int x) {
  if (t[x] && x < o) {
    t[x * 2] = t[x];
    t[x * 2 + 1] = t[x];
    t[x] = 0;
  }
}
void update(int x, int lo, int hi, int a, int b, int val) {
  down(x);
  if (lo >= a && hi <= b) {
    t[x] = val;
    return;
  }
  if (lo >= b || hi <= a) return;
  int mid = (lo + hi) / 2;
  update(x * 2, lo, mid, a, b, val);
  update(x * 2 + 1, mid, hi, a, b, val);
}
int query(int x, int lo, int hi, int y) {
  down(x);
  if (lo == hi - 1) return t[x];
  int mid = (lo + hi) / 2;
  if (y < mid) return query(x * 2, lo, mid, y);
  return query(x * 2 + 1, mid, hi, y);
}
long long val(int lo, int hi) {
  return (long long)(hi - lo) * arr[lo] + pref[lo] - pref[hi];
}
inline void solve(int d) {
  update(1, 0, o, 2, n + 1, 1);
  for (int i = 2; i <= n; i++) {
    long long tmp = query(1, 0, o, i);
    sol = max(sol, val(tmp, i) * d);
    int lo = i + 1, hi = n;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      int tmp = query(1, 0, o, mid);
      if (val(i, mid) * d >= val(tmp, mid) * d)
        hi = mid;
      else {
        if (val(i, i) * d > val(tmp, i) * d)
          hi = mid - 1;
        else
          lo = mid + 1;
      }
    }
    if (val(i, lo) * d < val(query(1, 0, o, lo), lo) * d) continue;
    int LO = lo;
    hi = n;
    while (lo < hi) {
      int mid = (lo + hi + 1) / 2;
      int tmp = query(1, 0, o, mid);
      if (val(i, mid) * d >= val(tmp, mid) * d)
        lo = mid;
      else
        hi = mid - 1;
    }
    update(1, 0, o, LO, lo + 1, i);
  }
}
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    tmpp[n - i + 1] = arr[i];
    pref[i] = pref[i - 1] + arr[i];
    org += (long long)i * arr[i];
  }
  solve(1);
  for (int i = 1; i <= n; i++) {
    arr[i] = tmpp[i];
    pref[i] = pref[i - 1] + arr[i];
  }
  memset(t, 0, sizeof t);
  solve(-1);
  printf("%I64d\n", org + sol);
  return 0;
}
