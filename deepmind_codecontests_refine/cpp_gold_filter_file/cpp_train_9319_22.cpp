#include <bits/stdc++.h>
using namespace std;
long long a[1005], b[1005];
long long sum(int l, int r) {
  long long aa = a[l], bb = b[l];
  for (int i = l + 1; i <= r; ++i) {
    aa = aa | a[i];
    bb = bb | b[i];
  }
  return aa + bb;
}
int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      ans = max(sum(i, j), ans);
    }
  }
  printf("%lld\n", ans);
}
