#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int n;
int m;
int x[2000];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  int ans = m;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      ans = max(ans, m % x[i] + (m / x[i]) * x[j]);
  printf("%d\n", ans);
  return 0;
}
