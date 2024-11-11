#include <bits/stdc++.h>
using namespace std;
int n, k, m;
int a[101010], b[101010];
int main() {
  memset(b, 0, sizeof b);
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    int tmp = (a[i] % m);
    b[tmp]++;
    if (b[tmp] == k) {
      printf("Yes\n");
      for (int j = 1; j <= i; j++)
        if (a[j] % m == tmp) printf("%d ", a[j]);
      return 0;
    }
  }
  printf("No\n");
  return 0;
}
