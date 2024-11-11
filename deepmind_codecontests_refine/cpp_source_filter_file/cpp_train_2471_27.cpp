#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 1000000007;
const int maxn = 1000010;
int a[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  if (n % 2 == 1)
    printf("%d\n", a[n / 2]);
  else
    printf("%d\n", a[n / 2 + 1]);
  return 0;
}
