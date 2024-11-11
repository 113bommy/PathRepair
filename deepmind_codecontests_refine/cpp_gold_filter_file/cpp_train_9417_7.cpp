#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p);
int Bit(long long x);
long long Sum(int x);
inline int D() {
  int t;
  scanf("%d", &t);
  return t;
}
inline long long llD() {
  long long t;
  scanf("%lld", &t);
  return t;
}
const int N = 1e6 + 5;
int arr[N], a;
bool mp[N];
int l, r, mid, n, m, x, y, mx = -1, ans = -1;
int BS(int idx) {
  l = 0, r = n - 1, mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (arr[mid] >= idx)
      r = mid;
    else
      l = mid + 1;
  }
  if (arr[r] >= idx) return r - 1;
  return r;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    if (!mp[a]) arr[y++] = a;
    mp[a] = true;
    mx = max(a, mx);
  }
  n = y;
  sort(arr, arr + n);
  for (int i = 0; i < n; ++i) {
    for (int j = 2 * arr[i]; j <= mx; j += arr[i]) {
      x = lower_bound(arr, arr + n, j) - arr - 1;
      ans = max(arr[x] % arr[i], ans);
    }
    ans = max(arr[n - 1] % arr[i], ans);
  }
  printf("%d", ans);
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int Bit(long long x) {
  if (!x) return 0;
  return 1 + Bit(x >> 1);
}
long long Sum(int x) { return (1ll * x * (x + 1)) >> 1ll; }
