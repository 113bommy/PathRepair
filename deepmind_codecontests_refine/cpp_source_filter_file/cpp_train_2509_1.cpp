#include <bits/stdc++.h>
using namespace std;
const int maxn = 222222, P = 13331;
int n, m, a[maxn], p[maxn], q[maxn];
unsigned long long pha[maxn], qha[maxn], pw[maxn];
unsigned long long ph(int l, int r) {
  return pha[r] - pha[l - 1] * pw[r - l + 1];
}
unsigned long long qh(int l, int r) {
  return qha[r] - qha[l - 1] * pw[r - l + 1];
}
bool equiv(int l, int r) { return ph(l, r) == qh(n - r + 1, n - l + 1); }
int main() {
  set<int> have;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), have.insert(a[i]);
  a[++n] = m;
  sort(a, a + n + 1);
  for (int i = 0; i < n; ++i) q[i + 1] = p[i + 1] = a[i + 1] - a[i];
  reverse(q + 1, q + n + 1);
  pw[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pw[i] = pw[i - 1] * P;
    pha[i] = pha[i - 1] * P + p[i] + 2;
    qha[i] = qha[i - 1] * P + q[i] + 2;
  }
  set<int> ok1, ans;
  for (int i = 2; i <= n; ++i)
    if (p[i] > p[1]) {
      if (equiv(2, i - 1)) {
        int res = a[i - 1] + p[1];
        if (have.count(res)) continue;
        if (res > a[n - 1])
          ans.insert(res);
        else
          ok1.insert(res);
      }
    }
  for (int i = n - 1; i >= 1; --i)
    if (p[i] > p[n] || (p[i] == p[n] && a[i] == p[n])) {
      if (equiv(i + 1, n - 1)) {
        int res = a[i] - p[n];
        if (have.count(res)) continue;
        if (ok1.count(res) || res < a[1]) ans.insert(res);
      }
    }
  if (have.count(0))
    for (int i = 1; i < n; ++i)
      if (equiv(1, i) && equiv(i + 1, n)) ans.insert(a[i]);
  int sz = ans.size();
  printf("%d\n", sz);
  for (auto g : ans) printf("%d ", g);
  return 0;
}
