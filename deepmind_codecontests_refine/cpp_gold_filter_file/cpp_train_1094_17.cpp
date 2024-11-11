#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
long long n, m, k, s, t, tot, a[N], b[5], sum[N];
double ans;
inline long long summ(int j, int k) { return sum[j] - sum[j - k]; }
void dfs(double o, int u, int x, int y, int k) {
  int l = 1, r = k, mid1, mid2;
  double k1, k2;
  if (x == 1000) {
    k1 = 1;
  }
  while (l + 5 < r) {
    mid1 = l + (r - l) / 3;
    mid2 = r - (r - l) / 3;
    k1 = (summ(x, mid1) + summ(y, mid1) + o * u) / (mid1 * 2 + u) - o;
    k2 = (summ(x, mid2) + summ(y, mid2) + o * u) / (mid2 * 2 + u) - o;
    if (k1 < k2)
      l = mid1 + 1;
    else
      r = mid2 - 1;
  }
  for (int mid1 = l; mid1 <= r; ++mid1) {
    k1 = (summ(x, mid1) + summ(y, mid1) + o * u) / (mid1 * 2 + u) - o;
    if (k1 > ans) {
      ans = k1;
      b[1] = x - mid1 + 1;
      b[2] = (u == 1 ? x + 1 : x + 2);
      b[3] = y - mid1 + 1;
      b[4] = n;
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
  for (int i = 2; i <= n - 1; ++i) {
    dfs(a[i], 1, i - 1, n, min(i - 1, (int)n - i));
  }
  for (int i = 2; i <= n - 2; ++i) {
    dfs((a[i] + a[i + 1]) / 2.0, 2, i - 1, n, min(i - 1, (int)n - i - 1));
  }
  if (ans == 0) {
    cout << 1 << "\n" << a[1];
    return 0;
  }
  cout << b[2] - b[1] + 1 + b[4] - b[3] + 1 << "\n";
  for (int i = b[1]; i <= b[2]; ++i) cout << a[i] << ' ';
  for (int i = b[3]; i <= b[4]; ++i) cout << a[i] << ' ';
}
