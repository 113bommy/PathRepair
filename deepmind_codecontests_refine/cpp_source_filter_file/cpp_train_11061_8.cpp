#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 5;
int a[maxn], b[maxn];
int t;
int cnt[maxn];
int pos[maxn];
int main() {
  while (~scanf("%d", &t)) {
    memset(cnt, 1, sizeof(cnt));
    int mx = 0;
    for (int i = 1; i <= t; i++) {
      scanf("%d", &a[i]);
      pos[a[i]] = i;
    }
    for (int i = 1; i <= t; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= t; i++) {
      int cur = (pos[b[i]] - i + t) % t;
      cnt[cur]++;
    }
    for (int i = 1; i <= t; i++) mx = max(mx, cnt[i]);
    printf("%d\n", mx);
  }
  return 0;
}
