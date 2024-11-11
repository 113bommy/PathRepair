#include <bits/stdc++.h>
using namespace std;
int n, m, k = 100005, s, a[100005];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int l, r, d;
    cin >> l >> r;
    d = r - l + 1;
    if (d < k) {
      s = l;
      k = d;
    }
  }
  cout << k << endl;
  a[s] = 0;
  for (int i = s + 1; i <= n; i++) {
    a[i] = a[i - 1] + 1;
    if (a[i] == k) a[i] = 0;
  }
  for (int i = s - 1; i >= 1; i--) {
    a[i] = a[i + 1] - 1;
    if (a[i] == -1) a[i] = k - 1;
  }
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  cout << endl;
  return 0;
}
