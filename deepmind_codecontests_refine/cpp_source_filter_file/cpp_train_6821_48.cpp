#include <bits/stdc++.h>
inline int Rand() { return (rand() << 16) | rand(); }
using namespace std;
const int N = 200005;
const double eps = 1e-9;
struct Pair {
  int l, r;
} was[N], was1[N];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a, s, type;
  for (int i = 1; i <= k; ++i) {
    cin >> type >> s >> a;
    if (type == 1)
      was[s].l = a, was[s].r = i;
    else
      was1[s].l = a, was1[s].r = i;
  }
  for (int i = 1; i <= n; cout << endl, ++i)
    for (int j = 1; j <= m; ++j)
      if (was[i].r > was1[j].l)
        cout << was[i].l << " ";
      else
        cout << was1[j].l << " ";
  return 0;
}
