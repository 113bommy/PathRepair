#include <bits/stdc++.h>
using namespace std;
stringstream ss;
int a[100010], prev[100010], st[100010];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int sz = 0, res = 0;
  for (int i = 1; i <= n; i++) {
    while (sz && st[sz - 1] < a[i]) res = max(res, a[i] ^ st[--sz]);
    if (sz) res = max(res, a[i] ^ st[sz - 1]);
    st[sz++] = a[i];
  }
  sz = 0;
  for (int i = n; i >= 1; i--) {
    while (sz && st[sz - 1] < a[i]) res = max(res, a[i] ^ st[--sz]);
    if (sz) res = max(res, a[i] ^ st[sz - 1]);
    st[sz++] = a[i];
  }
  cout << res << endl;
  return 0;
}
