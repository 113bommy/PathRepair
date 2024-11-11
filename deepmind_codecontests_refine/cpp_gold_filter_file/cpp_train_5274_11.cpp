#include <bits/stdc++.h>
using namespace std;
double a[100006];
long long int u, n;
int binary(int i) {
  int start = i + 2;
  int end = n - 1;
  while (end - start > 6) {
    int mid = (start + end) / 2;
    if (a[mid] - a[i] < u) {
      start = mid;
    } else if (a[mid] - a[i] > u) {
      end = mid;
    } else if (a[mid] - a[i] == u)
      return mid;
  }
  int dif = 0;
  int idx = i;
  for (int j = start; j <= end; ++j) {
    if (a[j] - a[i] > dif && a[j] - a[i] <= u) {
      dif = a[j] - a[i];
      idx = j;
    }
  }
  if (idx != i) return idx;
  return -1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int i, j;
  cin >> n >> u;
  for (i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  double ans = 0, val = 0;
  int flag = -1;
  for (i = 1; i < n - 1; ++i) {
    int idx = binary(i - 1);
    if (idx == -1) continue;
    flag = 0;
    val = (a[idx] - a[i]) / (a[idx] - a[i - 1]);
    if (val > ans) ans = val;
  }
  if (flag == -1)
    cout << flag << "\n";
  else
    cout << fixed << setprecision(9) << ans << "\n";
  return 0;
}
