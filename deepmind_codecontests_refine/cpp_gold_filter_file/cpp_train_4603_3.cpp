#include <bits/stdc++.h>
using namespace std;
const int next_x[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int next_y[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int inf = 2147483647;
const long long linf = 1e18 + 5;
const double PI = acos(-1.0);
const long double eps = 1e-12;
const int MAXN = 2e5 + 10;
const int N = 1e6;
const int fix = 1e5;
long long M = 1e9 + 7;
int n, q;
long long a[MAXN], ans, add[MAXN];
map<pair<int, int>, int> m;
int work() {
  scanf("%d", &n);
  for (register int i = (1), I = (n) + 1; i < I; ++i)
    scanf("%lld", &a[i]), ans += a[i];
  scanf("%d", &q);
  while (q--) {
    int s, t, u;
    scanf("%d%d%d", &s, &t, &u);
    if (m[{s, t}]) {
      int k = m[{s, t}];
      if (add[k] <= a[k]) ans++;
      add[k]--;
      m[{s, t}] = 0;
    }
    m[{s, t}] = u;
    if (u) {
      int k = m[{s, t}];
      if (add[k] < a[k]) ans--;
      add[k]++;
    }
    printf("%lld\n", max(1LL, ans));
  }
  return 0;
}
int main() {
  work();
  return 0;
}
