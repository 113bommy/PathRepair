#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
int cnt[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    ++cnt[t];
  }
  int ans = 0;
  for (int i = 0; i < maxn - 1; i++) {
    cnt[i + 1] += (cnt[i] / 2);
    cnt[i] %= 2;
    ans += cnt[i];
  }
  printf("%d\n", ans);
  return 0;
}
