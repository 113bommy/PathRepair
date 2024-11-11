#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const double EPS = 1e-9;
const long long INF = 100000000000000 + 5;
const int MAXN2 = 2e5 + 5;
long long a[MAXN];
int n;
bool check(long long m, long long k) {
  long long s = 0;
  for (int i = 0; i < n; i++) {
    s += min(a[i], m);
  }
  if (s < k)
    return true;
  else
    return false;
}
int main() {
  long long k, cnt;
  long long s = 0;
  scanf("%d%I64d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &a[i]);
    s += a[i];
  }
  if (s < k) {
    printf("-1");
    return 0;
  }
  if (s == k) {
    printf("\n");
    return 0;
  }
  long long i, l = 0, r = s;
  while (l + 1 < r) {
    i = (l + r) >> 1ll;
    int ans = check(i, k);
    if (ans)
      l = i;
    else
      r = i;
  }
  long long x = 0;
  if (check(l, k)) x = l;
  if (check(r, k)) x = r;
  vector<int> res;
  s = 0;
  for (int i = 0; i < n; i++) {
    s += min(a[i], x);
    a[i] -= x;
    if (a[i] > 0) res.push_back(i);
  }
  int sz = res.size();
  int d = 0;
  for (int i = 0; i < sz && s < k; i++) {
    int v = res[i];
    a[v]--;
    s++;
    if (s == k) d = i;
  }
  for (int i = d + 1; i < sz; i++) {
    printf("%d ", res[i] + 1);
  }
  for (int i = 0; i <= d; i++) {
    if (a[res[i]]) printf("%d ", res[i] + 1);
  }
  return 0;
}
