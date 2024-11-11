#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
const int inf = 2000000005;
int n, a[N];
int mx[N], mn[N], rec[N];
long long ans = 0;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void Prepare(int L, int R, int mid) {
  for (register int i = L; i <= R; ++i) mx[i] = -inf, mn[i] = inf;
  mx[mid] = mn[mid] = a[mid];
  for (int i = mid - 1; i >= L; --i) {
    mx[i] = ((a[i]) > (mx[i + 1]) ? (a[i]) : (mx[i + 1]));
    mn[i] = ((a[i]) < (mn[i + 1]) ? (a[i]) : (mn[i + 1]));
  }
  mx[mid + 1] = mn[mid + 1] = a[mid + 1];
  for (int i = mid + 2; i <= R; ++i) {
    mx[i] = ((a[i]) > (mx[i - 1]) ? (a[i]) : (mx[i - 1]));
    mn[i] = ((a[i]) > (mn[i - 1]) ? (a[i]) : (mn[i - 1]));
  }
}
inline void Solve(int L, int R) {
  if (L == R) {
    return ++ans, void();
  }
  int mid = (L + R) >> 1;
  Solve(L, mid);
  Solve(mid + 1, R);
  Prepare(L, R, mid);
  for (int l = L; l <= mid; ++l) {
    int r = l + mx[l] - mn[l];
    if ((r >= mid + 1) && (r <= R) && (mx[l] > mx[r]) && (mn[l] < mn[r])) ++ans;
  }
  for (int r = mid + 1; r <= R; ++r) {
    int l = r - mx[r] + mn[r];
    if ((l >= L) && (l <= mid) && (mx[l] < mx[r]) && (mn[l] > mn[r])) ++ans;
  }
  int p1 = mid + 1, p2 = mid + 1;
  for (int i = mid; i >= L; --i) {
    while ((p1 <= R) && (mn[p1] > mn[i])) ++rec[mx[p1] - p1 + n], ++p1;
    while ((p2 < p1) && (mx[p2] < mx[i])) --rec[mx[p2] - p2 + n], ++p2;
    ans += (long long)(rec[mn[i] - i + n]);
  }
  while (p2 < p1) --rec[mx[p2] - p2 + n], ++p2;
  p1 = mid, p2 = mid;
  for (int i = mid + 1; i <= R; ++i) {
    while ((p1 >= L) && (mn[p1] > mn[i])) ++rec[mx[p1] + p1], --p1;
    while ((p1 < p2) && (mx[p2] < mx[i])) --rec[mx[p2] + p2], --p2;
    ans += (long long)(rec[mn[i] + i]);
  }
  while (p1 < p2) --rec[mx[p2] + p2], --p2;
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    int x = read(), y = read();
    a[x] = y;
  }
  Solve(1, n);
  printf("%lld\n", ans);
  return 0;
}
