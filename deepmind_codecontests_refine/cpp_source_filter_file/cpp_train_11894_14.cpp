#include <bits/stdc++.h>
const int maxn = 3e5 + 10;
const int mod = 998244353;
using namespace std;
int n, k;
int a[maxn], sum[maxn], vis[maxn];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    if (n == 2 || n == 3) {
      printf("-1");
      continue;
    }
    for (int i = n & 1 ? 1 : 2; i <= n; i += 2) printf("%d ", i);
    printf("%d %d ", n - 3, n - 1);
    for (int i = n - 5; i >= 1; i -= 2) printf("%d ", i);
    puts("");
  }
  return 0;
}
