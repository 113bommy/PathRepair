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
int n;
ll k;
vector<int> vec;
vector<int> ax;
int main() {
  scanf("%d %lld", &n, &k);
  if ((n * 1ll * (n + 1)) / 2 > k) {
    printf("-1\n");
    exit(0);
  }
  k -= (n * 1ll * (n + 1)) / 2;
  for (int i = 1; i <= n; i++) vec.push_back(i);
  for (int i = n - 1; i > 0; i -= 2) ax.push_back(i);
  int p = 0;
  while (k and p < ((int)(ax).size())) {
    if (ax[p] <= k) {
      k -= ax[p];
      swap(vec[p], vec[n - p - 1]);
    } else {
      swap(vec[p], vec[n - p - 1 - ax[p] + k]);
      k = 0;
    }
    ++p;
  }
  int ans = 0;
  for (int i = 0; i < ((int)(vec).size()); i++) ans += max(i + 1, vec[i]);
  printf("%d\n", ans);
  for (int i = 0; i < ((int)(vec).size()); i++)
    printf("%d%c", vec[i], " \n"[i == ((int)(vec).size()) - 1]);
  for (int i = 1; i <= n; i++) printf("%d%c", i, " \n"[i == n]);
  return 0;
}
