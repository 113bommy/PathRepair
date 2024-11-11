#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, op, i, j;
  scanf("%d %d", &n, &op);
  int l[5005], r[5005], m[5005], t[5005];
  for (i = 1; i <= op; i++) scanf("%d %d %d %d", &t[i], &l[i], &r[i], &m[i]);
  vector<long long> ans(n + 5, 100000000);
  for (i = op; i >= 1; i--) {
    if (t[i] == 1) {
      for (j = l[i]; j <= r[i]; j++) ans[j] -= m[i];
    } else {
      for (j = l[i]; j <= r[i]; j++)
        if (ans[j] > m[i]) ans[j] = m[i];
    }
  }
  vector<long long> tmp = ans;
  for (i = 1; i <= op; i++) {
    if (t[i] == 1) {
      for (j = l[i]; j <= r[i]; j++) tmp[j] += m[i];
    } else {
      long long mx = -1000000000;
      for (j = l[i]; j <= r[i]; j++) mx = max(mx, tmp[j]);
      if (mx != m[i]) {
        printf("NO");
        return 0;
      }
    }
  }
  cout << "YES\n";
  cout << ans[1] << " ";
  for (i = 2; i <= n; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
