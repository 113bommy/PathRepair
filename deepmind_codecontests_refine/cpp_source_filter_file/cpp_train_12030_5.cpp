#include <bits/stdc++.h>
const int MAXN = 300010;
std::vector<int> q;
int cnt[MAXN], ans = 0;
int lim[MAXN];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int pos = 0;
  for (int i = 1; i <= m; i++) {
    int opt, x;
    scanf("%d%d", &opt, &x);
    switch (opt) {
      case 1: {
        q.push_back(x);
        cnt[x]++;
        ans++;
        break;
      }
      case 2: {
        ans -= cnt[x];
        cnt[x] = 0;
        lim[x] = i;
        break;
      }
      case 3: {
        while (pos <= x) {
          if (pos > lim[q[pos]]) {
            cnt[q[pos]]--;
            ans--;
          }
          pos++;
        }
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
