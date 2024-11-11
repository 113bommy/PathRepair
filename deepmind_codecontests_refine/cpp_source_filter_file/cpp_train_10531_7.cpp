#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 3e6 + 3;
bool appear[MAXN];
int ans[MAXN];
signed main() {
  int cnt = 1;
  int n, x;
  scanf("%d%d", &n, &x);
  int now = 0;
  appear[0] = true;
  appear[x] = true;
  for (int i = 1; i < (1 << n); ++i) {
    if (appear[i]) continue;
    appear[i ^ x] = true;
    ans[cnt++] = i ^ x;
  }
  printf("%d\n", cnt - 1);
  for (int i = 1; i < cnt; ++i) printf("%d ", ans[i] ^ ans[i - 1]);
}
