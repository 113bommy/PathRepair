#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int f[maxn], a[maxn];
void solve(int l, int r, int k) {
  if (!k) return;
  k -= 2;
  int mid = (l + r - 1) / 2;
  if (k == 0) {
    swap(a[l], a[mid + 1]);
    return;
  }
  if (f[mid - l + 1] >= k)
    solve(l, mid, k);
  else {
    solve(l, mid, f[mid - l + 1]);
    solve(mid + 1, r, k - f[mid - l + 1]);
  }
}
int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) a[i] = i;
  for (int i = 2; i <= n; i++) f[i] = f[i / 2] + f[i - i / 2] + 2;
  k--;
  if (k % 2 || f[n] < k)
    puts("-1");
  else {
    solve(1, n, k);
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
  }
  return 0;
}
