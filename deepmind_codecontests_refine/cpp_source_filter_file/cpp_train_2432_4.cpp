#include <bits/stdc++.h>
using namespace std;
int num[100010];
long long res[100010];
long long sum[100010];
int cmp(const void* a, const void* b) {
  return *(long long*)b - *(long long*)a;
}
int main() {
  long long n, q;
  int i, j;
  long long ans, k;
  while (cin >> n) {
    memset(res, 0, sizeof(res));
    memset(sum, 0, sizeof(sum));
    for (i = 0; i < n; i++) {
      cin >> num[i];
    }
    qsort(num, n, sizeof(num[0]), cmp);
    sum[0] = num[0];
    for (i = 0; i < n; i++) {
      sum[i + 1] = sum[i] + num[i];
    }
    cin >> q;
    for (j = 1; j <= q; j++) {
      cin >> k;
      if (res[k] != 0) {
        cout << ans << " ";
        continue;
      }
      long long l, r;
      long long step = k;
      l = r = 1;
      ans = 0;
      for (i = 1; l < n; i++) {
        r += step;
        step *= k;
        if (r > n) {
          r = n;
        }
        long long cur = sum[r] - sum[l];
        ans += cur * i;
        l = r;
      }
      res[k] = ans;
      cout << ans << " ";
    }
    cout << endl;
  }
  return 0;
}
