#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e6;
int a, b, n;
int l, t, m;
long long getSum(int l, int r) {
  long long res = a * 1LL * (r - l + 1);
  res += (r * 1LL * (r - 1) * 1LL * b) / 2;
  res -= ((l - 1) * 1LL * (l - 2) * 1LL * b) / 2;
  return res;
}
bool check(int r) {
  int len = r - l + 1;
  long long lst = a + b * 1LL * (r - 1);
  if (lst > t) return false;
  if (len <= m) {
    return true;
  } else {
    long long sum = getSum(l, r);
    return sum <= t * 1LL * m;
  }
}
void solve() {
  int lft = l - 1, rht = inf;
  while (rht - lft > 1) {
    int mid = (lft + rht) / 2;
    if (check(mid))
      lft = mid;
    else
      rht = mid;
  }
  if (lft == l - 1)
    printf("-1\n");
  else
    printf("%d\n", lft);
}
int main() {
  scanf("%d%d%d", &a, &b, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &l, &t, &m);
    solve();
  }
  return 0;
}
