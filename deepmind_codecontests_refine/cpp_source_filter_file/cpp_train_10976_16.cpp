#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double INF = 1e20;
const double PI = acos(-1.);
const int MXN = 50;
const long long MOD = 1000000007;
int main() {
  int i, j;
  int n, k;
  scanf("%d%d", &k, &n);
  int cnt = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d", &j);
    if (j + k <= 5) cnt++;
  }
  printf("%d\n", cnt / 3);
  return 0;
}
