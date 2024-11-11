#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, k, a[N];
bool ok1(int x) {
  int kk = k;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] <= x) return 1;
    kk -= a[i] - x;
    if (kk < 0) return 0;
  }
  return 1;
}
bool ok2(int x) {
  int kk = k;
  for (int i = 0; i < n; i++) {
    if (a[i] >= x) return 1;
    kk -= x - a[i];
    if (kk < 0) return 0;
  }
  return 1;
}
int s_max() {
  int l = a[0], r = a[n - 1];
  while (l + 1 != r) {
    int mid = (l + r) / 2;
    if (ok1(mid))
      r = mid;
    else
      l = mid;
  }
  if (ok1(l))
    return l;
  else
    return r;
}
int s_min() {
  int l = a[0], r = a[n - 1];
  while (l + 1 != r) {
    int mid = (l + r) / 2;
    if (ok2(mid))
      l = mid;
    else
      r = mid;
  }
  if (ok2(r))
    return r;
  else
    return l;
}
int main() {
  scanf("%d%d", &n, &k);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  sort(a, a + n);
  int ans;
  if (a[0] == a[n - 1])
    ans = 0;
  else {
    int max_min = s_max(), min_max = s_min();
    if (min_max >= max_min)
      ans = (sum % n != 0);
    else
      ans = max_min - min_max;
  }
  cout << ans << endl;
  return 0;
}
