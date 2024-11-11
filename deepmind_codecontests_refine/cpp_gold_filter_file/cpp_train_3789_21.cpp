#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 19;
vector<int> v, sub;
int main() {
  int n, m, t, x, sum = 0;
  scanf("%d%d", &n, &m);
  v.resize(n + 1), sub.resize(n + 1);
  for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
  while (m--) {
    scanf("%d%d", &t, &x);
    if (t == 1) {
      int xi;
      scanf("%d", &xi);
      v[x] = xi;
      sub[x] = sum;
    } else if (t == 2)
      sum += x;
    else
      printf("%d\n", v[x] + sum - sub[x]);
  }
  return 0;
}
