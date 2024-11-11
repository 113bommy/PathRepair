#include <bits/stdc++.h>
using namespace std;
long long n, k, x, a[200005], i, l, j, answ;
long long t[800005];
void build(int v, int s, int e) {
  if (s == e) {
    t[v] = a[s];
    return;
  }
  int m = (s + e) / 2;
  build(2 * v, s, m);
  build(2 * v + 1, m + 1, e);
  t[v] = (t[2 * v] | t[2 * v + 1]);
}
void update(int v, int s, int e, int pos, long long val) {
  if (s == e) {
    t[v] = val;
    return;
  }
  int m = (s + e) / 2;
  if (pos <= m)
    update(2 * v, s, m, pos, val);
  else
    update(2 * v + 1, m + 1, e, pos, val);
  t[v] = (t[2 * v] | t[2 * v + 1]);
}
int main() {
  scanf("%lld%lld%lld", &n, &k, &x);
  for (i = 1; i <= n; i++) scanf("%lld", &a[i]);
  build(1, 1, n);
  for (i = 1; i <= n; i++) {
    l = a[i];
    for (j = 1; j <= k; j++) l *= x;
    update(1, 1, n, i, l);
    answ = max(answ, t[1]);
    update(1, 1, n, i, a[i]);
  }
  cout << answ << endl;
  return 0;
}
