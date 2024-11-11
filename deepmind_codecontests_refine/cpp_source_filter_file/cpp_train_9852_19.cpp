#include <bits/stdc++.h>
using namespace std;
int n, m, c, d, k, x = 0;
int rage(int x) { return min(n, max(1, x)); }
int find(int a[], int x) {
  int l = 0, u = n - 1, mid;
  while (l < u) {
    mid = l + (u - l) / 2;
    if (a[mid] != -1 && a[mid] <= x)
      l = mid + 1;
    else
      u = mid;
  }
  l = min(l, n - 1);
  return l;
}
int find1(int a[], int x) {
  int l = 0, u = n - 1, mid;
  while (l < u) {
    mid = l + (1 + u - l) / 2;
    if (a[mid] != -1 && a[mid] >= x)
      u = mid - 1;
    else
      l = mid;
  }
  l = max(0, l);
  return l;
}
int main() {
  cin >> n >> m >> c;
  int dp[n];
  for (int i = 0; i < n; i++) dp[i] = -1;
  while (m--) {
    cin >> d;
    if (d < (c / 2))
      k = find(dp, d);
    else
      k = find1(dp, d);
    if (dp[k] == -1) x++;
    dp[k] = d;
    cout << k + 1 << endl;
    fflush(stdout);
    if (x == n) break;
  }
}
