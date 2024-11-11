#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int Q, n, a[N], cnt[40];
void solve() {
  scanf("%d", &n);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    for (int j = 0; j <= 30; j++) cnt[j] += ((a[i] >> j) & 1);
  }
  for (int j = 1; j <= n; j++) {
    bool flag = 1;
    for (int i = 1; i <= 30; i++)
      if (cnt[i] % j) flag = 0;
    if (flag) cout << j << " ";
  }
  cout << "\n";
}
int main() {
  scanf("%d", &Q);
  while (Q--) solve();
  return 0;
}
