#include <bits/stdc++.h>
using namespace std;
const long long inf = 100005 * 1000000000LL;
int tree[100005], n, cnt, data[100005];
long long sum[100005], x[100005], k;
void insert(int x, int k) {
  for (int i = x; i <= n; i += i & (-i)) tree[i] += k;
}
int ask(int x) {
  if (x == 0) return 0;
  int ret = 0;
  for (int i = x; i >= 1; i -= i & (-i)) ret += tree[i];
  return ret;
}
int find(long long key) {
  int g = 0, h = cnt - 1, ans = cnt;
  while (g <= h) {
    int mid = (g + h) / 2;
    if (x[mid] >= key) {
      ans = mid;
      h = mid - 1;
    } else
      g = mid + 1;
  }
  return ans + 1;
}
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &data[i]);
  sum[0] = data[0];
  for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + data[i];
  for (int i = 0; i < n; i++) x[i] = sum[i];
  sort(x, x + n);
  cnt = 1;
  for (int i = 1; i < n; i++)
    if (x[i] != x[cnt - 1]) x[cnt++] = x[i];
  long long g = -inf, h = inf, ans = -inf;
  int tt = 0;
  while (g <= h) {
    long long mid = (g + h) / 2;
    for (int i = 0; i < n; i++) insert(find(sum[i]), 1);
    long long tol = 0, last = 0;
    for (int i = 0; i < n; i++) {
      int k = find(mid + last + 1);
      tol += n - i - ask(k - 1);
      last = sum[i];
      insert(find(sum[i]), -1);
    }
    if (tol < k) {
      ans = mid;
      h = mid - 1;
    } else
      g = mid + 1;
  }
  printf("%lld\n", ans);
}
