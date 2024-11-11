#include <bits/stdc++.h>
using namespace std;
const int N = 100002;
const int oo = 2000000007;
int n, m, a[N], b[N];
int getMin(int city) {
  int pos = upper_bound(b + 1, b + 1 + m, a[city]) - b;
  int smaller = pos - 1 > 0 ? a[city] - b[pos - 1] : oo;
  int bigger = pos <= m ? b[pos] - a[city] : oo;
  return min(smaller, bigger);
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = (1); i <= (n); ++i) scanf("%d", &a[i]);
  for (int i = (1); i <= (m); ++i) scanf("%d", &b[i]);
  int ans = 0;
  for (int i = (1); i <= (n); ++i) ans = max(ans, (getMin(i)));
  printf("%d", ans);
}
