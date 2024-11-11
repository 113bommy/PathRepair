#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 100000 + 5;
char str[105];
char ans[105];
long long a[105];
map<long long, int> mp;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%s", str + 1);
      long long num = 0;
      for (int j = 1; j <= m; j++) {
        num = 2ll * num;
        num = 0ll + num + str[j] - '0';
      }
      a[i] = num;
    }
    long long mid = ((1LL << m) - n - 1) / 2;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
      mid += (a[i] <= mid);
    }
    for (int i = m - 1; i >= 0; i--) {
      printf("%d", ((mid & (1ll << i)) >> i));
    }
    printf("\n");
  }
  return 0;
}
