#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;
const ld EPS = 1e-9;
inline int cmp(ld first, ld second = 0, ld tol = EPS) {
  return (first <= second + tol) ? (first + tol < second) ? -1 : 0 : 1;
}
const int MOD = 1;
inline int mod(ll first, int m = MOD) { return (int)(((first % m) + m) % m); }
const int N = 1e5 + 10;
int n, k;
int a[N];
int st[N], en[N];
vector<int> vec;
int main() {
  scanf("%d %d", &n, &k);
  en[0] = en[n + 1] = 1e8;
  for (int i = 1; i <= n; i++) st[i] = n + 10;
  for (int i = 1; i <= k; i++) {
    int first;
    scanf("%d", &first);
    if (st[first] == n + 10) st[first] = i;
    en[first] = i;
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (en[i - 1] < st[i]) + (en[i + 1] < st[i]) + (en[i] == 0);
  }
  printf("%lld\n", ans);
  return 0;
}
