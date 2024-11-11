#include <bits/stdc++.h>
using namespace std;
const int maxn = 200100;
int a[maxn];
long long w[maxn];
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    w[i] += a[i];
    w[i + 1] += w[i] / 2;
    w[i] %= 2;
  }
  w[n] += a[n];
  int pos = -1;
  for (int i = 0; i <= n; i++) {
    pos = i;
    if (w[i]) break;
  }
  long long c = 0;
  int res = 0;
  for (int i = n; i >= 0; i--) {
    c = c * 2 + w[i];
    if (abs(c) > k * 2) break;
    if (i <= pos) {
      if (abs(w[i] - c) <= k) {
        if (i == n && w[i] - c == 0) continue;
        res++;
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
