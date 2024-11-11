#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 77;
int n, q;
long long a[N];
vector<long long> V, Ps;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
  if (n == 1) {
    int q;
    scanf("%d", &q);
    long long x, y;
    while (q--) {
      scanf("%lld %lld", &x, &y);
      x = y - x + 1;
      printf("%lld ", x);
    }
    return 0;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 2; i <= n; ++i) V.push_back(a[i] - a[i - 1]);
  sort(V.begin(), V.end());
  Ps.push_back(V[0]);
  for (int i = 3; i <= n; ++i) Ps.push_back(Ps.back() + V[i - 2]);
  int sz = V.size();
  scanf("%d", &q);
  while (q--) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    x = y - x + 1;
    int id = upper_bound(V.begin(), V.end(), x - 1) - V.begin() - 1;
    long long A = 0;
    if (id == -1) {
      A = n * x;
    } else {
      A = (n - id - 1) * x + Ps[id];
    }
    printf("%lld ", A);
  }
  return 0;
}
