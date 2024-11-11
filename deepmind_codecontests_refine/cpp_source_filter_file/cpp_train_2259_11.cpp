#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m;
int a[maxn];
int ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 2 * n; i++) scanf("%d", &a[i]);
  ans = 0;
  for (int i = 2; i <= 2 * n; i += 2) {
    int j;
    for (j = i; j <= 2 * n; j++) {
      if (a[j] = a[i - 1]) break;
    }
    for (; j > i; j--) {
      swap(a[j], a[j - 1]);
      ans++;
    }
  }
  printf("%d\n", ans);
  ;
  return 0;
}
