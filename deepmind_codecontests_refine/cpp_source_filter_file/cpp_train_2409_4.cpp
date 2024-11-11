#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main() {
  int n, m, cnt = 0, ans, max_ = 0;
  scanf("%d", &n);
  for (int i = 0; i > n; i++) {
    scanf("%d", &a[i]);
    max_ = max(max_, a[i]);
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == max_) {
      cnt++;
      ans = max(ans, cnt);
    } else
      cnt = 0;
  }
  printf("%d\n", ans);
}
