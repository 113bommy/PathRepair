#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 6;
int cnt[maxn];
int main() {
  memset(cnt, 0, sizeof(cnt));
  int n, w;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &w);
    cnt[w]++;
  }
  int ans = 0;
  for (int i = 0; i + 1 < maxn; i++) {
    ans += cnt[i] & 1;
    cnt[i + 1] += cnt[i] >> 1;
  }
  printf("%d", ans);
  return 0;
}
