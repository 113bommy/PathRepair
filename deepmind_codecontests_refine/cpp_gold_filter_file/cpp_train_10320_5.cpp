#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
long long n, vis[maxn], ans[maxn];
long long v[maxn][2];
int main() {
  long long p = 1, a, b;
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld%lld", &a, &b);
    v[i][0] = a;
    v[i][1] = b;
    vis[i] = 0;
  }
  ans[p] = 1;
  vis[1] = 1;
  while (1) {
    ans[p + 1] = v[ans[p]][0];
    ans[p + 2] = v[ans[p]][1];
    if (vis[ans[p + 1]] && vis[ans[p + 2]]) break;
    if (vis[ans[p + 1]] || vis[ans[p + 2]]) {
      if (vis[ans[p + 1]]) {
        ans[p + 1] = ans[p + 2];
      }
      break;
    }
    vis[ans[p + 1]] = 1;
    vis[ans[p + 2]] = 1;
    if (ans[p + 2] == v[ans[p + 1]][0] || ans[p + 2] == v[ans[p + 1]][1]) {
      p += 2;
    } else {
      swap(ans[p + 1], ans[p + 2]);
      p += 2;
    }
  }
  for (long long i = 1; i <= n; i++) {
    printf("%lld ", ans[i]);
  }
  return 0;
}
