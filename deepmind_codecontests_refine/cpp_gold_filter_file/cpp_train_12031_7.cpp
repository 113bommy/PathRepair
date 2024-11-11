#include <bits/stdc++.h>
using namespace std;
long long ans;
int n, m, a[100005], b[100005], c[100005], d[100005], A[100005], e[100005];
bool cmp(int x, int y) { return x > y; }
int main() {
  int i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    if (a[i] + b[i] <= c[i] + d[i]) {
      if (a[i] <= d[i] && b[i] <= c[i]) continue;
      if (a[i] > d[i]) {
        ans += 2 * (a[i] - d[i]);
        A[++m] = 0;
      } else {
        ans += 2 * (c[i] - b[i]);
        A[++m] = 0;
      }
      continue;
    }
    A[++m] = a[i] + b[i], ans += a[i] - b[i];
    A[++m] = c[i] + d[i], ans += c[i] - d[i];
  }
  sort(A + 1, A + m + 1, cmp);
  for (i = 1; i <= m; i++)
    if (i & 1)
      ans += A[i];
    else
      ans -= A[i];
  cout << ans / 2;
  return 0;
}
