#include <bits/stdc++.h>
const int N = 1e5 + 3;
const int inf = 1e9;
using namespace std;
int a[N];
double ans;
void rec(int *a, int n, int k, double c) {
  if (!k) {
    int cnt = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j) cnt += a[i] < a[j];
    ans += cnt * c;
    return;
  }
  for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j) {
      reverse(a + i, a + j + 1);
      rec(a, n, k - 1, c / (n * (n - 1)));
      reverse(a + i, a + j + 1);
    }
}
bool solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  if (n > 1) rec(a, n, k, 1.0);
  printf("%.12lf", ans);
  return false;
}
int main() {
  while (solve())
    ;
  return 0;
}
