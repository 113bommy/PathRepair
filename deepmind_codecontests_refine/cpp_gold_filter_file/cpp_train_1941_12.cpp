#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const long long mod = 1e9 + 7;
const long long INF = 1e18;
const double eps = 1e-6;
int a[maxn];
int main() {
  int n, q;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j]) ans++;
    }
  }
  int now = ans & 1;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int tmp = (r - l + 1);
    tmp = (tmp - 1) * tmp / 2;
    tmp &= 1;
    now ^= tmp;
    if (now)
      puts("odd");
    else
      puts("even");
  }
}
