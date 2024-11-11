#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
int n, m, u[MAXN], v[MAXN];
int solve() {
  if (m == 0) return n - 1;
  set<int> div1, div2;
  for (int i = 0; i < m; i++) {
    int a = min(u[i], v[i]);
    int b = max(u[i], v[i]);
    if (div1.count(a)) return 0;
    div2.insert(a);
    if (div2.count(b)) return 0;
    div1.insert(b);
  }
  int middle = *div1.begin() - *div2.rbegin() - 1;
  return max(0, middle + 1);
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u[i], &v[i]);
  }
  printf("%d\n", solve());
  return 0;
}
