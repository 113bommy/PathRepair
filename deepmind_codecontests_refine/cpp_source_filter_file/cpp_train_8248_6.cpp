#include <bits/stdc++.h>
using namespace std;
int T;
long long a, b;
bool vis[1025], tmp[1025];
int num[1025];
void solve() {
  int n, cnt;
  scanf("%d", &T);
  while (T--) {
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &num[i]);
      vis[num[i]] = 1;
    }
    int i;
    for (i = 0; i < 1025; ++i) {
      cnt = 0;
      memcpy(tmp, vis, sizeof(vis));
      for (int j = 0; j < n; ++j)
        if (tmp[num[j] ^ i]) {
          tmp[num[j] ^ i] = 0;
          ++cnt;
        } else
          break;
      if (cnt == n) break;
    }
    printf("%d\n", i == 1025 ? -1 : i);
  }
}
int main(void) { solve(); }
