#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long INF = 1e9 + 10;
int a[N], b[N], n, c;
int check(long long x) {
  long long second = 0;
  for (int i = 0; i < n; i++) {
    second += 1 + x * a[i] / b[i];
    if (second > c) return 1;
  }
  if (second == c) return 0;
  return -1;
}
int main() {
  cin >> n >> c;
  if (n > c) {
    cout << 0;
    return 0;
  }
  bool allNill = true;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    allNill &= a[i] == 0;
  }
  if (allNill) {
    if (n == c)
      cout << -1;
    else
      cout << 0;
    return 0;
  }
  long long l = 0, r = INF, mid, ff;
  while (l < r - 1) {
    mid = (l + r) / 2;
    if (check(mid) >= 0)
      r = mid;
    else
      l = mid;
  }
  ff = l;
  r = INF;
  while (l < r - 1) {
    mid = (l + r) / 2;
    if (check(mid) == 0)
      l = mid;
    else
      r = mid;
  }
  cout << l - ff;
  return 0;
}
