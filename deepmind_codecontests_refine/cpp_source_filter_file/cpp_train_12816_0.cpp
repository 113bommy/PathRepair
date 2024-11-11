#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 11;
const int MAXN = 5e7 + 1;
const int BITMAX = 18;
const int INF = 2e9 + 88;
const long long LLINF = 1e17 + 3;
const int MOD = 1e9 + 7;
const long double Pi = acos(-1);
int a[MAX];
int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  if (n == 1) return puts("0"), 0;
  sort(a, a + n);
  long long res = 0;
  int mx = 0;
  for (int i = 1; i < n; ++i) {
    res += a[i] - 1;
    if (a[i] > mx) mx++;
  }
  if (a[n] > mx)
    res += mx;
  else
    res += a[n] - 1;
  printf("%lld\n", res);
  return 0;
}
