#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int main() {
  int n, m, len;
  int a[100010], b[100010], sum[100010];
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(sum, 0, sizeof(sum));
    ;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    len = 0;
    b[len] = a[0];
    for (int i = 1; i < n; i++) {
      if (a[i] != b[len]) {
        len++;
        b[len] = a[i];
      }
    }
    len++;
    for (int i = 0; i < len; i++) {
      if (i == 0 || i == len - 1) {
        sum[b[i]]++;
      } else {
        if (b[i - 1] == b[i + 1]) {
          sum[b[i]] += 2;
        } else {
          sum[b[i]] += 1;
        }
      }
    }
    int maxx = -1, ans = 0;
    for (int i = 1; i <= m; i++) {
      if (sum[i] > maxx) {
        maxx = sum[i];
        ans = i;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
