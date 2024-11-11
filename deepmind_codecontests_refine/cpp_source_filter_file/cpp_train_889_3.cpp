#include <bits/stdc++.h>
using namespace std;
int a[109], s, qzh[109], n, m, r, l;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    qzh[i] = qzh[i - 1] + a[i];
  }
  for (int i = i; i <= m; i++) {
    cin >> l >> r;
    if (qzh[r] > qzh[l - 1]) s += qzh[r] - qzh[l - 1];
  }
  cout << s;
  return 0;
}
