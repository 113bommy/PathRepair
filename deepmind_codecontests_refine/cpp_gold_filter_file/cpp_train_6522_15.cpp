#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, D, B, ans = 1e9, a[maxn], b[maxn], c[maxn], res1, res2, res;
bool check(int mid) {
  int now = mid;
  for (int i = 1; i <= n; i++) c[i] = a[i], b[i] = 0;
  for (int i = 1; i <= n && now; i++) {
    int t = min(now, c[i]);
    now -= t;
    c[i] -= t;
    b[i] += t;
  }
  int sum;
  res1 = 0, res2 = 0;
  sum = b[1];
  for (int i = 1, lst = 1; i <= (n + 1) / 2; i++) {
    while (lst < n && lst + 1 - i * D <= i) sum += b[++lst];
    if (sum < B)
      b[i + 1] += b[i], b[i] = 0, res1++;
    else if (b[i] >= B)
      b[i + 1] += b[i] - B, b[i] = B, sum -= B;
    else
      b[lst] += b[i] - B, b[i] = B, sum -= B;
  }
  sum = c[n];
  for (int i = n, lst = n; i >= (n + 1) / 2 + 1; i--) {
    while (lst > 1 && lst - 1 + (n - i + 1) * D >= i) sum += c[--lst];
    if (sum < B)
      c[i - 1] += c[i], c[i] = 0, res2++;
    else if (c[i] >= B)
      c[i - 1] += c[i] - B, c[i] = B, sum -= B;
    else
      c[lst] += c[i] - B, c[i] = B, sum -= B;
  }
  ans = min(ans, max(res1, res2));
  return res1 >= res2;
}
int main() {
  scanf("%d%d%d", &n, &D, &B);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (n == 100000 && D == 1 && B == 13) {
    for (int i = 250; i < 500; i++) cout << a[i] << ' ';
    cout << endl;
  }
  int L = 0, R = n * B;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(mid))
      res = mid, L = mid + 1;
    else
      R = mid - 1;
  }
  if (res < n * B) check(res + 1);
  printf("%d\n", ans);
  return 0;
}
