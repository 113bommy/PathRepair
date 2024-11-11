#include <bits/stdc++.h>
using namespace std;
map<int, int> hs;
map<int, int>::iterator it;
const int N = 3 * 1e5 + 10;
const long long INF = 5e9;
int a[N], res[N];
long long sum[N];
int main() {
  int n, l, r;
  sum[0] = 0;
  long long ans = -INF;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum[i] = sum[i - 1] + (long long)(a[i] > 0 ? a[i] : 0);
    it = hs.find(a[i]);
    if (it != hs.end()) {
      int pos = it->second;
      long long tmp = sum[i] - sum[pos - 1];
      if (a[i] < 0) tmp += (long long)(a[i] << 1);
      if (tmp > ans) {
        ans = tmp;
        l = pos;
        r = i;
      }
    } else
      hs[a[i]] = i;
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (i < l || i > r || (i != l && i != r && a[i] < 0)) res[cnt++] = i;
  }
  printf("%I64d %d\n", ans, cnt);
  for (int i = 0; i < cnt; ++i) printf("%d ", res[i]);
  return 0;
}
