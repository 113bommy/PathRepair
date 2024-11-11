#include <bits/stdc++.h>
long long int a[262144], b[262144];
int n;
char ans[262144 * 2];
int nans, np;
bool check() {
  for (int i = 0; i < n; ++i)
    if (b[i] < a[i]) return false;
  return true;
}
bool search() {
  while (check()) {
    if (memcmp(a, b, n * sizeof(long long int)) == 0) return true;
    for (int i = n - 1; i; --i) b[i] -= b[i - 1];
    if (nans < 262144 * 2) ans[nans++] = 'P';
    ++np;
    if (memcmp(a, b, n * sizeof(long long int)) == 0) return true;
    if (b[n - 1] <= b[0]) {
      if (nans < 262144 * 2) ans[nans++] = 'R';
      std::reverse(b, b + n);
    }
  }
  return false;
}
long long int count(long long int al, long long int ar, long long int bl,
                    long long int br) {
  long long int res = 0;
  while (al < bl) {
    res += br / bl;
    long long int k = br % bl;
    br = bl, bl = k;
  }
  if (al > bl) return -1;
  assert(al == bl);
  return (br - ar) % bl == 0 ? res + (br - ar) / bl : -1;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%lld", &b[i]);
  bool fa = false, fb = false;
  if (a[n - 1] <= a[0]) std::reverse(a, a + n), fa = true;
  if (b[n - 1] <= b[0]) std::reverse(b, b + n), fb = true;
  if (n == 1 && a[0] != b[0]) return puts("IMPOSSIBLE"), 0;
  if (n == 2) {
    long long int res = count(a[0], a[1], b[0], b[1]);
    if (res == -1) return puts("IMPOSSIBLE"), 0;
    if (res > (long long int)2e5) return printf("BIG\n%lld\n", res), 0;
  }
  bool res = search();
  if (!res) return puts("IMPOSSIBLE");
  if (np > (int)2e5) return printf("BIG\n%d\n", np), 0;
  puts("SMALL");
  if (fa) ans[nans++] = 'R';
  std::reverse(ans, ans + nans);
  if (fb) ans[nans++] = 'R';
  ans[nans] = 0;
  printf("%d\n%s\n", nans, ans);
  return 0;
}
