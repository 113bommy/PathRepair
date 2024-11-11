#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int f[maxn];
int low[maxn];
int a[maxn][3];
int bs(int* f, int r, int t) {
  int l = 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (f[mid] <= t)
      l = mid + 1;
    else
      r = mid;
  }
  return l;
}
int main() {
  int n[3];
  cin >> n[0] >> n[1] >> n[2];
  for (int i = 0; i < 3; i++)
    for (int j = 1; j <= n[i]; j++) {
      cin >> a[i][j];
    }
  int cnt = 0;
  for (int i = 0; i < 3; i++) {
    sort(a[i] + 1, a[i] + 1 + n[i]);
    for (int j = 1; j <= n[i]; j++) {
      f[++cnt] = a[i][j];
    }
  }
  int m = n[0] + n[1] + n[2];
  low[1] = f[1];
  int ans = 1;
  for (int i = 2; i <= m; i++) {
    if (f[i] > low[ans])
      low[++ans] = f[i];
    else
      low[bs(low, ans, f[i])] = f[i];
  }
  cout << m - ans << endl;
}
