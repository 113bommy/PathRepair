#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N], pre[N], nho[N], lon[N], nhom[N], b[N], vt[N];
bool cmp(int i, int j) { return b[i] < b[j]; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, h;
  cin >> n >> h;
  if (n == 2) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    vt[i] = i;
  }
  sort(vt, vt + n, cmp);
  for (int i = 0; i < n; i++) a[i] = b[vt[i]];
  int ans = a[n - 1] + a[n - 2] - a[0] - a[1];
  int ans1 = 0, ans2 = -1;
  int tmp = max(a[n - 1] + a[n - 2], a[n - 1] + a[0] + h) -
            min(a[1] + a[2], a[0] + a[1] + h);
  if (tmp < ans) {
    ans = tmp;
    ans1 = 0;
    ans2 = 0;
  }
  nho[1] = a[0] + a[1];
  nho[2] = min(a[0] + a[2], a[0] + a[1] + h);
  for (int i = 3; i < n; i++)
    nho[i] = min(min(a[0] + a[1] + h, a[1] + a[2]), a[0] + a[i]);
  pre[1] = 1;
  for (int i = 2; i < n; i++) {
    pre[i] = pre[i - 1];
    if (nho[i] > nho[pre[i]]) pre[i] = i;
  }
  lon[n - 2] = a[n - 1] + a[n - 2] + h;
  lon[n - 3] = max(a[n - 1] + a[n - 2], a[n - 1] + a[n - 3] + h);
  for (int i = n - 4; i >= 0; i--)
    lon[i] = max(a[n - 1] + a[n - 2], a[n - 1] + a[i] + h);
  for (int i = 1; i < n - 1; i++) {
    if (ans > lon[i] - nho[pre[i]]) {
      ans = lon[i] - nho[pre[i]];
      ans1 = pre[i];
      ans2 = i;
    }
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++) nhom[i] = 1;
  for (int i = 1; i < ans1; i++) nhom[vt[i]] = 2;
  if (ans2 >= ans1) {
    for (int i = ans2 + 1; i < n; i++) nhom[vt[i]] = 3 - nhom[vt[ans2]];
  }
  for (int i = 0; i < n; i++) cout << nhom[i] << ' ';
  return 0;
}
