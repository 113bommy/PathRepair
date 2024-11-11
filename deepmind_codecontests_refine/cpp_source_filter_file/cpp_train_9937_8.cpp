#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long a[maxn], b[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  int t;
  long long sum_n = 0, sum_m = 0;
  long long cnt_n = 0, cnt_m = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sum_n = accumulate(a, a + n, 0LL);
  sum_m = accumulate(b, b + m, 0LL);
  sort(a, a + n);
  sort(b, b + m);
  for (int i = 0; i < n; i++) {
    if (a[i] < sum_m && i < n - 1) {
      cnt_n += a[i];
    } else {
      cnt_n += sum_m;
    }
  }
  for (int i = 0; i < m; i++) {
    if (a[i] < sum_n && i < m - 1) {
      cnt_m += b[i];
    } else {
      cnt_m += sum_n;
    }
  }
  printf("%lld\n", min(cnt_n, cnt_m));
  return 0;
}
