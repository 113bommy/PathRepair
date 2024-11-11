#include <bits/stdc++.h>
using namespace std;
const int inf = (int)(1e9 + 7), maxn = (int)(1e4);
const double eps = (1e-7);
int main() {
  int n, a[maxn], T, cnt = 1;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> T;
  sort(a, a + n);
  int uk = 0;
  for (int i = 1; i < n; i++) {
    int u = i - 1, sz = 1;
    while (u >= 0 && a[i] - a[u] <= T) sz++, u--;
    cnt = max(cnt, sz);
  }
  cout << cnt;
}
