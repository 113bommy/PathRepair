#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  static int a[100005], b[2005];
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) cin >> b[i];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  a[0] = a[1] - 1000, a[n + 1] = a[n] + 1000;
  static int l[100005], r[100005], f[100005];
  for (int i = 1; i <= n; ++i) l[i] = a[i] == a[i - 1] ? l[i - 1] : i;
  for (int i = n; i >= 1; --i) r[i] = a[i] == a[i + 1] ? r[i + 1] : i;
  for (int i = 1, cur = 0; i <= n; ++i) {
    while (cur < m && b[cur + 1] <= a[i]) ++cur;
    int Max = l[i] == i ? f[i - 1] + (a[i] == b[cur]) : -100000000;
    f[i] = max(f[i], Max);
    for (int j = cur; j >= 1; --j) {
      int k = i - (a[i] - b[j]);
      if (k <= 0)
        break;
      else
        k = l[k];
      f[i] = max(f[i], f[k - 1] + cur - j + 1);
      Max = max(Max, f[k - 1] + cur - j + 1);
    }
    for (int j = cur + (b[cur] < a[i]); j <= m; ++j) {
      int k = i + (b[j] - a[i]);
      if (k > n)
        break;
      else
        k = r[k];
      f[k] = max(f[k], Max + j - cur);
    }
    f[i + 1] = max(f[i + 1], f[i]);
  }
  cout << f[n] << endl;
}
