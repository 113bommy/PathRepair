#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e8;
const int MAXN = 2e5 + 5;
const long long INFLL = 1e18;
int n, k;
int a[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), k = max(k, a[i]);
  while (1) {
    int acum = 0;
    for (int j = 0; j < n; j++) acum += k - a[j];
    if (acum > n * k / 2) break;
    k++;
  }
  printf("%d\n", k);
  return 0;
}
