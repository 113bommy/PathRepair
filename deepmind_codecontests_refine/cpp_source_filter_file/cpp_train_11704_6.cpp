#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;
int n, k, a[N], b[N], p[N], t[N];
set<int> s;
void upd(int i, int x) {
  for (; i <= n; i += i & -i) t[i] += x;
}
int get(int i) {
  int s = 0;
  for (; i; i -= i & -i) s += t[i];
  return s;
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), p[a[i]] = i;
  for (int i = 1; i <= k; i++) scanf("%d", &b[i]);
  sort(b + 1, b + k + 1);
  s.insert(0);
  s.insert(n + 1);
  long long sol = 0;
  for (int i = 1; i <= n; i++) upd(i, 1);
  for (int i = 1, j = 1; i <= n; i++)
    if (j <= k && b[j] == i) {
      s.insert(p[i]);
      j++;
    } else {
      int x, y;
      auto it = s.lower_bound(i);
      y = *it;
      x = *--it;
      sol += get(y - 1) - get(x);
      upd(i, -1);
    }
  printf("%lld", sol);
  return 0;
}
