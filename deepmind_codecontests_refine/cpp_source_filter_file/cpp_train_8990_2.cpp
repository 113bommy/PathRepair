#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
int t[maxn], p[maxn], perm[maxn];
bool cmp(int x, int y) {
  long long u = 1ll * t[x] * p[x] * (100LL - p[y]);
  long long v = 1ll * t[y] * p[y] * (100LL - p[x]);
  return u > v;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> t[i] >> p[i];
  for (int i = 0; i < n; i++) perm[i] = i;
  sort(perm, perm + n, cmp);
  long long prv = 0;
  double res = 0;
  for (int i = 0; i < n; i++) {
    int id = perm[i];
    res += t[id] + (prv * (100LL - p[id])) / (int)1e4;
    prv += p[id] * t[id];
  }
  cout << fixed << setprecision(12) << res;
  return 0;
}
