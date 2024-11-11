#include <bits/stdc++.h>
using namespace std;
int a[100002];
int b[100002];
int c[100002];
int l[100002], r[100002];
int ans[100002];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] <= n) b[a[i]]++;
  }
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i];
  }
  for (int i = 1; i <= n; i++) {
    if (b[i] < i) continue;
    c[0] = 0;
    if (a[0] == i) c[0] = 1;
    for (int j = 0; j < n; j++) {
      c[j] = (a[j] == i ? c[j - 1] + 1 : c[j - 1]);
    }
    for (int j = 0; j < m; j++) {
      if (l[j] == 1) {
        if (c[r[j] - 1] == i) ans[j]++;
      } else if (c[r[j] - 1] - c[l[j] - 2] == i)
        ans[j]++;
    }
  }
  for (int i = 0; i < m; i++) cout << ans[i] << endl;
  return 0;
}
