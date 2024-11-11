#include <bits/stdc++.h>
using namespace std;
long long vis[10000];
int main() {
  int n;
  long long i, j = 0, k;
  for (i = 0; i < 1000000; i++) {
    k = i;
    int ans = 0;
    while (k) {
      ans += k % 10;
      k /= 10;
    }
    if (ans == 10) {
      vis[j++] = i;
    }
  }
  scanf("%d", &n);
  printf("%d\n", vis[n - 1]);
  return 0;
}
