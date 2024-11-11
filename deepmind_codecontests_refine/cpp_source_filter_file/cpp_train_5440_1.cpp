#include <bits/stdc++.h>
using namespace std;
int n, p;
const int maxn = 1e5 + 100;
int a[maxn], suff[maxn];
vector<int> ans;
int cmp(int x, int y) { return x < y; }
int judge(int x) {
  int pos = upper_bound(a + 1, a + n + 1, x) - a;
  if (pos >= p + 1) return 0;
  int MOD = (x + n) % p;
  if (suff[MOD] >= pos)
    return 0;
  else
    return 1;
}
int main() {
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    int MOD = (a[i] + n - i) % p;
    suff[MOD] = max(suff[MOD], i);
  }
  int sta = max(a[n - 1] - n + 1, a[0]), end = a[n - 1];
  for (int x = sta; x < end; ++x) {
    if (judge(x)) ans.push_back(x);
  }
  int len = ans.size();
  printf("%d\n", len);
  if (len != 0) {
    for (int i = 0; i < len - 1; ++i) printf("%d ", ans[i]);
    printf("%d\n", ans[len - 1]);
  }
  return 0;
}
